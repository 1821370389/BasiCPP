/* 继承9，虚继承 */
#include <iostream>
using namespace std;

#if 0
/* 菱形继承 */
class Person 
{
    int m_age;
};
class Student : public Person
{
    int m_grade;
};
class Worker : public Person
{
    int m_salary;
};
class Undergraduate : public Student, public Worker
{
    int m_class;
};

int main()
{
    Undergraduate ug;
    cout << "sizeof(ug): " << sizeof(ug) << endl;           // 20
    cout << "sizeof(Student): " << sizeof(Student) << endl; // 8
    cout << "sizeof(Worker): " << sizeof(Worker) << endl;   // 8
    cout << "sizeof(Person): " << sizeof(Person) << endl;   // 4
    /* ug 中会继承两次Person */

    return 0;
}
#elif 1
/* 虚继承 */
class Person 
{
    long m_age;
    long m_page1;
    long m_page2;
    long m_page3;
    long m_page4;
    long m_page5;
};
class Student : virtual public Person
{
    long m_grade;
    long m_sage1;
    long m_sage2;
};
class Worker : virtual public Person
{
    long m_salary;
    long m_wage1;
    long m_wage2;
};
class Undergraduate : public Student, public Worker
{
    long m_class;
    long m_sage3;
    long m_sage4;
};
int main()
{
    Undergraduate ug;                                       // 虚继承   非虚继承
    cout << "sizeof(ug): " << sizeof(ug) << endl;           // 136      168
    cout << "sizeof(Student): " << sizeof(Student) << endl; // 80       72
    cout << "sizeof(Worker): " << sizeof(Worker) << endl;   // 80       72
    cout << "sizeof(Person): " << sizeof(Person) << endl;   // 48       48
    /* ug 中会继承两次Person */

    return 0;
}
#endif