#include <iostream>

class Drink
{
public:
    virtual void Boil() = 0;        // 烧水
    virtual void Brew() = 0;        // 冲泡
    virtual void PutSomething() = 0;// 加辅料

    /* 工作流程 */
    void MakeDrink()
    {
        Boil();
        Brew();
        PutSomething();
    }
};

class Coffee : public Drink
{
public:
    void Boil()
    {
        std::cout << "烧矿泉水" << std::endl;
    }
    void Brew()
    {
        std::cout << "冲咖啡" << std::endl;
    }
    void PutSomething()
    {
        std::cout << "加糖和牛奶" << std::endl;
    }
};
class MilkTea : public Drink
{
public:
    void Boil()
    {
        std::cout << "烧牛奶" << std::endl;
    }
    void Brew()
    {
        std::cout << "冲茶" << std::endl;
    }
    void PutSomething()
    {
        std::cout << "加珍珠" << std::endl;
    }
};

int main()
{
    Coffee coffee;
    coffee.MakeDrink();
    MilkTea milktea;
    milktea.MakeDrink();
    return 0;
}