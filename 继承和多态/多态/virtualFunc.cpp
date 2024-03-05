/* 多态2, 虚函数 */
#include <iostream>
using namespace std;

class Person
{
private:
    int m_age;
public:
    Person()
    {
        m_age = 18;
        cout << "Person()" << endl;
    }
    ~Person()
    {
        cout << "~Person()" << endl;
    }
    virtual int makeMoney()
    {
        cout << "Persom-makeMoney()" << endl;
        return 1;
    }
};

class Student : public Person
{
private:
    int m_sNo;
public:
    Student()
    {
        m_sNo = 404;
        cout << "Student()" << endl;
    }
    ~Student()
    {
        cout << "~Student()" << endl;
    }
    int makeMoney()
    {
        Person::makeMoney();
        cout << "Studnet-makeMoney()" << endl;
        return 1;
    }
};
class Teacher : public Person
{
private:
    int m_tNo;
public:
    Teacher()
    {
        m_tNo = 502;
        cout << "Teacher()" << endl;
    }
    ~Teacher()
    {
        cout << "~Teacher()" << endl;
    }
    int makeMoney()
    {
        Person::makeMoney();
        cout << "Teacher-makeMoney()" << endl;
        return 1;
    }
};


int main()
{
    Person* per = new Student();        // 父类指针指向子类对象
    per->makeMoney();
    per = new Teacher();
    per->makeMoney();
    cout << "sizeof:" << sizeof(per) << endl;
    Student stu;
    cout << "sizeof:" << sizeof(stu) << endl;
    return 0;
}
/* 虚表: 用于存放虚函数的地址 
    虚表在内存中位置在父类变量的上面;

    只要父类中声明为虚函数，子类中重写的函数也自动变成虚函数(也就是说子类中可以省略virtual关键字)
    */