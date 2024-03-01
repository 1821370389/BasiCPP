#include <iostream>
#include <cstdlib>

class Test
{
public:
    Test()
    {
        std::cout << "构造函数" << std::endl;
    }

    ~Test()
    {
        std::cout << "析构函数" << std::endl;
    }
};

int main()
{
    Test *p = new Test();
    delete p;
    std::cout << "————————分界线————————\n";
    // Test *p1 = (Test*)malloc(sizeof(Test));     // 并不会调用构造函数
    // free(p1);                                   // 并不会调用析构函数

    Test *p2 = new Test[3];
    delete[] p2;
    return 0;
}
