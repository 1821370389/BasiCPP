#include <iostream>
#include <string>

class Test
{
private:
    int *p;
public:
    Test();
    ~Test();
    Test(const Test &t);
};

Test::Test()
{
    std::cout << "构造函数" << std::endl;
    p = new int;
    *p = 10;

}

Test::~Test()
{
    delete p;
    std::cout << "析构函数" << std::endl;
}

Test::Test(const Test &t)
{
    std::cout << "拷贝构造" << std::endl;
    p = new int;
    *p = *t.p;
}

Test func()
{
    Test t;
    std::cout << "——————————————" << std::endl;
    return t;
}

Test& func1()
{
    // 返回引用会增加一次拷贝
    static Test t;  // 返回引用就要延长局部变量的寿命
    std::cout << "——————————————" << std::endl;
    return t;
}

Test func2(Test& t)
{
    return t;
}


int main()
{
#if 0
    // Test t;
    // Test t1 = t;

    Test();     // 匿名对象, 生命周期只有一行代码

    Test t = Test();
#endif
    Test t = func();
    // Test t1 = func1();
    Test t2 = func2(t);
    return 0;
}