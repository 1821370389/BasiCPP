#include <iostream>
#include <stack>

int main()
{
    std::stack<int> s;
    for(int idx = 0; idx <= 10; idx++)
    {
        s.push(idx);
    }

    while(!s.empty())
    {
        std::cout << s.top() << std::endl;  // top()的返回值是引用,所以top后最好拿变量接一下,直接pop有风险，如果你之后会用到这个值的话
        s.pop();
    }
    
    return 0;
}