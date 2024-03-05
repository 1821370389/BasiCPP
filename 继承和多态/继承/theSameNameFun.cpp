/* 继承7&8, 同名函数&变量 */
#include <iostream>
using namespace std;

class Student
{
private:
    int m_score;
public:
    int m_age;
    Student(int score)
    {
        m_score = score;
        cout << "Student()" << endl;
    }
    ~Student()
    {
        cout << "~Student()" << endl;
    }
    void showInfo()
    {
        cout << "m_score = " << m_score << endl;
    }
    void makeMoney()
    {
        cout << "Student make money" << endl;
    }
};

class Worker
{
private:
    int m_sarary;
public:
    int m_age;
    Worker(int sarary)
    {
        m_sarary = sarary;
        cout << "Worker()" << endl;
    }
    ~Worker()
    {
        cout << "~Worker()" << endl;
    }
    void showInfo()
    {
        cout << "m_sarary = " << m_sarary << endl;
    }
    void makeMoney()
    {
        cout << "Worker make money" << endl;
    }
};

/* 多继承 */
class Undergraduate : public Worker,public Student
{
private:
    int m_id;
public:
    int m_age;
    /* 多继承的带参构造的调用 */
    Undergraduate(int score, int sarary, int id) : Student(score), Worker(sarary)
    {
        m_id = id;
        cout << "Undergraduate()" << endl;
    }

    ~Undergraduate()
    {
        cout << "~Undergraduate()" << endl;
    }
    void showInfo()
    {
        Student::showInfo();
        Worker::showInfo();
        cout << "m_id = " << m_id << endl;
    }
    void makeMoney()
    {
        cout << "Undergraduate make money" << endl;
    }
};

int main()
{
    Undergraduate u(90, 800, 404);
    /* 继承的同名函数的用法 */
    u.makeMoney();
    u.Student::makeMoney();
    u.Worker::makeMoney();

    /* 同名变量 */
    u.m_age = 30;
    u.Worker::m_age = 40;
    u.Student::m_age = 50;
    cout << "u.m_age = " << u.m_age << endl;
    cout << "u.Worker::m_age = " << u.Worker::m_age << endl;
    cout << "u.Student::m_age = " << u.Student::m_age << endl;
    return 0;
}