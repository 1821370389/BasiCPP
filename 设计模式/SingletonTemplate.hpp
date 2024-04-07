#include <iostream>
#include <mutex>
#include <thread>


template <class T>
class Singleton
{
public:
    static T* getInstance()
    {
    std::lock_guard<std::mutex> lock(m);

        if (p == nullptr)
        {
            p = new T();
        }
        return p;
    }
    void Release()
    {
        delete p;
        p = nullptr;
    }

protected:
    Singleton()
    {
        std::cout << "Singleton" << std::endl;
    }
    static T* p;
    static std::mutex m;
};



template <class T>
T *Singleton<T>::p = nullptr;
template <class T>
std::mutex Singleton<T>::m;
std::mutex m;
