#include <iostream>
#include <set>


template <typename T>
void print(const T& t)
{
    for (const auto& e : t)
        std::cout << e << " ";
    std::cout << std::endl;
}

int main()
{
    std::set<int> s{5,9,3,2,4};
    print(s);
    s.insert(1);
    print(s);
    s.insert(3);    // 排序容器会自动去重
    print(s);
    s.erase(1);     // 删除
    print(s);
    auto ite = s.find(10);
    std::cout << *ite << std::endl;
    if (s.count(10))
        std::cout << "find 10" << std::endl;
    std::multiset<int> ms{5,9,3,2,4};
    print(ms);
    ms.insert(3);       // 允许插入重复值
    print(ms);
    return 0;
}