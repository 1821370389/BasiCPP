#include <iostream>

constexpr int func(int a)
{
    return a*10;
}

template<int size>
class Test
{
public:

private:
    char arr[size];
};

class A
{
int a;
};

int main()
{
    // constexpr int a = 10*10;
    // std::cout << func(a) << std::endl;
    #if 0
    int a = 10;
    #else
    // constexpr int a = 10;
    constexpr int a = sizeof(A);
    #endif
    Test<a> test;
    return 0;
}
