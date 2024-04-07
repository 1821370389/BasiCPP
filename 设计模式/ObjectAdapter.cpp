#include <iostream>

class USB
{
public:
    virtual void show()
    {
        std::cout << "USB接口" << std::endl;
    }
};

class TypeC
{
public:
    virtual void show()
    {
        std::cout << "TypeC接口" << std::endl;
    }
};

#if 1

/* 对象适配器 */
/* 用组合加继承 */
class Adapter : public USB
{
public:
    void show()
    {
        c.show();
    }
private:
    TypeC c;
};

#endif

int main()
{
    USB *usb = new Adapter();
    usb->show();
    return 0;
}