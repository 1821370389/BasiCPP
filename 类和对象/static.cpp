#include <iostream>

class Test
{
private:
    int m_b;
public:
    static int a;
    Test();
    ~Test();
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


int Test::a = 0;   // 静态成员变量的初始化


int main()
{
    Test *t1 = new Test();
    Test *t2 = new Test();
    delete t1;
    delete t2;
    std::cout << Test::a << std::endl;
    /* 初值为0, 在构造中自加, 在析构里自减, 实现对类创建于销毁的检查 不为0即是有类申请的没释放 */
    return 0;
}