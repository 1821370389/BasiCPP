#include <iostream>

class Test
{
private:
    int a;
    int b;
public:
    Test(int a, int b);
    Test(const Test &test);
    ~Test();
    Test classClone();
    void showInfo();

};

#if 0
Test::Test(int a, int b) : a(a), b(b)
{
#else
Test::Test(int a, int b)
{
    this->a = a;
    this->b = b;
#endif
    std::cout << "构造函数" << std::endl;
}

Test::Test(const Test &test) : a(test.a), b(test.b)
{
    std::cout << "拷贝构造函数" << std::endl;
}


Test::~Test()
{
    std::cout << "析构函数" << std::endl;
}

Test Test::classClone()
{
    return *this;
}

void Test::showInfo()
{
    std::cout << this->a << " " << b << std::endl;
}

int main()
{
    Test test(1, 2);
    Test test2 = test.classClone();
    test.showInfo();
    test2.showInfo();
    test2.classClone().showInfo();
    return 0;
}
