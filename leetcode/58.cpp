/* 获取最后字符串的长度 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <regex>


    int lengthOfLastWord(string s) 
    {
        char *p = (char *)s.c_str();
        while(*p != '\0')
        {
            p++;
        }
        int count = 0;
        while(*p == ' ' || p == '\0')
        {
            p--;
        }
        while(*p != ' ' && *p != '\0')
        {
            p--;
            count++;
        }
        return count;

    }

int main()
{

    return 0;  // 主函数返回值为0，表示程序运行成功。
}
