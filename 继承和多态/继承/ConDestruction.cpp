#include <iostream>
using namespace std;

const int NAMESIZE = 20;
class Person
{
public:
    Person()
    {
        m_name = new char[NAMESIZE];
        cout << "Person()" << endl;
    }
    ~Person()
    {
        // delete[] m_name;
        m_name = NULL;
        cout << &m_name << endl;
        cout << "~Person()" << endl;
    }
public:
	int m_age;
    char* m_name;
};

class Student : public Person
{
public:

    Student()
    {
        m_school = new char[NAMESIZE];
        cout << "Student()" << endl;
    }
    ~Student()
    {
        printf("释放前:%p\n", m_school);
        cout << "释放前:" << m_school << endl;
        delete[] m_school;
        printf("置空前:%p\n", m_school);
        cout << "置空前:" << m_school << endl;
        m_school = nullptr;
        cout << "释放后:" << m_school << endl;
        // printf("释放后:%p\n", m_school);
        cout << "~Student()" << endl;
    }
public:
	int m_score;
    char* m_school;
};



int main()
{
    // Student s;
    Student * per = new Student();
    per->m_age = 10;
    per->m_score = 100;
    
	return 0;
}
