#include <iostream>

int main()
{
    int a = 1;
    std::cout << sizeof(a++) << std::endl;
    std::cout << a << std::endl;
    return 0;
}