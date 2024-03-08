#include <iostream>
#include "myArray.cpp"
/* 直接调.cpp 。hpp:? */

class Person
{
private:
    int age;
public:
    Person();
    ~Person();
};

Person::Person()
{
    std::cout << "Person" << std::endl;
}

Person::~Person()
{
    std::cout << "~Person" << std::endl;
}


int main()
{
    MyArray<int> arr(10);
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    std::cout << arr.getSize() << std::endl;
    MyArray<Person> arr1(2);
    return 0;
}
