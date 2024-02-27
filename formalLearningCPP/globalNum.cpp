#include <iostream>

int a = 10;

int main()
{
    int a = 20;
    // ::a 表示 a 的作用域来自全局
    std::cout<<::a<<std::endl;
    std::cout<<a<<std::endl;
    return 0;
}