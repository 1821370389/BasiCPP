#include <iostream>

/* 复杂产品 */
class Car
{
public:
    void setEngine(std::string engine)
    {
        this->engine = engine;
    }
    void setWheel(std::string wheel)
    {
        this->wheel = wheel;
    }
    void setBody(std::string body)
    {
        this->body = body;
    }

    void show()
    {
        std::cout << "造好了一辆汽车: " << engine << ", " << wheel << ", " << body << std::endl;
    }

private:
    std::string engine; // 引擎
    std::string wheel;  // 轮胎
    std::string body;   // 车身
};

/* 建造者抽象类 */
class Assembler
{
public:
    Assembler() : car(new Car()) {}
    virtual void buildEngine() = 0;
    virtual void buildWheel() = 0;
    virtual void buildBody() = 0;
    Car* getCar()
    {
        return car;
    }
protected:
    Car* car;
};

class AssemblerA : public Assembler
{
public:
    void buildEngine()
    {
        car->setEngine("引擎A");
    }
    void buildWheel()
    {
        car->setWheel("轮胎A");
    }
    void buildBody()
    {
        car->setBody("车身A");
    }
};
class AssemblerB : public Assembler
{
public:
    void buildEngine()
    {
        car->setEngine("引擎B");
    }
    void buildWheel()
    {
        car->setWheel("轮胎B");
    }
    void buildBody()
    {
        car->setBody("车身B");
    }
};
class AssemblerC : public Assembler
{
public:
    void buildEngine()
    {
        car->setEngine("引擎C");
    }
    void buildWheel()
    {
        car->setWheel("轮胎C");
    }
    void buildBody()
    {
        car->setBody("车身C");
    }
};
/* 指挥建造者 */
class Director
{
private:
    Assembler* assembler;

public:
    Director(Assembler* assembler) : assembler(assembler) {}
    Car* Assemble()
    {
        assembler->buildEngine();
        assembler->buildWheel();
        assembler->buildBody();
        return assembler->getCar();
    }
};

int main()
{
    /* 定建造者类型 */
    AssemblerA assemblerA;
    /* 把建造对象给指挥者 */
    Director director(&assemblerA);
    director.Assemble()->show();
    return 0;
}