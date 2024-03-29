#include <iostream>
#include <thread>
#include <future>

void print()
{
    std::cout << "Hello" << std::endl;
}

int main()
{
    auto f = std::async(print);
    return 0;
}
