#include <iostream>
using namespace std;

/* 命名规范:
    全局变量用g_开头
    成员属性用m_开头
    局部变量没有限制*/


class Person
{
private:
public:
    int m_height;
    int m_age;
    Person(int height = 155, int age = 16): m_height(height), m_age(age){}
    void run()
    {
        cout << "Person run" << endl;
    }
    void showInfo()
    {
        cout << "Person's age:" << m_age << endl;
    }
};


class Student : Person
{
private:
    int m_sNo;
public:
    Student():Person(0,0)       // 父类带参构造的初始化
    {
        m_sNo = 0;
    }
    void run()
    {
        cout << "Student run" << endl;
    }
    void showInfo()
    {
        cout << "Student's age:" << m_age << endl;
        cout << "age的地址:" << &m_age << endl;
        cout << "Student's sNo:" << m_sNo << endl;
        cout << "sNo的地址:" << &m_sNo << endl;
        /* 继承的属性的地址是连续的,且父类的属性在子类前面*/
    }
};

int main()
{
    Person p(150,15);
    cout << sizeof(p) << endl;
    /* 成员函数不占用类的内存大小 */
    p.showInfo();
    Student s;
    cout << sizeof(s) << endl;
    /* 子类的大小=子类属性的大小+父类的大小 */
    s.showInfo();
    return 0;
}
