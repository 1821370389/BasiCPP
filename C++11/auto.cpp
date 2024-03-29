#include <iostream>
#include <vector>

// void fun(auto a)
// {
//     std::cout << "auto" << std::endl;
// }

int main()
{
    // auto a = 10;
    std::vector<int> v;
    // auto ite = v.begin();

    // auto定义需要初始化

    // auto a;

    const int a =  10;
    auto b = a;
    fun(a);

    // std::vector<auto> y = v;

    return 0;
}