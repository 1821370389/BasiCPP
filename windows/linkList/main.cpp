#include <iostream>
#include "linkList.cpp"
#include <string>
#include <vector>

class Person
{
private:
    std::string m_name;
    std::string m_sex;
    int m_age;
public:
    Person(std::string name, std::string sex, int age): m_name(name), m_sex(sex), m_age(age)
    {
        std::cout << "构造" << std::endl;
    };
    Person(const Person& P);
    Person():Person("Untitled", "man", 18){};
    ~Person()
    {
        std::cout << "析构" << std::endl;
    }

    std::string getName();
    std::string getSex();
    int getAge();

    bool operator>(const Person& P2);
    bool operator<(const Person& P2);
    friend std::ostream& operator<<(std::ostream& os, const Person& P);
};
Person::Person(const Person& P)
{
    m_name = P.m_name;
    m_sex = P.m_sex;
    m_age = P.m_age;
    std::cout << "复制构造" << std::endl; 
}
std::string Person::getName()
{
    return m_name;
}
std::string Person::getSex()
{
    return m_sex;
}
int Person::getAge()
{
    return m_age;
}

bool Person::operator>(const Person& P2)
{
    return m_age > P2.m_age;
}
bool Person::operator<(const Person& P2)
{
    return m_age < P2.m_age;
}
std::ostream& operator<<(std::ostream& os, const Person& P)
{
    os << "Name: " << P.m_name << std::endl;
    os << "Sex: " << P.m_sex << std::endl;
    os << "Age: " << P.m_age ;
    return os;
}

int main()
{
    LinkedList<Person> pList;
    pList.insertTail(Person("zhangsan","man",15));
    pList + Person("lisi", "man",16);
    std::cout << "_____________" << std::endl;
    pList.insert(1,Person("wangwu","man",18));
    pList.insertHead(Person("liuliu","man",25));
    pList.print();
    std::cout << "_____________" << std::endl;
    pList.sort();
    pList.print();
    pList.remove(1);
    pList.print();
    pList.reverse();
    pList.print();
    std::cout << "_____________" << std::endl;
    pList.destroy();
    
    std::cout << "_____________" << std::endl;

    return 0;
}