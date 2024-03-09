/*
给你两个正整数：n 和 target 。

如果数组 nums 满足下述条件，则称其为 美丽数组 。

nums.length == n.
nums 由两两互不相同的正整数组成。
在范围 [0, n-1] 内，不存在 两个 不同 下标 i 和 j ，使得 nums[i] + nums[j] == target 。
返回符合条件的美丽数组所可能具备的 最小 和，并对结果进行取模 10^9 + 7。
*/
/* 
1.1.1
1.2.1
2.1.3
2.2.3
2.3.4
2.4.3
3.3.8
3.4.7
3.5.8
3.6.6*/
#include <iostream>

using namespace std;

int minimumPossibleSum(int n, int target) 
{
    if(target>>1 >= n)
    {
        return n*(n+1)/2;
    }
    else
    {
        int m = target >> 1 ;
        int sum = m * (m + 1) >> 1;
        sum += (n - m) * (target * 2 + n -m -1) >> 1;
        return sum;
    }

}

int main()
{
    cout << minimumPossibleSum(3,5) << endl;
    return 0;
}