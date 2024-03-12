#include <iostream>
#include <deque>

template <typename T>
void printDeque(std::deque<T> d)
{
    std::cout << "size: " << d.size() << std::endl;
    for (auto i : d)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);    // 头插
    d.push_front(4);

    printDeque(d);

    return 0;
}