#include <iostream>

class Car
{
public:
    virtual void create() = 0;
};

class BENZ : public Car
{
public:
    void create()
    {
        std::cout << "创建一辆奔驰" << std::endl;
    }
};

class BMW : public Car
{
public:
    void create()
    {
        std::cout << "创建一辆宝马" << std::endl;
    }
};

class BYD : public Car
{
public:
    void create()
    {
        std::cout << "创建一辆比亚迪" << std::endl;
    }
};

// 工厂类 : 生产对象  将对象指针和构造对象的过程解耦
class Factory
{
public:
    Car *createBenz()
    {
        return new BENZ();
    }
    Car *createBMW()
    {
        return new BMW();
    }
    Car *createBYD()
    {
        return new BYD();
    }
};

int main()
{
    // Car *car = new BENZ();
    // car->create();
    // car = new BMW();
    // car->create();
    // car = new BYD();
    // car->create();
    Factory factory;
    Car *car = factory.createBenz();
    car->create();
    return 0;
}
