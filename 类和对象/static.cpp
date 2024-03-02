#include <iostream>

class Test
{
private:
    int m_b;
public:
    static int a;
    Test();
    ~Test();
    void func();
    /* 静态成员函数 调用时不用定义对象 不能调用私有属性 */
    static void func2();
};

Test::Test()
{
    std::cout << "构造函数" << std::endl;
    a++;
}
Test::~Test()
{
    std::cout << "析构函数" << std::endl;
    a--;
}
void Test::func()
{
    std::cout << "Hello world!" << std::endl;
}
void Test::func2()
{
    std::cout << "Hello world!" << std::endl;
}


int Test::a = 0;   // 静态成员变量的初始化


int main()
{
    Test *t1 = new Test();
    Test *t2 = new Test();
    std::cout << Test::a << std::endl;
    delete t1;
    delete t2;
    std::cout << Test::a << std::endl;
    /* 初值为0, 在构造中自加, 在析构里自减, 实现对类创建于销毁的检查 不为0即是有类申请的没释放 */

    Test::func2();
    return 0;
}