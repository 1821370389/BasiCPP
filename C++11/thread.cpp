#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex m;
std::condition_variable cv;

int flag = 0;

void print(int a)
{
#if 0
    m.lock();
    std::cout << "ID:" << a << std::endl;
    m.unlock();
#elif 0
    /* 自动释放 */
    std::lock_guard<std::mutex> lock(m);
    std::cout << "ID:" << a << std::endl;
#else
    /* 更加灵活,能够手动加减锁,但会消耗更多的资源 */
    std::unique_lock<std::mutex> lock(m);
    std::cout << "ID:" << a << std::endl;
    lock.unlock();
#endif
    
}

void print2(int a)
{
    #if 0
    /* 轮询 */
    while(flag != 1)
    {
        usleep(1000);
    }
    #else
    /* 条件变量 */
    cv.wait(m, [](){return flag == 1;});
}


int main()
{
    // std::thread t([](){
    //     std::cout << "Hello from thread" << std::endl;
    // });
    
    // std::thread t(print);
/*
    std::thread t;
    t = std::thread(print,3);
    // t.join();
    t.detach();
    std::thread t2([]()
    {
        int i = 100;
        while (i != 0)
        {
            i--;
        }
    });
    
    std::cout << "pid:" << t.get_id() << std::endl;
    std::cout << "pid:" << t2.get_id() << std::endl;
    t2.join();
    std::cout << std::thread::hardware_concurrency() << std::endl;  // 剩余可用核数
*/
    std::thread t[10];
    int i = 0;
    for (auto &t : t)
    {
        t = std::thread(print, ++i);
    }
    for (auto &t : t)
    {
        t.join();
    }
    return 0;
}