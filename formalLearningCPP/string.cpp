#include <iostream>
#include <string>

int main()
{
    // 声明
    std::string str;
    // std::cin >> str;    // 键盘输入
    // std::cout << str << std::endl;
    // 写入
    str = "hello world";
    std::cout << str << std::endl;

    // 比较
    if(str == "hello world")
    {
        std::cout << "str == hello world" << std::endl;
    }

    std::string str1 = "\ngood night, world";
    // 拼接
    str += str1;
    std::cout << str << std::endl;
    std::cout << "str的长度:" << str.length() << std::endl;
    std::cout << "str的大小:" << str.size() << std::endl;
    std::cout << "str的容积:" << str.capacity() << std::endl; 
    
    // 截取子串
    std::string str2 = str.substr(0, 5);
    std::cout << str2 << std::endl;

    // 查找字符串
    std::cout << str.find("world") << std::endl;

    return 0;
}