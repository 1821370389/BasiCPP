#include <iostream>
#include <set>

using namespace std;


/* 观察者基类 */
class ObserverBase
{
public:
    virtual string getName() = 0;  // 获取观察者名称
    virtual void update(const string& message) = 0; // 更新订阅消息
};

/* 观察者具体类 */
class observer : public ObserverBase
{
public:
    observer(const string& name) : name(name) {}
    string getName()
    {
        return name;
    }

    void update(const string& message)
    {
        cout << "我是" << name << ",我收到了消息:" << message << endl;
    }
private:
    string name;    // 名称
    string message; // 消息
};

/* 被观察者基类 */
class TargetBase
{
public:
    virtual void addObserver(ObserverBase* observer) = 0;       // 添加观察者
    virtual void removeObserver(ObserverBase* observer) = 0;    // 移除观察者
    virtual void BroadCast(const string& message) = 0;          // 更新消息
};

/* 具体被观察者 */
class Target : public TargetBase
{
public:
    Target(const string& name) : name(name) {}
    void addObserver(ObserverBase* observer)
    {
        observers.insert(observer);
        cout << name << "新增了观察者：" << observer->getName() << endl;
    }

    void removeObserver(ObserverBase* observer)
    {
        auto it = observers.find(observer);
        if (it != observers.end())
        {
            observers.erase(it);
            cout << "已移除观察者：" << observer->getName() << endl;
        }
        cout << "不存在该观察者" << endl;
    }

    void BroadCast(const string& message)
    {
        for(auto observer : observers)
        {
            observer->update(message);
        }
    }
private:
    set<ObserverBase*> observers;   // 观察者容器
    string name;
};

int main()
{
    TargetBase* target = new Target("张三");

    ObserverBase* ob1 = new observer("李四");
    ObserverBase* ob2 = new observer("王五");

    target->addObserver(ob1);
    target->addObserver(ob2);

    target->BroadCast("你们好");

    target->removeObserver(ob1);

    target->BroadCast("健在");
    delete target;
    delete ob1;
    delete ob2;
    return 0;
}