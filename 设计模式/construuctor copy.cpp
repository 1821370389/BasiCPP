#include <iostream>

/* 房子 */
class House
{
public:
    void setWindow(std::string window)
    {
        this->window = window;
    }
    void setDoor(std::string door)
    {
        this->door = door;
    }
    void setWall(std::string wall)
    {
        this->wall = wall;
    }
    void setType(std::string type)
    {
        this->type = type;
    }

    void show()
    {
        std::cout << "建了一间" << type << ", " << window << ", " << door << ", " << wall << std::endl;
    }
private:
    std::string window;
    std::string door;
    std::string wall;
    std::string type;
};

/* 建造者 */
class AssemblerHouse
{
public:
    AssemblerHouse() : house(new House()) {}
    virtual void buildWindow() = 0;
    virtual void buildDoor() = 0;
    virtual void buildWall() = 0;
    virtual void buildHouse() = 0;
    House* getHouse()
    {
        return house;
    }
protected:
    House* house;
};
/* 普通房子 */
class OrdinaryHouse : public AssemblerHouse
{
public:
    void buildWindow()
    {
        house->setWindow("普通窗户");
    }
    void buildDoor()
    {
        house->setDoor("普通门");
    }
    void buildWall()
    {
        house->setWall("普通墙");
    }
    void buildHouse()
    {
        house->setType("普通房子");
    }
};
/* 高档房子 */
class FancyHouse : public AssemblerHouse
{
public:
    void buildWindow()
    {
        house->setWindow("高档窗户");
    }
    void buildDoor()
    {
        house->setDoor("高档门");
    }
    void buildWall()
    {
        house->setWall("高档墙");
    }
    void buildHouse()
    {
        house->setType("高档房子");
    }
};

/* 建造指挥者 */
class DirectorHouse
{
private:
    AssemblerHouse* assembler;

public:
    DirectorHouse(AssemblerHouse* assembler) : assembler(assembler) {}
    House* Assemble()
    {
        assembler->buildWindow();
        assembler->buildDoor();
        assembler->buildWall();
        assembler->buildHouse();
        return assembler->getHouse();
    }
};


int main()
{
    /* 房屋样式 */
    FancyHouse fancyHouse;
    DirectorHouse directorHouse(&fancyHouse);
    directorHouse.Assemble()->show();
    return 0;
}