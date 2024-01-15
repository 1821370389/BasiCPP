/* 最长回文串 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>

    /* 判断字符串是否是回文串 */
    bool isPalindrome(const string& s, int start, int end) 
    {
        while (start < end) 
        {
            if (s[start] != s[end]) 
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s) 
    {
        int maxLen = 1;
        int startIdx = 0;
        int len = s.size();

        for (int idx = 0; idx < len; idx++) 
        {
            for (int jdx = idx + maxLen; jdx < len; jdx++) 
            {
                if (isPalindrome(s, idx, jdx)) 
                {
                    startIdx = idx;
                    maxLen = jdx - idx + 1;
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }

int main()
{
    string s = "babad";
    string str = longestPalindrome(s);
    cout << str << endl;
    return 0;  // 主函数返回值为0，表示程序运行成功。
}
