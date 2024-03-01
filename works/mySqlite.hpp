#ifndef __MY_SQLITE_HPP__
#define __MY_SQLITE_HPP__

#include <sqlite3.h>
class MySqlite
{
public:
    MySqlite(const std::string& db_name);
    ~MySqlite();

    /* 建表 */
    bool create_table(const std::string& tablename, const std::vector<std::string> ages);

    /* 插入数据 */
    bool insert_data(const std::string& tablename, const std::vector<std::string> headers, const std::vector<std::string> values);
    /* 插入数据(无表头) */
    bool insert_data(const std::string& tablename, const std::vector<std::string> values);

    /* 查询数据 */
    std::vector<std::vector<std::string>> query_data(const std::string& tablename, const std::string& condition = "", const std::string& headers = "*");

    /* 修改数据 */
    bool update_data(const std::string& tablename, const std::string& colName, const std::string& oldValue,const std::string& newValue);
    
    /* 删除数据*/
    bool delete_data(const std::string& tablename, const std::string& condition);
    
    /* 关闭数据库 */
    bool close_db();

private:
    sqlite3* db;
};

#endif //__MY_SQLITE_HPP__

