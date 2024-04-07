#include <iostream>

//   * 抽象产品
class Car
{
public:
    virtual void show() = 0;
protected:
    std::string name;
};

//   * 具体产品
class BMW : public Car
{
public:
    BMW()
    {
        this->name = "宝马";
    }
    void show()
    {
        std::cout << name << std::endl;
    }
};

//   * 抽象装饰
/* 装饰者抽象类 */
class Decorator : public Car
{
public:
    Decorator(Car* car) : car(car) {}
    void show()
    {
        car->show();
    }
protected:
    Car* car;
};

//   * 具体装饰
/* 导航 */
class Navigator : public Decorator
{
public:
    using Decorator::Decorator;
    void show()
    {
        std::cout<< "导航";
        car->show();
    }
};
/* 自动驾驶 */
class SelfDrive : public  Decorator
{
public:
    using Decorator::Decorator;
    void show()
    {
        std::cout << "自动驾驶";
        car->show();
    }
};
/* 语音控制 */
class VoiceControl : public Decorator
{
public:
    using Decorator::Decorator;
    void show()
    {
        std::cout << "语音控制";
        car->show();
    } 
};


int main()
{
    Car* car = new BMW;
    car->show();
    Decorator* decorator = new SelfDrive(car);
    decorator->show();
    Decorator* decorator2 = new Navigator(decorator);
    decorator2->show();
    Decorator* decorator3 = new VoiceControl(decorator2);
    decorator3->show();
    delete car;
    delete decorator;
    delete decorator2;
    delete decorator3;
    return 0;
}