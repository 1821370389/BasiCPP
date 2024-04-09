/* 中介者模式 */
#include <iostream>


class Mediator;


class House
{
public:
    House(Mediator* mediator) : mediator(mediator) {}
    virtual void SendMsg(const std::string& message) = 0;  // 发信息
    virtual void RecvMsg(const std::string& message) = 0;  // 收消息
protected:
    Mediator* mediator;
};


/* 抽象中介者 */
class Mediator {
public:
    void SetHouse(House* sellHouse, House* buyHouse)
    {
        this->sellHouse = sellHouse;
        this->buyHouse = buyHouse;
    }
    virtual void SendMsg(const std::string& message, House* house) = 0;
    
protected:
    House* sellHouse;
    House* buyHouse;
};

class SellHouse : public House
{
public:
    using House::House;
    void SendMsg(const std::string& message)  override
    {
        mediator->SendMsg(message, this);
    }
    void RecvMsg(const std::string& message) override
    {
        std::cout << "房东收到的消息: " << message << std::endl;
    }
};

class BuyHouse : public House
{
public:
    using House::House;
    void SendMsg(const std::string& message) override
    {
        mediator->SendMsg(message, this);
    }
    void RecvMsg(const std::string& message) override
    {
        std::cout << "房客收到的消息: " << message << std::endl;
    }
};


/* 具体中介者 */
class ConcreteMediator : public Mediator
{
public:
    void SendMsg(const std::string& message, House* house) override
    {
        if (house == sellHouse) // 房东
        {
            buyHouse->RecvMsg(message);
        }
        else if (house == buyHouse) // 房客
        {
            sellHouse->RecvMsg(message);
        }
    }
};

int main()
{
    Mediator* mediator = new ConcreteMediator();
    House* sellHouse = new SellHouse(mediator);
    House* buyHouse = new BuyHouse(mediator);
    mediator->SetHouse(sellHouse, buyHouse);

    sellHouse->SendMsg("我要出售房子");
    buyHouse->SendMsg("我要买房子");

    delete mediator;
    delete sellHouse;
    delete buyHouse;
    return 0;
}
