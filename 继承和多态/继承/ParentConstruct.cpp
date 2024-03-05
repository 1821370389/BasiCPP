#include <iostream>
using namespace std;

class Person
{
/* 无参构造想调用有参构造函数必须使用初始化列表 */
public:
    Person(): Person(0)
    {
        cout << "Person()" << endl;
    }
	Person(int age): m_age(age)
    {
        cout << "Person(int)" << endl;
    }
public:
	int m_age;
};

class Student : public Person
{
public:
#if 0
    Student(int age, int score)
    {
        /* 若m_age是私有 则寄*/
        m_age = age;
        m_score = score;
    }
#elif 0
    Student(int age, int score) : m_age(age), m_score(score)
    {
        cout << "Student(int, int)" << endl;
    }
#elif 1
	Student(int age, int score): Person(age), m_score(score)
    {
        cout << "Student(int, int)" << endl;
    }
#endif
public:
	int m_score;
};



int main()
{
    Student s(155,80);
	return 0;
}
/* 
1. 子类的构造函数默认会调用父类的无参构造函数
2. 若要使用有参构造,则要在初始化列表中调用*/