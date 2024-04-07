#include <iostream>
#include "memorypool.hpp"

class Test
{
public:
    Test()
    {
        std::cout << "Test()" << std::endl;
    }

    ~Test()
    {
        std::cout << "~Test()" << std::endl;
    }
    MEMORYPOOL(Test, 1024)
private:
    int a;
    int b;
    int c;
    int d;
};

int main()
{
    Test *p = new Test;
    return 0;
}