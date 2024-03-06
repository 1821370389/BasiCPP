/* 继承5, 多继承*/
#include <iostream>
using namespace std;

class Student
{
private:
    int m_score;
public:
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
};

class Worker
{
private:
    int m_sarary;
public:
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
};

/* 多继承 */
class Undergraduate : public Worker,public Student
{
private:
    int m_id;
public:
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
};

int main()
{
    Undergraduate u(90, 800, 404);
    /* 子类的内存分布是根据继承声明的顺序，而不是类定义的顺序 */
    cout << "sizeof(u) = " << sizeof(u) << endl;
    u.showInfo();
    return 0;
}