#include <iostream>
#include <functional>
#include <map>

#if 0
// void print()
// {
//     std::cout << "print" << std::endl;
// }
void print(int a, int b)
{
    std::cout << "print" << a << b << std::endl;
}

class func
{
public:
    void operator()()
    {
        std::cout << "func" << std::endl;
    }
};

int main()
{
    // std::function<void()> f = print;
    // f();
    std::function<void(int,int)> f2 = print;
    f2(10,10);
    std::function<void()> f3 = func();
    f3();
    std::function<void()> f4 = []() {std::cout << "lambda" << std::endl;};
    return 0;
}
#elif 1

int add(int a, int b)
{
    return a + b;
}

class minus
{
public:
    int operator()(int a, int b)
    {
        return a - b;
    }
};

std::map<char, std::function<int(int, int)>> m;

int Calculate(char symbol, int a, int b)
{
    return m[symbol](a, b);
}





class Func
{
public:
    void print()
    {
        std::cout << "Func" << std::endl;
    }
};

int divide(int a, int b, int c)
{
    return a / b / c;
}

int main()
{
    // // 状态注册机
    // m['+'] = add;
    // m['-'] = minus();
    // m['*'] = [](int a, int b) {return a * b;};

    // std::cout << Calculate('-', 1, 2) << std::endl;

    // 函数属于特定的对象 
    // std::function<void()> f = Func().print;
    // f();
    Func func;
    auto f = std::bind(&Func::print, &func);
    f();

    // 函数格式不匹配
    // m['/'] = divide;
    /* std::placeholders::_1: 占位符 函数原参数继续占据该位置 */
    auto d = std::bind(divide, std::placeholders::_1, std::placeholders::_2, 1);
    m['/'] = d;
    std::cout << Calculate('/', 8, 2) << std::endl;
    return 0;
}

#endif 