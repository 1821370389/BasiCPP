#include <iostream>
using namespace std;

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
    cout << "构造函数" << endl;
    a++;
}
Test::~Test()
{
    cout << "析构函数" << endl;
    a--;
}
void Test::func()
{
    cout << "Hello world!" << endl;
}
void Test::func2()
{
    /* 静态函数中拿不到类的对象及属性 
    this->m_b = 0;
    this->func();*/
    cout << "Hello world!" << endl;
}


int Test::a = 0;   // 静态成员变量的初始化

/* static:
    static修饰的变量(属性):
        1. 是属于类的
        2.访问方法3种
    static修饰的函数(方法):
        1. 拿不到普通函数
        2. 拿不到不同变量
        因为在静态函数里没有this

    */


int main()
{
    Test *t1 = new Test();
    /* 初值为0, 在构造中自加, 在析构里自减, 实现对类创建于销毁的检查 不为0即是有类申请的没释放 */

    /* 类内静态变量可以以以下三种方法获取 */
    Test::a = 0;
    Test t2;
    t2.a = 0;
    t1->a = 0;

    Test::func2();
    return 0;
}