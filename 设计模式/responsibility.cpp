#include <iostream>

struct request
{
    int money; // 涨薪数量
};

/* 抽象经理类 */
class Manager
{
public:
    Manager(const std::string &name) : name(name){}
    virtual void SetManager(Manager *manager)  // 设置上级
    {
        this->manager = manager;
    }
    virtual void GetRequest(request* req) = 0;       // 获取请求
protected:
    std::string name;
    Manager *manager; // 上级
};

class CommonManager : public Manager
{
public:
    using Manager::Manager;
    void GetRequest(request* req) override
    {
        if (req->money <= 1000)
        {
            std::cout << name << "批准了涨薪" << req->money << "的请求" << std::endl;
        }
        else if (manager != nullptr)
        {
            manager->GetRequest(req);
        }
    }
};

class Major : public Manager
{
public:
    using Manager::Manager;
    void GetRequest(request* req) override
    {
        if (req->money <= 2000)
        {
            std::cout << name << "批准了涨薪" << req->money << "的请求" << std::endl;
        }
        else if (manager != nullptr)
        {
            manager->GetRequest(req);
        }
    }
};

class GeneralManger : public Manager
{
public:
    using Manager::Manager;
    void GetRequest(request* req) override
    {

        std::cout << name << "批准了涨薪" << req->money << "的请求" << std::endl;
        

    }
};

int main()
{
    Manager* commonManager = new CommonManager("张经理");
    Manager* major = new Major("李总监");
    Manager* generalManger = new GeneralManger("王总");

    commonManager->SetManager(major);
    major->SetManager(generalManger);

    request req = {10200};
    commonManager->GetRequest(&req);
    return 0;
}