#include <iostream>
#include <memory>

class Test
{
public:
    Test(){};
    Test(const Test &t) = delete;       // ban了复制构造
    void operator=(const Test &t) = delete;     // ban了运算符重载
    /* ban了这俩以实现独占的效果 */
private:
    int *a;
};

int main()
{
    Test t;
    // Test t2 = t;

    // t2 = t;

    return 0;
}