/* 
传统指针存在的问题:
    需要手动管理内存
    容易发生内存泄漏
    释放后会产生野指针
智能指针
    auto_ptr: 属于C++98标准, 在C++11中已经不推荐使用(有缺陷,比如不能用于数组)
    shared_ptr: 属于C++11标准
    */

#include <iostream>
#include <memory>

using namespace std;

#if 0
void test()
{
    int *ptr;   // 野指针
    ptr = nullptr;

    char * str = (char*)malloc(sizeof(char) * 10);  // 手动管理

    free(str);
    str = NULL;

    int* size = new int;
    
    cout << "size = " << size << endl;

    delete size;
    /* delete 和 free 都不会把指针置为NULL */
    size = NULL;
}
#endif

class Person
{
private:
    int m_age;
public:
    Person();
    ~Person();
    void run()
    {
        cout << "Person running." << endl;
    }
};

Person::Person()
{
    cout << "Person()" << endl;
}

Person::~Person()
{
    cout << "~Person()" << endl;
}

template <typename T>
class SmartPtr
{
private:
    T *m_ptr;
public:
    SmartPtr(T *ptr = nullptr);
    ~SmartPtr();
    T& operator*();
    T* operator->();
};
template <typename T> 
SmartPtr<T>::SmartPtr(T* ptr) : m_ptr(ptr) {}
template <typename T> 
SmartPtr<T>::~SmartPtr()
{
    delete m_ptr;
}
template <typename T> 
T& SmartPtr<T>::operator*()
{
    return *m_ptr;
}
template <typename T> 
T* SmartPtr<T>::operator->()
{
    return m_ptr;
}

int main()
{
#if 0
    {
        Person *p = new Person[2];
        delete[] p;
    }
#elif 0
    {
        /* shared_ptr的设计理念 
            多个shared_per可以指向同一个对象,当最后一个shared_ptr在作用域范围内结束时,对象才会被自动释放
            可以通过一个已存在的智能指针初始化一个新的智能指针
            */
        shared_ptr<Person> p1(new Person);
        p1->run();
        shared_ptr<Person[]> p2(new Person[2]);
        p2[1].run();
    }
#elif 1
    /* 引用计数 */
    /*sharend_ptr的原理
        一个shared_ptr会对一个对象产生强引用
        每个对象都有与之对应的强引用计数，记录着当前对象被多少个shared_ptr强引用着，可以通过shared_ptr的use_count函数获得强引用计数
        当有一个新的shared_ptr指向对象时，对象的强引用计数就会+1
        当有一个shared_ptr销毁时，对象的强引用就会-1
        当强引用计数为0时，对象就会自动销毁
        */
    {
        {
            shared_ptr<Person> p2;
            shared_ptr<Person> p3;
            {
                shared_ptr<Person> p1(new Person);
                p2 = p1;
                cout << p1.use_count() << endl;
            }
            cout << p2.use_count() << endl;
            p3 = p2;
            cout << p3.use_count() << endl;
        }
    }

#elif 0
    {
        auto_ptr<Person> p1(new Person);
        /* auto_ptr 不支持数组 */
        p1->run();
    }
#elif 1
    {
        SmartPtr<Person> p1 = new Person;
        p1->run();
    }
#endif
    return 0;
}