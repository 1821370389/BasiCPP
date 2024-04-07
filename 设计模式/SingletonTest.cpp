#include <iostream>
#include "SingletonTemplate.hpp"

class Test : public Singleton<Test> 
{
public:
    // void print() {
    //     std::cout << "Hello World!" << std::endl;
    // }
};

int main()
{
    Test *t1 = Test::getInstance();
    // t1->print();
    Test *t2 = Test::getInstance();
    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    return 0;
}