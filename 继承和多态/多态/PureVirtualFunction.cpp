/* 多态4, 纯虚函数 */
#include <iostream>
using namespace std;

/*  纯虚函数: 没有函数体且初始化为0的虚函数， 用来定义接口规范
    抽象类(Abstract Class)
        含有纯虚函数的类,不可以实例化(不可创建对象)
        抽象类也可以包含非纯虚函数、成员变量
        如果父类是抽象类,子类没有完全重写纯虚函数，那么这个子类依然是抽象类
    */

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
    virtual ~Person()
    {
        cout << "~Person()" << endl;
    }
    virtual int makeMoney()
    {
        cout << "Persom-makeMoney()" << endl;
        return 1;
    }
    /* 纯虚函数, 必须被子类重写 */
    virtual int shop() = 0;
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
    int shop()
    {
        cout << "Student-shop()" << endl;
        return 1;
    }
};


int main()
{
    Person* per = new Student();        // 父类指针指向子类对象
    per->makeMoney();
    delete per;
    return 0;
}