#include <iostream>

/* 
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void show(const int &a)
{
    std::cout << "a:" << a << std::endl;
}

int main()
{
    int a = 10;
    /*
    int b = 20;
    swap(&a, &b);
    std::cout << a << "," << b << std::endl;
    */
    /*
    int &b = a;     // 引用定义必须初始化，初始化后不再改变朝向
    int c = 20;
    b = c;
    std::cout << a << "," << b << "," << c << std::endl;*/

    /*
    int b = 20;
    swap(a, b);
    std::cout << a << "," << b << std::endl;*/

    /*
    int &b = a;
    std::cout << "bSize:" << sizeof(b) << std::endl;
    double c = 3.14;
    double &d = c;
    std::cout << "dSize:" << sizeof(d) << std::endl;*/

    show(a);
    show(50);

    return 0;
}