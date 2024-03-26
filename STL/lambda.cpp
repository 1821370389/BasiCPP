#include <iostream>

class Test
{
private:
    
public:
    Test();
    ~Test();
    void show()
    {
        std::cout << "show" << std::endl;
    }
    void lambda()
    {
   
        auto f = [=]() // 捕获this
        {
            this->show();     
        };
        f();
    }
};

Test::Test()
{
}

Test::~Test()
{
}


int main()
{
    // int a = 11;
    // int b = 20;
    // auto f = [=,&a]()->int    // 捕获列表: 捕获上下文中的变量 (): 参数列表 ->类型: 返回值类型,一般不写
    // {
    //     a++;
    //     std::cout << a << std::endl;
    //     std::cout << b << std::endl;
    //     return 10;
    // };
    // std::cout << f() << std::endl;

    Test t;
    t.lambda();
    return 0;
}