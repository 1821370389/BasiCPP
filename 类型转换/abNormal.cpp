#include <iostream>
#include <string>
using namespace std;

#if 0
int main()
{
    cout << "Hello World!" << endl;
    try
    {
        int size = 1e9;
        cout << "Allocating " << size << " bytes" << endl;
        int* p = new int[size];
    }
    catch(...)
    {
        cout << "捕获到异常" << endl;
    }


    cout << "Goodbye World!" << endl;
    return 0;
}
#endif
#if 0
// 异常抛出声明
int func1()                     // 可能抛出任何类型
{
    return 0;
}
int func2() throw()             // 不会抛出
{
    return 0;
}
// int func3() noexcept(true)          // 不会抛异常 或这样
int func3() noexcept
{
    return 0;
}
int func4() noexcept(false)           // 可能抛出异常
{
    return 0;
}

int myDiv(int a, int b) 
{
    if(b == 0)
    {
        throw "除数不能为0";
    }
    return a / b;
}

int main()
{
    try
    {
        int a = myDiv(1, 0);
    }
    catch(const char* e)
    {
        cout << e << endl;
    }
    catch(...)  // 捕捉所有异常
    {
        cout << "其他异常" << endl;
    }

    return 0;
}
#endif 

#if 0
/* 抽象类 
    1. 具有纯虚函数的类叫做抽象类，纯虚函数: 虚函数初始化为零
    2. 抽象类不能实例化对象
    */
class Exception
{
public:
    virtual string what() const = 0;
};

class DivException : public Exception
{
public:
    string what() const
    {
        return "不能除以0";
    }
};
class MemoryFlowException : public Exception
{
public:
    string what() const
    {
        return "内存溢出";
    }
};

int myDiv(int a, int b) noexcept(false)
{
    if(b == 0)
    {
        throw DivException();
    }
    return a / b;
}

int main()
{
    // Exception* p = new DivException();
    // cout << p->what() << endl;
    // delete p;

    // Exception* p = new Exception();抽象类类型“Exception”的无效新表达式
    // Exception::run();不能在没有对象的情况下调用成员函数virtual void Exception::run()
    
    // try
    // {
    //     int a = myDiv(1, 0);
    // }
    // catch(const Exception& e)
    // {
    //     cout << e.what() << endl;
    // }

    try
    {
        int size = 1e9;
        cout << "Allocating " << size << " bytes" << endl;
        int* p = new int[size];
        delete[] p;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
#endif

class Person
{
private:
    int m_age;
public:
    Person();
    virtual ~Person();
    virtual void run();
};

Person::Person()
{
    cout << "Person()" << endl;
}
Person::~Person()
{
    cout << "~Person()" << endl;
}
void Person::run()
{
    cout << "Person::run()" << endl;
}

class Student : public Person
{
private:
    int m_score;
public:
    Student();
    ~Student();
    void run();
    void study();
};
Student::Student()
{
    cout << "Student()" << endl;
}
Student::~Student()
{
    cout << "~Student()" << endl;
}
void Student::run()
{
    cout << "Student::run()" << endl;
}
void Student::study()
{
    cout << "Student::study()" << endl;
}

int main()
{
    Person* p1 = new Person();
    Person* p2 = new Student();
    Person& p3 = *p1;
    try
    {
        Student& stu1 = dynamic_cast<Student&>(p3);
        // stu1->run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Student* stu2 = dynamic_cast<Student*>(p2);
        stu2->run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    delete p1;
    delete p2;

    return 0;
}
