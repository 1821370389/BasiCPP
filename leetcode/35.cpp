/* 二产查找数组 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>


    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()  - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    /* 二分查找 */
    int binarySearch(vector<int>& nums, int target)
    {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

int main()
{
    vector<int> nums = {1,3,5,6};
    int target = 5;
    int res = searchInsert(nums, target);
    cout << res << endl;
    return 0;  // 主函数返回值为0，表示程序运行成功。
}
