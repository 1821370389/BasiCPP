/* 字母去重后排序 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <regex>

    string removeDuplicateLetters(string s) 
    {
        string str ;
        for(int idx = 0; idx < s.size(); idx++)
        {
            if(str.find(s[idx]) != -1)
            {
                continue;
            }
            while(!str.empty() && s[idx] < str.back() && s.find(str.back(), idx) != -1)
            {
                str.pop_back();
            }
            str.push_back(s[idx]);
        }
        return str;

    }

int main()
{
    string s = "cbacdcbc";
    cout << removeDuplicateLetters(s) << endl;

    return 0;  // 主函数返回值为0，表示程序运行成功。
}
