#include <iostream>

class Test
{
public:
    Test() = default;   // 让编译器默认生成无参构造
    Test(int a):a(a){};

private:
    int a;
};

int main()
{  
    Test t;
    return 0;
}