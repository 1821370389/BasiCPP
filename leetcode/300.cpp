/* 最长递增子序列 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>

    int lengthOfLIS(vector<int>& nums) 
    {
        int size = nums.size();
        if(size == 0)return 0;
        int dp[size];
        int maxnnum = 1;
        dp[0] = 1;
        for(int i = 1;i < size;i++)
        {
            dp[i] = 1;
            for(int j = 0;j < i;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                    // cout<<i <<":"<<j<<":"<<dp[i]<<endl;
                    if(dp[i] > maxnnum)
                    {
                        maxnnum = dp[i];
                    }
                }
            }
        }
        return maxnnum;


    }

int main()
{

    return 0;  // 主函数返回值为0，表示程序运行成功。
}
