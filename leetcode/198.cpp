/* 打家劫舍 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>

/* 
    分析：
    只有一个房子时直接返回
    只有两个房子时返回最大值
    有三个房子时比较1+3和2谁大
    有四个房子时比较1+4和2+3和1+3和2+4谁大
    有五个房子时比较1+3+5和2+4和1+4和2+5 
*/

    int rob(vector<int>& nums) 
    {
        /* 题目表明不存在空数组 所以不判空了 */
        int size = nums.size();
        vector<int> dp(size+1,0);
        if(size == 1)
        {
            return nums[0];
        }
        if(size == 2)
        {
            return max(nums[0],nums[1]);
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i < size;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[size-1];
        
    }

int main()
{

    return 0;  // 主函数返回值为0，表示程序运行成功。
}
