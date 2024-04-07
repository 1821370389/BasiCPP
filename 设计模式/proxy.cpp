#include <iostream>

/* 抽象的被代理对象 */
class AbstractSystem    // 抽象系统
{
public:
    virtual void run() = 0;
};

class Windows : public AbstractSystem
{
public:
    void run()
    { 
        std::cout << "Windows系统启动!" << std::endl;
    }
};

class Linux : public AbstractSystem
{
public:
    void run()
    {
        std::cout << "Linux系统启动!" << std::endl;
    }
};

class Proxy
{
private:
    std::string user;
    std::string password;
    AbstractSystem *system;     // 代理对象

public:
    Proxy(std::string user, std::string password)
    {
        this->user = user;
        this->password = password;
    }

    void run()
    {
        if (user == "admin" && password == "123456")
        {
            system = new Windows();
            system->run();
        }
        else if (user == "root" && password == "1")
        {
            system = new Linux();
            system->run();
        }
        else
        {
            std::cout << "登录失败" << std::endl;
        }
    }
};

int main()
{
    // Proxy proxy("admin", "123456");
    Proxy proxy("root", "1");
    proxy.run();

    return 0;
}