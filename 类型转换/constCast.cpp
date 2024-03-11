/* 类型转换
    C语言: 
        (type)expression
        type(expression)
    C++中的四个类型转换符
        static_cast         // 适配与将非const转为const
        dynamic_cast
        reinterpret_cast
        const_cast          // 将const转换为非const
        使用格式:xx_cast<type>(expression)
        */
#include <iostream>
#include <cstring>
using namespace std;

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

#if 0
/* const_cast,将const转换为非const */
int main()
{
    const char* str = "Hello world";
    #if 0
    /* 非法转换 
    char* p = str;
    */
    char* p = (char*)str;
    #elif 1
    /* 将const转换为非const属性*/
    char* p = const_cast<char*>(str);
    #endif

    /* 复合数据类型 */
    const Person* p1 = new Person();
#if 0
    Person* p = (Person*)p1;
#else
    Person* p2 = const_cast<Person*>(p1);
#endif
    p2->run();
    cout << p << endl;
}
#endif

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

#if 0
/* dynamic_cast:
    一般用于多态, 运行时进行安全检测
    进行不安全转换时，会自动置为NULL */
int main()
{
    Person* p1 = new Person();      // 指向自己
    Person* p2 = new Student();     // 父指向子
    p1->run();
#if 0
    Student* stu1 = (Student*)p1;   // 子指向父
    Student* stu2 = (Student*)p2;
#else
    Student* stu1 = dynamic_cast<Student*>(p1); /* 子类不能指向父类,父类没子类大,存在踩内存的风险  */
    Student* stu2 = dynamic_cast<Student*>(p2);
#endif
    cout << "stu1:" << stu1 << endl;
    cout << "stu2:" << stu2 << endl;
    // stu1->run();
    stu2->run();
    /* 
        内存泄露:
            1.野指针
            2.malloc分配未释放
            3.踩内存(其中子类指针指向父类没有使用dynamic_cast或许会踩内存)
    */
    delete p1;
    delete p2;
    // delete stu2;
    return 0;
}
#endif

#if 0
/* static_cast:
    一般用于类型转换, 将一个对象转换为另一个类型的对象
    转换过程中可能会出现类型转换异常 */
int main()
{
    int idx = 10;
    int* y = static_cast<int*>(idx);
    return 0;
}
/* 总结:
    1. 对比dynamic_cast, 缺乏运行时安全检测
    2. 不能交叉转换(不是同一继承体系的, 无法转换)
    3. 常用于基本类型的转换、非const转成const
    4. 使用范围较广*/
#endif

/* reinterpret_cast:
    没有安全检测*/
int main()
{
    int* p = reinterpret_cast<int*>(100);   // 整型转指针 
    cout << "p:" << p  <<endl;
    /* p:0x64 */
    int x = reinterpret_cast<long>(p);  // 指针转整型
    cout << "x:" << x << endl;
}