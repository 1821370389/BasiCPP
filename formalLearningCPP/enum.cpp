#include <iostream>

// enum  class color
enum color
{
    black,
    white
};

// enum class RGB
enum RGB
{
    rad,
    green,
    blue
};

int main()
{
    // 此时会报警告，在枚举时若使用enum class 会直接报错
    if(color::white == RGB::green)
    {
        using namespace std;
        cout<<"euqal"<<endl;
    }
    
    std::cout<<"euqal"<<std::endl;
}