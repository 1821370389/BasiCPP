#include <iostream>
#include <vector>
#include <initializer_list>     // 初始化列表

class A
{
public:
    A(std::initializer_list<int> list){}
};

std::vector<int> func()
{
    return {1, 2, 3};
}

void Log(std::initializer_list<std::string> list)
{
    for(auto i : list)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v = {1, 2, 3};
    A a({1, 2, 3, 4, 5});
    Log({"1.cpp", "line:12", "空指针"});
    return 0;
}