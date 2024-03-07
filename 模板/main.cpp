#include <iostream>
#include "myAdd.hpp"
using namespace std;

int main()
{
    /* 汇编在链接之前 ， _zSmyAddiet_S0_S0_@PlT是有个随机值
        知道链接完成后，才会更新这个值 */
    cout << myAdd<int>(1,2) << endl;
    return 0;
}