#include <iostream>

int func()
{
    std::cout << "func" << std::endl;
    return 0;
}

template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
    int a = 10;
    const int b = 20;
    decltype(b) c;

    decltype(func()) d;

    return 0;
}