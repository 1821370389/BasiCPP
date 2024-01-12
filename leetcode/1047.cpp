/* 删除字符串中的所有相邻重复项 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>

#if 0
    string removeDuplicates(string s) 
    {
        stack<char> st1;
        stack<char> st2;
        for(int idx = 0; idx < s.size(); idx++)
        {
            st1.push(s[idx]);
        }
        while(!st1.empty())
        {
            if(st2.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            else
            {
                if(st1.top() == st2.top())
                {
                    st2.pop();
                    st1.pop();
                    continue;
                }
                else
                {
                    st2.push(st1.top());
                    st1.pop();
                    continue;
                }
            }
        }
        string str;
        while(!st2.empty())
        {
            str += st2.top();
            st2.pop();
        }
        return str;
    }
#endif

    string removeDuplicates(string s) 
    {
        int pop = 0;
        while(pop < s.size() - 1 && s.size() > 1)
        {
            cout << "pop = " << s[pop] << " pos = " << s[pop+1] << endl;
            if(s[pop] == s[pop+1])
            {
                s.erase(pop, 2);
                if(pop > 0)
                {
                    pop--;
                }
                continue;
            }
            pop++;
        }
        return s;
    }

int main()
{
    string str = "abbaca";
    string str1 = removeDuplicates(str);
    cout << str1 << endl;

    
    return 0;
}