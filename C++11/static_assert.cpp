#include <iostream>

/* 关键词(判断条件，"不满足时抛出错误原因")*/
static_assert(sizeof(void*) == 4, "改代码编译在32机上");


int main()
{
    return 0;
}