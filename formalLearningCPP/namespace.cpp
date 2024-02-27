#include <iostream>

/* 尾插函数 */
namespace A
{
    void InsertTail()
    {
        std::cout<<"A"<<std::endl;
    }
    int a = 10;
}

namespace B
{
    void InsertTail()
    {
        std::cout<<"B"<<std::endl;
    }
    int a = 20;
    namespace c
    {
        int a = 30;
    }
}

int main()
{

    int a[] = {1,2,3};
    A :: InsertTail();
    using namespace B;
    // 声明后面的代码使用命名空间B的变量&函数
    InsertTail();
    
    return 0;
}