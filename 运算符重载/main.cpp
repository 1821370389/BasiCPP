#include <iostream>
#include <string>
#include "stdMyString.hpp"


int main()
{
    /*
    stdMyString s1("Hello");
    stdMyString s2("World ");

    std::cout << s1 << std::endl;
    s1[1] = 'a';
    std::cout << s1 << std::endl;
#if 0
    std::cout << s1 + "  " + s2 + "end " << std::endl;
    std::cout << s1 << std::endl;

    // if(s1 == s2)
    // {
    //     std::cout << "s1 == s2" << std::endl;
    // }
    // else
    // {
    //     std::cout << "s1 != s2" << std::endl;
    // }
    std::cout << s1.Size() << std::endl;
    std::cin >> s1;
    std::cout << s1 << std::endl;
    std::cout << s1.Size() << std::endl;
#endif
    stdMyString s = "10";
    std::cout << (int)s+1 << std::endl;
    */
    /*     
    MyStringList list;
    list += "zhangsan";
    list += "lisi";
    list += "wangwu";

    std::cout << list ;
    */
    stdMyString s1("I have a a a apple");
    MyStringList list = s1.split(" ");
    std::cout << list ;
    std::cout << s1 <<std::endl;
    std::cout << list.getsize() << std::endl;
    list[8] = "is";
    list -= "a";
    std::cout << list <<std::endl;

    return 0;
}