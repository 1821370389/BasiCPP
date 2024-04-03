#ifndef __STDMYSQL_H__
#define __STDMYSQL_H__

#include <string>
#include <vector>
#include <memory>

struct stdMysqlData;

using CStrRef = const std::string &;
using StrArray = std::vector<std::string>;

class StdMysql
{
public:
    StdMysql();
    ~StdMysql();
    bool Connect(CStrRef host, CStrRef user, CStrRef passwd, CStrRef db, int port = 3306);
    bool Execute(CStrRef sql);
    std::vector<StrArray> GetResult(CStrRef sql);
    bool ExecuteTransaction(const StrArray &sqls);
    bool IsConnected() const;    

private:
    stdMysqlData *data;
};

#define MYSQLPOOL  StdMysqlPool::GlobalInstance();
using MysqlPtr = std::shared_ptr<StdMysql>;
struct StdMysqlPoolPrivate;

class StdMysqlPool
{
public:
    static StdMysqlPool *GlobalInstance();
    bool SetMysqlParams(int MaxConn, CStrRef host, CStrRef user, CStrRef passwd, CStrRef databaseName, int port = 3306);
    ~StdMysqlPool();
    MysqlPtr GetMysql();
    void CloseMysql(MysqlPtr mysql);
private:
    StdMysqlPool();
    StdMysqlPoolPrivate *p;
};

#endif // __STDMYSQL_H__
