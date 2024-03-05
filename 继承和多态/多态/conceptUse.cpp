/* 多态1, 重写 */
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
    int makeMoney()
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
        cout << "Teacher-makeMoney()" << endl;
        return 1;
    }
};


int main()
{
    Person* per = new Student();
    per->makeMoney();
    return 0;
}