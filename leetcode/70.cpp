/* 爬楼梯 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>

    int climbStairs(int n) 
    {
        int count = 0;
        int a = 1;
        int b = 2;
        if(n == 1)
        {
            return a;
        }
        if(n == 2)
        {
            return b;
        }
        for(int i = 3;i <= n;i++)
        {
            count = a + b;
            a = b;
            b = count;
        }
        return count;

    }

int main()
{
    int n = 5;
    int result = climbStairs(n);
    cout << result << endl;
    return 0;  // 主函数返回值为0，表示程序运行成功。
}
