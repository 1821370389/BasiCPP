#include <iostream>
#include <string.h>
#include <string>


struct student
{
    int age;
    char name[20];
    std::string address;
    void print()
    {
        std::cout << "age: " << age << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "address: " << address << std::endl;
    }
};

// 重命名 
typedef student stu;
using stu1 = student;

int main()
{
    student s;
    stu s1;
    stu1 s2;
    s.age = 20;
    strcpy(s.name, "zhangsan");
    s.address = "beijing";
    s.print();
}