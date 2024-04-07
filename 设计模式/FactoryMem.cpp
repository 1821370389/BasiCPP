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

/*‘ 抽象工厂类 */
class Factory
{
public:
    virtual Car *createCar() = 0;
};

/* 具体工厂类 */
class FactoryBenz : public Factory
{
public:
    Car *createCar()
    {
        return new BENZ();
    }
};
class FactoryBMW : public Factory
{
public:
    Car *createCar()
    {
        return new BMW();
    }
};
class FactoryBYD : public Factory
{
public:
    Car *createCar()
    {
        return new BYD();
    }
};

/* 工厂的工厂 */
class FactoryFactory
{
public:
    static Factory *createBenzFactory()
    {
        return new FactoryBenz();
    }
};

int main()
{
    FactoryFactory* ff = new FactoryFactory();
    Factory *factory = ff->createBenzFactory();
    
    // Factory *factory = new FactoryBenz;
    Car *car = factory->createCar();
    car->create();
    return 0;
}
