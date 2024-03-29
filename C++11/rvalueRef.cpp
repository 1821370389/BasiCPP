#include <iostream>
#include <vector>

class Test 
{
public:
    Test()
    {
        std::cout << "Test()" << std::endl;
    }
    Test(const Test& t)
    {
        std::cout << "拷贝构造" << std::endl;
    }
    Test(Test&& t)
    {
        std::cout << "移动语义/移动构造" << std::endl;
    }
};

int main()
{
    // Test t;
    // Test t2 = t;
    // Test t3 = std::move(t);

    // int a = 10;
    // int &b = a;     // 左值引用
    // int &&c = 10;   // 右值引用

    std::vector<int> v = {1, 2, 3};
    std::vector<int> v2 = std::move(v);

    std::cout << v.size() << std::endl;
    std::cout << v2.size() << std::endl;

    return 0;
}