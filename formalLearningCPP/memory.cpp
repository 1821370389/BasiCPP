#include <iostream>
#include <cstdlib>
#include <cstring>

#if 0
int main()
{
	char * str = (char *)malloc(sizeof(char) * 10);
    if(str == NULL)
    {
        std::cout << "malloc failed" << std::endl;
        return -1;
    }
    strcpy(str, "hello");
    std::cout << str << std::endl;
    free(str);

    char ** arr = (char **)malloc(sizeof(char*) * 3);
    if(arr == NULL)
    {
        std::cout << "malloc failed" << std::endl;
        return -1;
    }
    for(char idx = 0; idx < 3; idx++)
    {
        arr[idx] = (char*)malloc(sizeof(char)*10);
        if(arr[idx] == NULL)
        {
            std::cout << "malloc failed" << std::endl;
            return -1;
        }
    }
    strcpy(arr[0], "hello");
    strcpy(arr[1], "world");
    strcpy(arr[2], "!");
    for(char idx = 0; idx < 3; idx++)
    {
        std::cout << arr[idx] << std::endl;
    }
    for(char idx = 0; idx < 3; idx++)
    {
        free(arr[idx]);
    }
    free(arr);
    
    return 0;
}
#else
int main()
{
    char* s = new char[10];
    /*
        1. 不需要计算内存的大小 
        2. 不需要对指针进行转换
        3. 不需要判断指针是否为空：抛出异常，终止程序
    */
    strcpy(s, "hello");
    std::cout << s << std::endl;

    // 释放数组
    delete[] s;
    
    int *a = new int(10);   // 小括号是赋值，中括号是数组大小
    std::cout << *a << std::endl;
    delete a;               // 直接释放，不用中括号

    char **arr = new char*[3];
    for(char idx = 0; idx < 3; idx++)
    {
        arr[idx] = new char[10];
        strcpy(arr[idx], "hello");
    }
    // strcpy(arr[0], "hello");
    // strcpy(arr[1], "world");
    // strcpy(arr[2], "!");
    for(char idx = 0; idx < 3; idx++)
    {
        std::cout << arr[idx] << std::endl;
    }
    for(char idx = 0; idx < 3; idx++)
    {
        delete[] arr[idx];
    }
    delete[] arr;
    return 0;
}

#endif 