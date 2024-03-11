#include <iostream>
using namespace std;

class MyClass 
{
public:
    auto getValue() const 
    {
        return value;
    }
    friend auto getValue(const MyClass&);
private:
    int value = 42;
};

auto getValue(const MyClass& my)
{
    return my.value;
}

int main()
{
    auto add = [](auto a, auto b) { return a + b; };
    cout << add(1, 2) << endl;
    
    MyClass myClass;
    cout << getValue(myClass) << endl;

    return 0;
}