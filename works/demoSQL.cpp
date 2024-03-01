#include<iostream>
#include<string>
#include<vector>
#include"mySqlite.hpp"

/* 打印二维数组 */
void print_2d_array(std::vector<std::vector<std::string>> &res)
{
    std::cout << "打印数组 :" << std::endl;
    int row = res.size();
    if(row == 0) return;
    int col = res[0].size();
    std::cout << "row :" << row << " col :" << col << std::endl;
    for(int idx = 0; idx < row; idx++)
    {
        for(int jdx = 0; jdx < col; jdx++)
        {
            std::cout << res[idx][jdx] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    MySqlite sql("test.db");
    sql.create_table("student",{"id","name","age"});
    sql.insert_data("student", {"id","name","age"}, {"1", "zhangsan", "28"});
    sql.insert_data("student", {"2", "lisi", "21"});
    sql.insert_data("student", {"3", "wangwu", "24"});
    sql.insert_data("student", {"4", "zhaoliu", "18"});
    std::vector<std::vector<std::string>> res = sql.query_data("student", "WHERE age > '20'");
    print_2d_array(res);
    sql.delete_data("student", "age > '25'");
    res = sql.query_data("student");
    print_2d_array(res);
    sql.update_data("student", "age", "'18'", "age > '21'");
    res = sql.query_data("student");
    print_2d_array(res);

    return 0;
    
    

}