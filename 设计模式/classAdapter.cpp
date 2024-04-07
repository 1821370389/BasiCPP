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

/* 类适配器 */
/* 用多继承 */
class Adapter : public USB, public TypeC
{
public:
    void show()
    {
        TypeC::show();
    }
};

#endif

int main()
{
    USB *usb = new Adapter();
    usb->show();
    return 0;
}