#include <iostream>
#include <forward_list>

template <typename T>
void print(const T& t)
{
    for(const auto& e : t)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::forward_list<int> fl;
    fl.assign({1, 2, 3});   
    fl.push_front(0);   // 头插,单链表没有尾插
    auto ite = fl.begin();
    print(fl);
    return 0;
}