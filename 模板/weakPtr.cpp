#include <iostream>
#include <memory>
using namespace std;

class Car;

class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }
    ~Person()
    {
        cout << "~Person()" << endl;
    }
    void getCar(shared_ptr<Car> car)
    {
        m_pCar = car;
    }
private:
    // Car *m_pCar;

    // shared_ptr<Car> m_pCar;

    weak_ptr<Car> m_pCar;
};

class Car
{
public:
    Car()
    {
        cout << "Car()" << endl;
    }
    ~Car()
    {
        cout << "~Car()" << endl;
    }
    void setMaster(shared_ptr<Person> master)
    {
        m_pMaster = master;
    }
private:
    // Person *m_pMaster;

    // shared_ptr<Person> m_pMaster;

    weak_ptr<Person> m_pMaster;
};

int main()
{
    shared_ptr<Person> p1(new Person);
    shared_ptr<Car> c1(new Car);
    p1->getCar(c1);
    c1->setMaster(p1);
    /* 当shared_ptr循环引用时 会导致引用计数永远不等于0 从而导致内存泄露 
        为此引入了 weak_ptr 弱引用，但不会增加引用计数
        把其中一个shared_ptr改成weak_ptr就可以了
        */
    cout << "p1.use_count() = " << p1.use_count() << endl;
    cout << "c1.use_count() = " << c1.use_count() << endl;
    auto val = 100.0;

    cout << typeid(string).name() << endl;
    return 0;
}