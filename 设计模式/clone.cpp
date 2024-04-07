#include <iostream>
#include <string>

class Clone
{
public:
    virtual Clone* clone() = 0;
    virtual void show() = 0;
};

class Student : public Clone
{
public:
    Student(int ID, const std::string& name) : ID(ID), name(name) {}
    Clone* clone() override 
    { 
        return new Student(*this); 
    }
    void show() override 
    { 
        std::cout << "ID: " << ID << ", name: " << name << std::endl; 
    }
private:
    int ID;
    std::string name;
};

int main()
{
    Student *s1 = new Student(1, "Alice");
    Clone* s2 = s1->clone();
    s2->show();
    std::cout << "s1 address: " << s1 << ", s2 address: " << s2 << std::endl;
    delete s2;
    return 0;
}