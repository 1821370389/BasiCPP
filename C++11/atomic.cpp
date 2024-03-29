#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

using namespace std;
mutex m;

atomic<int> count = 0;
int  count = 0;
void add()
{
    // lock_guard<mutex> lock(m);
    for (int i = 0; i < 1000000; i++)
    {
        count++;
    }
}

int main()
{
    auto start = chrono::steady_clock::now();
    std::thread t1(add);
    std::thread t2(add);

    t1.join();
    t2.join();
    
    auto end = chrono::steady_clock::now();
    // auto time = end - start;
    auto time = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "time: " << time.count() << "ms" << endl;

    std::cout << count << std::endl;
    
    return 0;
}