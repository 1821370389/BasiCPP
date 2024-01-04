#include <iostream>
using namespace std;    // 命名空间
#include <stdio.h>
#include <string>
#include <stack>    // 栈库

#define BUFFER_SIZE 6

/* 判断括号是否有效 */
bool isValid(string s)
{
#if 1
    stack<char> stack;
    int len = s.size();
    for(int idx = 0; idx < len; idx++)
    {
        if(s[idx] == '(' || s[idx] == '[' || s[idx] == '{')
        {
            stack.push(s[idx]);
            continue;
        }
        if(stack.empty())return false;
        char temp = stack.top();
        if(s[idx] == ')' && temp == '(' ||
            s[idx] == ']' && temp == '[' ||
            s[idx] == '}' && temp == '{')
        {
            stack.pop();
            continue;
        }
        return false;
    }
    return stack.empty();
#else
    stack<char> stack1,stack2;  // 创建两个栈
    // int len = strlen(str);      //  获取字符串长度
    int count = 0;              //  计数器
    for(int i = 0; i < str.size(); i++)
    {
        stack1.push(str[i]);    //  将字符串中的字符入栈
    }

    char temp1 = 0, temp2 = 0;  // 定义两个记录栈顶的变量
    while(!stack1.empty())      // 栈1不为空时，循环执行下面的操作
    {
        count++;                // 记录检测次数
        temp1 = stack1.top();   //  获取栈1顶元素
        stack1.pop();
        if(stack2.empty())      // 栈2为空时，直接入栈2，并且跳过此次循环
        {
            stack2.push(temp1);
            if(temp1 == '(' || temp1 == '[' || temp1 == '{')break;  // 若入栈的是左括号，则直接跳出循环
            continue;
        }
        temp2 = stack2.top();
        if(temp1 == '(' && temp2 == ')' ||
            temp1 == '[' && temp2 == ']' ||
            temp1 == '{' && temp2 == '}')   // 判断两个元素是否匹配,匹配跳过当前循环,不匹配栈1元素入栈2
        {
            stack2.pop();
            continue;
        }
        stack2.push(temp1);
        if(temp1 == '(' || temp1 == '[' || temp1 == '{')break;  // 同上
    }
    printf("count = %d\n",count);
    return stack2.empty();
#endif
}
int main()
{
   string str = {'(','[',')',']','{','}'};
    if(isValid(str))
    {
        printf("括号有效\n");
    }
    else
    {
        printf("括号无效\n");
    }
    return 0;
}