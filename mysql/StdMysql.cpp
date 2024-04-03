#include "StdMysql.h"
#include <mysql/mysql.h>
#include <iostream>
#include <queue>
#include <mutex>

struct stdMysqlData
{
    MYSQL mysql;
    bool isConnected = false;   // 是否连接
};

StdMysql::StdMysql(): data(new stdMysqlData)
{
    mysql_init(&data->mysql);
}

StdMysql::~StdMysql()
{
    if (data->isConnected) mysql_close(&data->mysql);
    delete data;
}

bool StdMysql::Connect(CStrRef host, CStrRef user, CStrRef passwd, CStrRef db, int port)
{
    if (mysql_real_connect(&data->mysql, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), port, nullptr, 0) == nullptr)
    {
        std::cout << "数据库连接失败！\n" << mysql_error(&data->mysql) << std::endl;
        return false;
    }
    data->isConnected = true;
    return true;
}

bool StdMysql::Execute(CStrRef sql)
{
    if (mysql_real_query(&data->mysql, sql.c_str(), sql.size()) != 0)
    {
        std::cout << "语句执行失败！\n" << mysql_error(&data->mysql) << std::endl;
        return false;
    }
    return true;
}

std::vector<StrArray> StdMysql::GetResult(CStrRef sql)
{
    if (Execute(sql))
    {
        MYSQL_RES *res = mysql_store_result(&data->mysql);
        if (res != nullptr)
        {
        #if 0
            int row = mysql_num_rows(res);
            int col = mysql_num_fields(res);
            std::vector<StrArray> result;
            result.reserve(row);
            for (int i = 0; i < row; ++i)
            {
                MYSQL_ROW row = mysql_fetch_row(res);
                StrArray rowResult;
                rowResult.reserve(col);
                for (int j = 0; j < col; ++j)
                {
                    rowResult.push_back(row[j]);
                }
                result.push_back(rowResult);
            }
            mysql_free_result(res);
            return result;
        #elif 1
            int count = mysql_field_count(&data->mysql);
            // std::cout << "count = " << count << std::endl;
            // std::cout << "res = " << mysql_num_rows(res) << std::endl;
            // std::cout << "fields = " << mysql_num_fields(res) << std::endl;
            std::vector<StrArray> result;
            while(MYSQL_ROW row = mysql_fetch_row(res))
            {
                StrArray rowResult;
                for (int i = 0; i < count; i++)
                {
                    rowResult.push_back(row[i]);
                }
                result.push_back(std::move(rowResult));
            }
            mysql_free_result(res);
            return result;
        #endif 
        }

    }
    return {};
}

bool StdMysql::ExecuteTransaction(const StrArray &sqls)
{
    if (mysql_autocommit(&data->mysql, false) != 0)
    {
        std::cout << "启动手动事务失败!\n" << mysql_error(&data->mysql) << std::endl;
        return false;
    }
    for (const auto &sql : sqls)
    {
        if (Execute(sql) == false)
        {
            mysql_rollback(&data->mysql);
            mysql_autocommit(&data->mysql, true);
            return false;
        }
    }
    mysql_commit(&data->mysql);
    mysql_autocommit(&data->mysql, true);
    return false;
}

bool StdMysql::IsConnected() const
{
    if (!data->isConnected) return false;
    if (mysql_ping(&data->mysql) != 0)
    {
        std::cout << "mysql连接断开" << std::endl;
        return false;
    }
    data->isConnected = true;
    return true;
}

struct StdMysqlPoolPrivate
{
    std::queue<MysqlPtr> MysqlQueue;    // 连接队列
    std::mutex poolMutex;               // 连接池锁
    int MaxCount;                       // 最大连接数量

    std::string host;
    std::string user;
    std::string passwd;
    std::string databaseName;
    unsigned int port;
    void SetParams(int MaxConn, CStrRef host, CStrRef user, CStrRef passwd, CStrRef databaseName, int port)
    {
        MaxCount = MaxConn;
        this->host = host;
        this->user = user;
        this->passwd = passwd;
        this->databaseName = databaseName;
        this->port = port;
    }
};

StdMysqlPool::StdMysqlPool():
    p(new StdMysqlPoolPrivate)
{
}

StdMysqlPool *StdMysqlPool::GlobalInstance()
{
    static StdMysqlPool p;
    return &p;
}
bool StdMysqlPool::SetMysqlParams(int MaxConn, CStrRef host, CStrRef user, CStrRef passwd, CStrRef databaseName, int port)
{
    p->SetParams(MaxConn, host, user, passwd, databaseName, port);
    for (int idx = 0; idx < MaxConn; ++idx)
    {
        MysqlPtr mysql = std::make_shared<StdMysql>();
        if (!mysql->Connect(host, user, passwd, databaseName, port))
        {
            return false;
        }
        p->MysqlQueue.push(mysql);
    }
    return true;
}
StdMysqlPool::~StdMysqlPool()
{
    while (p->MysqlQueue.size() > 0)
    {
        p->MysqlQueue.pop();
    }    
    delete p;
}

MysqlPtr StdMysqlPool::GetMysql()
{
    /* mysql的连接是TCP 当网路不稳定连接就会*/
    std::lock_guard<std::mutex> lock(p->poolMutex);
    while (!p->MysqlQueue.empty())
    {
        /* 队头指针处于断开状态 */
        if (!p->MysqlQueue.front()->IsConnected()) p->MysqlQueue.pop();
        /* 可用 */
        else 
        {
            auto ptr = p->MysqlQueue.front();
            p->MysqlQueue.pop();
            return ptr;
        }
        if (p->MysqlQueue.size() < p->MaxCount)
        {
            MysqlPtr mysql = std::make_shared<StdMysql>();
            if (mysql->Connect(p->host, p->user, p->passwd, p->databaseName, p->port))
            {
                p->MysqlQueue.push(mysql);
                return mysql;
            }
            else
            {
                std::cout << "连接失败" << std::endl;
                return nullptr;
            }
        }
        std::cout << "连接数超过最大值" << std::endl;
        return nullptr;
    }
    return nullptr;

}

void StdMysqlPool::CloseMysql(MysqlPtr mysql)
{
    /* 连接已断开 */
    if (mysql->IsConnected()) 
    {
        std::lock_guard<std::mutex> lock(p->poolMutex);
        p->MysqlQueue.push(mysql);
    }  
}
