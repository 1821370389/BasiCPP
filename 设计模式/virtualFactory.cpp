#include <iostream>

class Fruit
{
public:
    virtual void show() = 0;
};

class NorthApple : public Fruit
{
public:
    void show()
    {
        std::cout << "北方苹果" << std::endl;
    }
};
class SouthApple : public Fruit
{
public:
    void show()
    {
        std::cout << "南方苹果" << std::endl;
    }
};
class NorthPear : public Fruit
{
public:
    void show()
    {
        std::cout << "北方梨" << std::endl;
    }
};
class SouthPear : public Fruit
{
public:
    void show()
    {
        std::cout << "南方梨" << std::endl;
    }
};

class Factory
{
public:
    virtual Fruit* createApple() = 0;
    virtual Fruit* createPear() = 0;
};

class NorthFactory : public Factory
{
public:
    Fruit* createApple()
    {
        return new NorthApple();
    }
    Fruit* createPear()
    {
        return new NorthPear();
    }
};
class SouthFactory : public Factory
{
public:
    Fruit* createApple()
    {
        return new SouthApple();
    }
    Fruit* createPear()
    {
        return new SouthPear();
    }
};

int main()
{
    Factory* factory = new NorthFactory();
    Fruit* apple = factory->createApple();
    Fruit* pear = factory->createPear();
    apple->show();
    pear->show();
    delete apple;
    delete pear;
    delete factory;
    factory = new SouthFactory();
    apple = factory->createApple();
    pear = factory->createPear();
    apple->show();
    pear->show();
    delete apple;
    delete pear;
    delete factory;
    return 0;
}