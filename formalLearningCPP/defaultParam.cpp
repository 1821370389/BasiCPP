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