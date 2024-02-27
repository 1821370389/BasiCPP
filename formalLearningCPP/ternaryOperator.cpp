#include <iostream>

int main()
{
    int a = 100;
    int b = 90;
    #if 0
    a > b ? b+=10 : a+=10;
    #else
    (a > b ? b:a) += 10;
    #endif 
    std::cout<<"a:"<<a<<std::endl;
    
    std::cout<<"b:"<<b<<std::endl;

    
}