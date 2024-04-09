#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <string>

#define Connect(signal, slot) Signal::instance().connect(signal, slot)
#define Disconnect(signal, slot) Signal::instance().disconnect(signal, slot)
#define Emit(signal, arg) Signal::instance().emit(signal, arg)

using namespace std;
using FuncArray = vector<function<void(void*)>>;


class Signal
{
public:

    static Signal& instance()
    {
        static Signal signal;
        return signal;
    }
    void connect(const string& signal, const function<void(void*)>& func)
    {

        auto& funcArray = callbacks[signal];
        funcArray.push_back(func);

        // auto ite = callbacks.find(signal);
        // if (ite != callbacks.end())
        // {
        //     ite->second.push_back(func);
        // }
        // else
        // {
        //     FuncArray funcArray;
        //     funcArray.push_back(func);
        //     callbacks[signal] = funcArray;
        // }

    }

    void disconnect(const string& signal, const function<void(void*)>& func)
    {
        auto ite = callbacks.find(signal);
        if (ite != callbacks.end())
        {
            auto& funcArray = ite->second;
        #if 0
            auto iteFunc = find(funcArray.begin(), funcArray.end(), func);
            if (iteFunc != funcArray.end())
            {
                funcArray.erase(iteFunc);
            }
        #else
            for (auto iteFunc = funcArray.begin(); iteFunc != funcArray.end(); iteFunc++)
            {
                if (func.target_type() == iteFunc->target_type())
                {
                    funcArray.erase(iteFunc);
                    return;
                }
            }
        #endif 
        }
    }

    void emit(const string& signal, void* data)
    {
        auto ite = callbacks.find(signal);
        if (ite != callbacks.end())
        {
            auto& funcArray = ite->second;
            for (auto& func : funcArray)
            {
                func(data);
            }
        }
        else
        {
            cout << "emit error" << endl;
            return;
        }
        
    }

private:
    map<string, FuncArray> callbacks; // 回调列表
};


void func1(void* data)
{
    cout << "网络初始化" << endl;
    Emit("network_init", nullptr);
}
void func2(void* arg)
{
    cout << "数据库初始化" << endl;
    Emit("database_init", nullptr);
}
void func3(void* arg)
{
    cout << "界面初始化" << endl;
    Emit("ui_init", nullptr);
}
void func4(void* arg)
{
    cout << "系统初始化成功" << endl;
}

int main()
{
    Connect("network_init", func2);
    Connect("database_init", func3);
    Connect("ui_init", func4);

    func1(nullptr);
    return 0;
}