#include <iostream>

class Test
{
public:
    Test()
    {
        std::cout << "Test()" << std::endl;
    }
    Test(const Test& t)
    {
        std::cout << "拷贝构造 " << std::endl;
    }
};

void Print(int &a)
{
    std::cout << "左值引用" << std::endl;
}

void Print(int &&a)
{
    std::cout << "右值引用" << std::endl;
}

//完美转发(perfect forwarding)

template<typename T>
void func(T&& t)
{
    Print(std::forward<T>(t));
}
int main()
{
    Test t;
    // func(t);
    int a = 10;
    func(a);
    func(10);
    return 0;
}