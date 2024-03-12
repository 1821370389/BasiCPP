#include <iostream>
#include <queue>

/* 约瑟夫环 */
int& JosephRing(const int& n, const int& m)
{
    std::queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while(q.size() > 1)
    {
        for(int i = 1; i < m; i++)
        {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

int main()
{
    std::cout << JosephRing(31, 3) << std::endl;
    return 0;
}