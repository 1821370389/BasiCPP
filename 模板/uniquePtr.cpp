#include <iostream>
#include <memory>
using namespace std;

class Person
{
private:
    int m_age;
public:
    Person();
    ~Person();
    void run();
    void setAge(int age) { m_age = age; }
    int getAge() { return m_age; }
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
    cout << "run()" << endl;
}

int main()
{
    // unique_ptr<Person[]> p(new Person[3]);
    unique_ptr<Person> p1(new Person);
    p1->run();
    p1->setAge(20);
    cout << "age = " << p1->getAge() << endl;
    {
        unique_ptr<Person> p2  = std::move(p1);
        p2->run();
        p2->setAge(30);
        cout << "age = " << p2->getAge() << endl;
    }
    p1->run();
    cout << "age = " << p1->getAge() << endl;

    return 0;
}
