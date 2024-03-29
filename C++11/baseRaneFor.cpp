#include <iostream>
#include <vector>
#include <map>

int main()
{
#if 0
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto &i : v)
    {
        i *= 2;
    }
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
#else
    std::map<int, int> m = {{1, 2}, {2, 3}, {3, 4}};

    for (auto i : m)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }
#endif 
    return 0;
}
