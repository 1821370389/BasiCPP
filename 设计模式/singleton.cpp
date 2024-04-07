#include <iostream>
#include <thread>
#include <mutex>

/* 懒汉式 线程不安全 */
#if 0
class Singleton
{
public:
    static Singleton* getInstance();
    static std::mutex m;
    ~Singleton();
    void Release();

private:
    Singleton();
    static Singleton* p;
};

Singleton::Singleton()
{
    std::cout << "Singleton" << std::endl;
}

Singleton *Singleton::getInstance()
{
    if (p == nullptr)
    {
        p = new Singleton();
    }
    return p;
}

void Singleton::Release()
{
    delete p;
    p = nullptr;
}

Singleton::~Singleton()
{
    delete p;
}

Singleton *Singleton::p = nullptr;
std::mutex Singleton::m;
std::mutex m;

void threadFunc()
{
    std::lock_guard<std::mutex> lock(Singleton::m);
    Singleton *p = Singleton::getInstance();
    std::cout << p << std::endl;
}

int main()
{
    // Singleton *p = Singleton::getInstance();
    // Singleton *p1 = Singleton::getInstance();
    // std::cout << p << std::endl;
    // std::cout << p1 << std::endl;
    std::thread t[10];
    for (auto &i : t)
    {
        i = std::thread(threadFunc);
    }
    for (auto &i : t)
    {
        i.join();
    }
    return 0;
}
#else
/* 饿汉式 线程安全 */
class Singleton
{
public:
    static Singleton* getInstance();
    ~Singleton();
    void Release();
private:
    Singleton();
    static Singleton* p;
};

Singleton::Singleton()
{
    std::cout << "Singleton" << std::endl;
}

Singleton *Singleton::getInstance()
{
    if (p == nullptr)
    {
        p = new Singleton();
    }
    return p;
}

Singleton::~Singleton()
{
    delete p;
}
void Singleton::Release()
{
    delete p;
    p = nullptr;
}

/* 区别在此处 */
Singleton *Singleton::p = new Singleton;


void threadFunc()
{
    Singleton *p = Singleton::getInstance();
    std::cout << p << std::endl;
}

int main()
{
    std::thread t[10];
    for (auto &i : t)
    {
        i = std::thread(threadFunc);
    }
    for (auto &i : t)
    {
        i.join();
    }
    return 0;
}
#endif 