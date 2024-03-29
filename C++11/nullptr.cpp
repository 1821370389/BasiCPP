#include <iostream>

void func(void *p)
{
    std::cout << "void *p" << std::endl;
}

void func(int p)
{
    std::cout << "int p" << std::endl;
}

int main()
{
    func(nullptr);
    func(0);
    // func(NULL);  // NULL 存在二义性
    return 0;
}