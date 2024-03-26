#include <iostream>
#include <functional>
#include <set>

#if 0
bool func(int num)
{
    return num > 3; 
}

int Count(int *num, int size, bool (*func)(int))
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (func(num[i]))
        {
            count++;
        }
    }
    return count;
}

#else
class Func
{
private:
    int n;
public:
    Func(int n) : n(n){}
    bool operator()(int num)
    {
        return num > 3 && num%n;
    }
};

int Count(int *num, int size, Func func)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (func(num[i]))
        {
            count++;
        }
    }
    return count;
}

#endif 

int main()
{
    int n[] = {1, 2, 3, 4, 5, 6};
    // std::cout << Count(n, 6, Func(5)) << std::endl;
    // std::cout << std::equal_to<int>()(5, 6) << std::endl;
    std::set<int,std::greater<int>> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for (auto i : s)
    {
        std::cout << i << std::endl;
    }
	return 0;
}