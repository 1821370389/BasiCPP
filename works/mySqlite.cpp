#include <iostream>
#include <vector>
#include "mySqlite.hpp"

MySqlite::MySqlite(const std::string &db_name)
{
    sqlite3_open(db_name.c_str(), &db);
}
MySqlite::~MySqlite()
{
    sqlite3_close(db);
}

/* 无回调执行语句 */
static bool exec_sql(sqlite3 *db, const std::string &sql)
{
    std::cout << "Executing SQL: " << sql << std::endl;
    char *errmsg;
    int result = sqlite3_exec(db, sql.c_str(), NULL, NULL, &errmsg);
    if (result == SQLITE_OK)
    {
        return true;
    }
    else
    {
        std::cout << "Error: " << errmsg << std::endl;
        return false;
    }
}


/* 建表*/
bool MySqlite::create_table(const std::string& tablename, const std::vector<std::string> ages)
{
    std::string query = "CREATE TABLE IF NOT EXISTS " + tablename + " (";
    for (int i = 0; i < ages.size(); i++)
    {
        query += ages[i];
        if (i != ages.size() - 1)
        {
            query += ",";
        }
    }
    query += ");";
    return exec_sql(db, query);
}

/* 插入数据*/
bool MySqlite::insert_data(const std::string& tablename, const std::vector<std::string> headers, const std::vector<std::string> values)
{
    std::string query = "INSERT INTO " + tablename + " (";
    for (int i = 0; i < headers.size(); i++)
    {
        query += headers[i];
        if (i != headers.size() - 1)
        {
            query += ",";
        }
    }
    query += ") VALUES (";
    for (int i = 0; i < values.size(); i++)
    {
        query += "'" + values[i] + "'";
        if (i != values.size() - 1)
        {
            query += ",";
        }
    }
    query += ");";

    return exec_sql(db, query);
}

/* 插入数据(无表头) */
bool MySqlite::insert_data(const std::string& tablename, const std::vector<std::string> values)
{
    std::string query = "INSERT INTO " + tablename + " VALUES (";
    for (int i = 0; i < values.size(); i++)
    {
        query += "'" + values[i] + "'";
        if (i != values.size() - 1)
        {
            query += ",";
        }
    }
    query += ");";
    return exec_sql(db, query);
}

/* 回调函数 */
static int callback(void *data, int argc, char **argv, char **azColName)
{
    std::vector<std::vector<std::string>> *result = (std::vector<std::vector<std::string>> *)data;
    
    // 创建一个新的向量来存储当前行的数据
    std::vector<std::string> rowData;

    // 将每个列的数据存储到当前行的向量中
    for (int i = 0; i < argc; i++)
    {
        rowData.push_back(argv[i] ? argv[i] : "NULL");
    }

    // 将当前行的向量添加到结果向量中
    result->push_back(rowData);
    
    return 0;
}


/* 查询数据 */
std::vector<std::vector<std::string>> MySqlite::query_data(const std::string& tablename, const std::string& condition, const std::string& headers)
{
    std::vector<std::vector<std::string>> result;
    char *errmsg;
    std::string query = "SELECT " + headers + " FROM " + tablename + " " + condition + ";";
    int result_code = sqlite3_exec(db, query.c_str(), callback, (void *)&result, &errmsg);
    if (result_code != SQLITE_OK)
    {
        std::cout << "Error: " << errmsg << std::endl;
    }
    return result;
}

/* 修改数据 */
bool MySqlite::update_data(const std::string& tablename, const std::string& colName,const std::string& newValue, const std::string& condition)
{
    std::string query = "UPDATE " + tablename + " SET " + colName + " = " + newValue + " WHERE " + condition + ";";
    return exec_sql(db, query);
}

/* 删除数据 */
bool MySqlite::delete_data(const std::string& tablename, const std::string &condition)
{
    std::string query = "DELETE FROM " + tablename + " WHERE " + condition + ";";
    return exec_sql(db, query);
}

/* 关闭数据库 */
bool MySqlite::close_db()
{
    sqlite3_close(db);
    return true;
}
