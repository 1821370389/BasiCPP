#include <iostream>
using namespace std;    // 命名空间
#include <map>
#include <string.h>

#define BUFFER_SIZE 20

/* 定义结构体 */
typedef struct stuInfo
{
    int age;
    char sex;
    char address[BUFFER_SIZE];
}stuInfo;

int main()
{
    map<int, int> mymap;

    mymap[7] = 668;

    printf("%d\n", mymap[7]);

    stuInfo stu;
    stu.age = 18;
    stu.sex = 'f';


    map<string, stuInfo> mymap2;
    mymap2["xiaoming"] = stu;
    printf("xiaoming age:%d, sex:%c\n", mymap2["xiaoming"].age, mymap2["xiaoming"].sex);

    strncpy(stu.address, "beijing", sizeof(stu.address));

    return 0;

}