/* 多态3, 虚析构 */
#include <iostream>

const int NAMESIZE = 20;

class Person
{
private:
    int m_age;
    char* m_name;
public:
    Person()
    {
        m_age = 18;
        m_name = new char[NAMESIZE];
        std::cout << "Person()" << std::endl;
    }
    virtual ~Person()
    {
        
        delete[] m_name;
        m_name = nullptr;
        std::cout << "~Person()" << std::endl;
    }
    virtual int makeMoney()
    {
        std::cout << "Persom-makeMoney()" << std::endl;
        return 1;
    }
};

class Student : public Person
{
private:
    int m_sNo;
    char* m_school;
public:
    Student()
    {
        m_sNo = 404;
        m_school = new char[NAMESIZE];
        std::cout << "Student()" << std::endl;
    }
    ~Student()
    {
        delete[] m_school;
        m_school = nullptr;
        std::cout << "~Student()" << std::endl;
    }
    int makeMoney()
    {
        Person::makeMoney();
        std::cout << "Studnet-makeMoney()" << std::endl;
        return 1;
    }
};

int main()
{
    Person* per = new Student;        // 父类指针指向子类对象
    /* 当使用父类指针指向子类对象可能会引起 */
    delete per;
    return 0;
}
