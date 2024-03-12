#include <iostream>
#include <list>

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
    std::list<int> list{1,2,3,4,5};
    std::cout << list.size() << std::endl;
    print(list);

    auto ite = list.begin();
    for (int i = 0; i < 3; i++)
    {
        ite++;
    }
    ite--;
    list.insert(ite, 0);
    print(list);
    list.reverse();
    return 0;
}