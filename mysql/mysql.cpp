#include <iostream>
#include <mysql/mysql.h>
// #include "StdMysql.h"
#include <StdMysql.h>

const char *host = "127.0.0.1";
const char *user = "root";
const char *passwd = "52671314";
const char *db = "student254";
const int port = 3306;


#if 0
int main()
{
    MYSQL mysql;
    mysql_init(&mysql);  // 初始化
    if (mysql_real_connect(&mysql, host, user, passwd, db, port, nullptr, 0) == nullptr)
    {
        std::cout << "连接失败" << std::endl;
        return -1;
    }
    std::cout << "连接成功" << std::endl;

    /* 数据库语句执行 */ 
    // std::string sql = "update student set sex = '女' where id = 1;";
    std::string sql = "select id,name from student;";
    if (mysql_real_query(&mysql, sql.c_str(), sql.size()) != 0)
    {
        std::cout << "语句执行失败 : " << mysql_error(&mysql) << std::endl;
    }
    else
    {
        std::cout << "语句执行成功" << std::endl;
    }

    /* 获取结果集 */
    MYSQL_RES *res = mysql_store_result(&mysql);
    if (res == nullptr)
    {
        std::cout << "结果为空" << std::endl;
        mysql_close(&mysql);
        return -1;
    }

    /* 读取 */
    MYSQL_FIELD* field = mysql_fetch_fields(res);               // 获取查询结果集中每个字段的详细信息
    int num = mysql_num_fields(res);                            // 获取查询结果集中的字段数量
    int field_count = mysql_field_count(&mysql);                // 获取最近一次执行的查询返回的字段数量
    std::cout << "num: " << num << std::endl;                   
    std::cout << "field_count: " << field_count << std::endl;   
    for (int i = 0; i < num; i++)
    {
        std::cout << field[i].name << " ";                      // 打印表头
    }
    std::cout << std::endl;

    while(MYSQL_ROW row = mysql_fetch_row(res))                 // 逐行打印
    {
        for (int i = 0; i < num; i++)
        {
            std::cout << row[i] << " ";
        }
        std::cout << std::endl;
    }

    /* 关闭连接 */
    mysql_close(&mysql);
    return 0;
}
#else
int main()
{
#if 0
    StdMysql mysql;
    if (!mysql.Connect(host, user, passwd, db, port))
    {
        return -1;
    }
    StrArray sqls;
    sqls.push_back("update student set sex = '女' where id = 1;");
    sqls.push_back("update student set sex = '女' where id = 2;");
    mysql.ExecuteTransaction(sqls);
    std::vector<StrArray> res = mysql.GetResult("select * from student;");
    for (auto &row : res)
    {
        for (auto &col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
#else
    StdMysqlPool::GlobalInstance()->SetMysqlParams(10, host, user, passwd, db, port);

    auto Array = StdMysqlPool::GlobalInstance()->GetMysql()->GetResult("select * from student;");

    for (auto &row : Array)
    {
        for (auto &col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
#endif 

    
    return 0;
}
#endif 