#include <iostream>
using namespace std;
#include <set>

int main()
{
    set<int> myset;

    /* 插入数据 */
    /* 集合的特性：去重*/
    myset.insert(10);
    myset.insert(10);
    myset.insert(20);
    myset.insert(20);
    myset.insert(30);
    myset.insert(30);

    /* 获取集合大小 */
    printf("set size = %d\n", (int)myset.size());

    /* 判断特定元素是否存在于集合中 */
    printf("is 10 exist? %d\n", (int)myset.count(10));
    printf("is 40 exist? %d\n", (int)myset.count(40));

    return 0;
}