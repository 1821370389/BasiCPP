#include <iostream>

class Singleton
{
private:
    Singleton();
public:
    ~Singleton();
    static Singleton* Instance();
};

Singleton::Singleton()
{
    std::cout << "构造函数" << std::endl;
}

Singleton::~Singleton()
{
    std::cout << "析构函数" << std::endl;
}

Singleton* Singleton::Instance()
{
    static Singleton instance;
    return &instance;
}

int main()
{
    Singleton* s1 = Singleton::Instance();
    Singleton* s2 = Singleton::Instance();
    Singleton* s3 = Singleton::Instance();

    std::cout << s1 << " " << s2 << " " << s3 << std::endl;
    /* 只进行一次构造&析构, s1 = s2 = s3 */
    return 0;

}