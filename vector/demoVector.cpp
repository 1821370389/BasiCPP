#include <iostream>
using namespace std;    // 命名空间
#include <vector>       // 动态数组库
#include <stdio.h>
#include <string.h>


#define BUFFER_SIZE 10
#define NAMESIZE 20

/* 结构体 */
typedef struct Stu_info
{
    int age;
    char name[NAMESIZE];
    char sex;
}Stu_info;


int main()
{
#if 0
    vector<int> myvector;//声明动态整形数组

    /* 放数据 */
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        //myvector.insert(myvector.end(), idx);
        myvector.push_back(idx);//尾插
    }
    /* 数组大小 */
    int size = myvector.size();
    printf("size = %d\n", size);
    myvector.insert(myvector.end(), BUFFER_SIZE);

    size = myvector.size();
    printf("size = %d\n", size);

    /* 打印数组 */
    for(int idx = 0; idx < size; idx++)
    {
        printf("%d ", myvector[idx]);
    }
    printf("\n");

#elif 0 
    Stu_info stu1,stu2,stu3;
    stu1.age = 10;
    strncpy(stu1.name, "zhangsan", sizeof(stu1.name) - 1);
    stu1.sex = 'M';
    stu2.age = 13;
    strncpy(stu2.name, "lisi", sizeof(stu2.name) - 1);
    stu2.sex = 'W';
    stu3.age = 18;
    strncpy(stu3.name, "wangwu", sizeof(stu3.name) - 1);
    stu3.sex = 'M';

    vector<Stu_info> myvector;
    myvector.push_back(stu1);
    myvector.push_back(stu2);
    myvector.push_back(stu3);
    int size = myvector.size();
    int capacity = myvector.capacity();
    printf("size = %d\n", size);
    printf("capacity = %d\n", capacity);
    for(int idx = 0; idx < size; idx++)
    {
        // 可替换为 myvector.at(idx)
        printf("age = %d,\tname = %s,\tsex = %c\n", myvector[idx].age, myvector[idx].name, myvector[idx].sex);
    }



#endif

    return 0;
}