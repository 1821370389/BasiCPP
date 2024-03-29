#include <iostream>

#if 0
class Test
{
public:
    Test(int a):a(a){}
    Test(int a, int b):a(a),b(b){}
    Test(int a, int b, int c):a(a),b(b),c(c){}

private:
    int a;
    int b;
    int c;
}
#elif 1
/* 委托构造 */
class Test
{
public:
    Test(int a):a(a)
    {
        std::cout << "Test(int a)" << std::endl;
    }
    /* 委托现有构造函数帮忙构造 */
    Test(int a, int b):Test(a)
    {
        this->b = b;
    }
    Test(int a, int b, int c):Test(a,b)
    {
        this->c = c;
    }

private:
    int a;
    int b;
    int c;
};

class Derived : public Test
{
public:
#if 0
    Derived(int a):Test(a)
    {
        std::cout << "Derived(int a)" << std::endl;
    }
    Derived(int a, int b):Test(a, b)
    {
        std::cout << "Derived(int a, int b)" << std::endl;
    }
    Derived(int a, int b, int c):Test(a, b, c)
    {
        std::cout << "Derived(int a, int b, int c)" << std::endl;
    }
#else
    /* 继承父类 一键继承 */
    using Test::Test;
#endif 
};

#endif 
int main()
{
    Test t1(1);
    Test t2(1, 2);
    Test t3(1, 2, 3);
    std::cout << "Hello World!" << std::endl;
    Derived d1(1);
    return 0;
}