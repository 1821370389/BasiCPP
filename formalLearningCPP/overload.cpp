#include <iostream>

void show(int a)
{
    std::cout << a << std::endl;
}

void show(short a)
{
    std::cout << "short:" << a << std::endl;
}

void show(int a, int b)
{
    std::cout << a << " " << b << std::endl;
}
void show(char *a )
{
    std::cout << a << std::endl;
}


int main()
{
    char a[10] = "hello";
    show(a);
    int b = 10;
    show(b);
    int c = 20;
    show(b,c);

    return 0;
}