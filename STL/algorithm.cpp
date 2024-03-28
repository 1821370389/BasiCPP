#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <forward_list>
#include <numeric>
using namespace std;

void print(int i)
{
    cout << i << " ";
}
class FuncPrint
{
public:
    void operator()(int i)
    {
        cout << i << " ";
    }
};

struct Node
{
    int data;
    Node* next;
};

/* 单链逆序 递归 */
Node* Reverse(Node* n)
{
    if (n->next == NULL)
    {
        return n;
    }
    Node* tall =  Reverse(n->next);
    n->next->next = n;
    n->next = NULL;
    return tall;
}

int main() 
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 3, 3, 8, 9};
    /* 非变动算法 */
#if 0
    /* 遍历 */
    #if 0
    for_each(v.begin(), v.end(), [](int i) { cout << i << " "; });      // 匿名函数
    #elif 0
    for_each(v.begin(), v.end(), print);                                // 回调函数
    #elif 0
    FuncPrint f;
    for_each(v.begin(), v.end(), f);                                    // 仿函数
    #endif

    /* 返回一个值出现的次数 */
    // cout << count(v.begin(), v.end(), 3);

    /* 如果满足就结束 */
    // cout << count_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; });

    /* 返回最大最小值的索引 */
    // cout << *max_element(v.begin(), v.end());
    // cout << *min_element(v.begin(), v.end());

    /* 搜索每个容器中一个等于n的元素*/
    // cout << *find(v.begin(), v.end(), 3);
    /* 返回第一个满足条件的元素 */
    // cout << *find_if(v.begin(), v.end(), [](int i) { return i > 3 && i%2 == 0;});

    /* 寻找区间内连续的a个b，并返回第一个元素的，没有返回尾指针 */
    // cout << * search_n(v.begin(), v.end(), 2, 3);

    /* 找一个区间在另一个区间首次出现的维护者 ， 没有返回nullptr */
    // vector<int> v2 = {5,8,3};
    // cout << *search(v.begin(), v.end(), v2.begin(), v2.end());

    /* 搜索子区间最后一次出现的位置 */
    // vector<int> v2 = {3};
    // cout << distance(v.begin(), find_end(v.begin(), v.end(), v2.begin(), v2.end()));

    /* 在一个区间里找第一个存在于第二个区间中的元素 */
    // vector<int> v2 = {6, 2, 3};
    // cout << *find_first_of(v.begin(), v.end(), v2.begin(), v2.end());

    /* 查找相邻的两个相同元素， 返回其迭代器 */
    // cout << distance(v.begin(), adjacent_find(v.begin(), v.end()));

    /* 判断两区间是否相等 */
    // vector<int> v2 = {1, 2, 3};
    // cout << (equal(v.begin(), v.end(), v2.begin()) ? "true" : "false");

    /* 返回两个区间不相等的位置 */
    string s1 = "hello";
    string s2 = "hellw";
    auto pair = mismatch(s1.begin(), s1.end(), s2.begin(), s2.end());
    cout << *pair.first << " " << *pair.second;

    cout << endl;
#endif

    /* 变动算法 */
#if 0
    /* 传引用就能改值了 */
    // for_each(v.begin(), v.end(), [](int &num){num++;cout << num << " ";});

    list<int> l;
    l.resize(v.size());
    /* 复制 */
    // copy(v.begin(), v.end(), l.begin());
    // for_each(l.begin(), l.end(), print);

    /* 反向复制 从结尾往前复制，结果依旧是正序 */
    // copy_backward(v.begin(), v.end(), l.end());
    // for_each(l.begin(), l.end(), print);

    /* 变动元素 */
    // transform(v.begin(), v.end(), l.begin(), [](int i) { return i * i; });
    // for_each(l.begin(), l.end(), print);

    /* 合并 */
    // vector<int> v2 = {1, 2, 3, 4, 5};
    // vector<int> v3;
    // v3.resize(v.size() + v2.size());
    // merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
    // for_each(v3.begin(), v3.end(), print);

    /* 两个区间交换 */
    // vector<int> v2 = {3,8,9};
    // v2.resize(v.size()); //  请确保两个区间一样大
    // swap_ranges(v.begin(), v.end(), v2.begin());
    // for_each(v.begin(), v.end(),  print);
    // cout << endl;
    // for_each(v2.begin(), v2.end(), print);

    /* 填充 */
    // fill(v.begin(), v.end(), 1);
    // for_each(v.begin(), v.end(), print);
    // cout << endl;
    // fill_n(v.begin(), 2, 3);    // 填充指定个数
    // for_each(v.begin(), v.end(), print); 

    /* 变动元素 */
    // generate(v.begin(), v.end(), [](){return rand()%10;});  // 与transform不同，这个是修改后塞回原容器
    // for_each(v.begin(), v.end(), print);
    // cout << endl;
    // generate_n(v.begin(), 2, [](){return rand()%10;});      // 同上， 修改前n个元素
    // for_each(v.begin(), v.end(), print);

    /* 替换特定元素 */
    // replace(v.begin(), v.end(), 3, 0);  // 3换成0
    // for_each(v.begin(), v.end(), print);
    // cout << endl;
    // replace_if(v.begin(), v.end(), [](int i){return i%2 == 0;}, 81); // 自定义条件
    // for_each(v.begin(), v.end(), print);

    /* 替换区间 */
    // vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // replace_copy(v.begin(), v.end(), v2.begin(), 0);
    // for_each(v.begin(), v.end(), print);
    // cout << endl;
    // replace_copy_if(v.begin(), v.end(), v2.begin(), [](int i){return i%2 == 0;}, 81);
    // for_each(v.begin(), v.end(), print);
    cout << endl;
#endif

    /* 移除性算法 */
#if 0
    /* 将等于某值的全部元素移除 */
    // remove(v.begin(), v.end(), 3);  // 后面的全部前移，数组大小不变
    // for_each(v.begin(), v.end(), print);

    // remove_if(v.begin(), v.end(), [](int i){return i > 3;});
    // for_each(v.begin(), v.end(), print);

    /* 去重 */
    // unique(v.begin(), v.end());
    // for_each(v.begin(), v.end(), print);
    // vector<int> v2;
    // v2.resize(v.size());
    // unique_copy(v.begin(), v.end(), v2.begin());
    // for_each(v2.begin(), v2.end(), print);

    cout << endl;
#endif

    /* 变序性算法 */
#if 0
    /* 逆序 */
    // reverse(v.begin(), v.end());     // forward_list，没有--迭代器，不能逆序

    /* 旋转 */
    // rotate(v.begin(), v.begin() + 3, v.end());

    /* 下一个排列  用于遍历全排列*/
    // vector<int> v2 = {1, 2, 3, 5};
    // do{
    //     for(int num : v2)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }while(next_permutation(v2.begin(), v2.end()));

    /* 随机打乱数组 */
    // srand(time(NULL));  // 生成随机种子
    // random_shuffle(v.begin(), v.end());

    /* 分组函数 把符合要求的数据放到前面 */
    // partition(v.begin(), v.end(), [](int i){return i == 3;}); 
    // stable_partition(v.begin(), v.end(), [](int i){return i%2 == 0;});  // 保持相对位置不变的分组算法


    for_each(v.begin(), v.end(), print);
    cout << endl;
#endif

    /* 排序性算法 */
#if 0
    srand(time(NULL));  // 生成随机种子
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), print);
    cout << endl;

    /* 排序 
    1. 数量不超过16. 使用插入排序
    2. 超过16，递归深度没到0 快速排序
    3. 递归深度到0， 堆排序*/
    // sort(v.begin(), v.end());

    /* 稳定的排序  */
    // stable_sort(v.begin(), v.end());

    /* 部分排序 */
    // partial_sort(v.begin(), v.begin() + 3, v.end());
    nth_element(v.begin(), v.begin() + 3, v.end());     // 只排序第n个


    for_each(v.begin(), v.end(), print);
    cout << endl;
#endif

    /* 已序区间 */
#if 0
    /* 二分查找 */
    // cout << binary_search(v.begin(), v.end(), 3) << endl;

    /* 一个区间是否包含在另一个区间内 */
    // vector<int> v2 = {3, 4, 5};
    // cout << includes(v.begin(), v.end(), v2.begin(), v2.end()) << endl;

    /* */
    // cout << *lower_bound(v.begin(), v.end(), 4) << endl;    // 返回第一个大于等于n的数的指针
    // cout << *upper_bound(v.begin(), v.end(), 4) << endl;    // 返回第一个大于的数的指针

    /* todo?? */
    // auto pair = equal_range(v.begin(), v.end(), 6);
    // cout << distance(v.begin(),pair.first)  << " " << distance(v.begin(), pair.second) << endl;

    /* 并集 */
    sort(v.begin(), v.end());
    vector<int> v2 = {3, 4, 5, 6, 10};
    vector<int> v3(13);
    // set_union(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());

    /* 交集 */
    // set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());

    /* 补集 */
    // set_difference(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());

    /* 对称差集 (并集减交集) */
    // set_symmetric_difference(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());

    // inplace_merge(v.begin(), v.begin() + 3, v.end());
    for_each(v.begin(), v.end(), print);
    for_each(v3.begin(), v3.end(), print);
    cout << endl;

#endif

    /* 数值算法 */
#if 1
    /* 最大/小值 */
    // cout << *max_element(v.begin(), v.end()) << endl;
    // cout << *min_element(v.begin(), v.end()) << endl;

    /* 求和 */
    // int sum = 0;
    // cout << accumulate(v.begin(), v.end(), sum) << endl;     // sum是其他计算的和
    // cout << "sum:" << sum << endl;
    // string str = " world";
    // string str2 = "hello";
    // cout << accumulate(str.begin(), str.end(), str2) << endl;   // 字符串拼接

    /* 组合 */
    // vector<int> v1 = {1, 2};
    // vector<int> v2 = {4, 5, 6};
    // cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0) << endl; // 对于位置相乘，结果相加

#endif

    // auto ite = v.begin();    // 避免迭代器失效，不要这么写
    /*
    for(auto ite = v.begin(); ite != v.end();)
    {
        if(*ite == 3)
        {
            v.erase(ite);
        }
        else
        {
            ite++;
        }
    }*/
    for_each(v.begin(), v.end(), print);
    cout << endl;
    return 0;
}
int Binary_search(vector<int> &v, const int value)
{
    int low = 0;
    int high = v.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == value)
        {
            return mid;
        }
        else if (v[mid] > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}