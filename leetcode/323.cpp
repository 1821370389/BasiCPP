/* 零钱兑换 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>


#if 0
    int coinChange(vector<int>& coins, int amount) 
    {
        int size = coins.size();
        int MAX = amount + 1;
        if(size == 0)
        {
            return -1;
        }
        vector<int> dp(MAX,MAX);
        dp[0] = 0;
        for(int idx = 1; idx < MAX; idx++)
        {
            for(int jdx = 0; jdx < size; jdx++)
            {
                if(coins[jdx] <= idx)
                {
                    dp[idx] = min(dp[idx],dp[idx-coins[jdx]]);
                }
            }
        }
        return dp[amount] > MAX ? -1 : dp[amount];
    }
#endif
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1,amount + 1);
        dp[0] = 0;
        int minNum = 0;
        for(int idx = 1; idx < amount + 1; idx++)
        {
            minNum = amount + 1;
            for(int& jdx : coins)
            {
                if(jdx <= idx)
                {
                    minNum = min(minNum,dp[idx - jdx] + 1);
                }
            }
            dp[idx] = minNum;
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }


int main()
{
    vector<int> coins = {186,419,83,408};
    int amount = 6249;
    int result = coinChange(coins, amount);
    cout << result << endl;

    return 0;  // 主函数返回值为0，表示程序运行成功。
}
