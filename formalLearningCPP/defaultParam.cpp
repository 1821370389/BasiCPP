#include <iostream>
#include <cstring>


// 默认参数
/*
int add(int a, int b, int c = 0);

int add(int a, int b, int c)
{
    return a + b + c;
}
*/

bool func(int a, char *errorMsg = NULL)
{
    if(errorMsg != NULL)
    {
        strcpy(errorMsg, "Error");
    }
    return false;
}

// 占位默认参数
/*
int add(int a, int b, int = 0)
{
    return a + b;
}
*/
int add(int a, int b, ...)
{
    return a + b;
}

// 函数重载(函数名相同，参数不同，返回值可以相同，也可以不同，但是参数个数不能相同，参数类型不能相同，参数顺序不能相反，参数默认值不能相同)
// 函数重载可以使用函数模板，但是函数模板不能使用函数重载
// 函数重载不能使用函数模板重载


int main()
{
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1, 2, 3) << std::endl;
    char errorMsg[10];
    if(func(1, errorMsg) == false)
    {
        std::cout << errorMsg << std::endl;
    }
    func(1);
    return 0;
}