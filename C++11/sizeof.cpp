#include <iostream>

struct A
{   
    int a;
    char b;
};


int main()
{
    // C中：
    A a;
    std::cout << sizeof(a.b) << std::endl;
    // C++中
    std::cout << sizeof(A::b) << std::endl;

    // 偏移量
    printf("%x\n", &A::b);
    return 0;
}
