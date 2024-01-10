/* 最大重复字符串 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>


int maxRepeating(string sequence, string word);

int main()
{
    string sequence = "aaaaaa", word = "aa";
    maxRepeating(sequence, word);
}

int maxRepeating(string sequence, string word) 
{
    int count = 0;
    if(sequence.size() < word.size())
    {
        return count;
    }
    int max = 0;        // 记录最大次数
    int index = -1;      // 记录上一个串的起点
    int count_temp = 0; // 记录当前串的次数
    for(int idx = 0; idx < sequence.size(); idx++)
    {
        int jdx = 0;
        while(sequence[idx + jdx] == word[jdx] && (idx + jdx) < sequence.size() && jdx < word.size())
        {
            jdx++;
        }
        if(jdx == word.size())
        {
            printf("idx = %d, jdx = %d\n", idx, jdx);
            printf("index = %d, count = %d\n", index, count_temp);
            count_temp++;
            if(index == -1 || idx == index + jdx || idx == index)
            {
                if(index == -1)
                {
                    count_temp = 1; // 重置次数
                }
                index = idx; // 记录第一次匹配到的位置
                idx += jdx -1; // 跳过匹配到的串
            }
            else// 说明匹配到的与上一子串不连续
            {
                count_temp = 1; // 重置次数
                idx = index + 1; // 重置起点
                index = -1; // 重置起点标记
            }
            if(count_temp > max)
            {
                max = count_temp;
            }
        }
    }
        printf("max = %d\n", max);

    return max;
}