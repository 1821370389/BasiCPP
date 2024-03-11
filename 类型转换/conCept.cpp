/* io流 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>      //setw() 
#include <unistd.h>     //sleep()

using namespace std;

#if 0
int main()
{
    int num1 = 123;
    cout << "设置域宽" << endl;
    cout.width(10);
    cout << num1 << endl;
    cout << setw(5) << num1 << endl;
    cout << "1234567890123456789" << endl;
    cout << "hello" << endl;

    
    return 0;
}
#endif 


int main()
{
    /* 使用构造方式打开文件 */
    #if 0
    // ofstream ofs("test.txt");    // 默认是ios::out | iso::trunc
    ofstream ofs("test.txt", ios::out | ios::app);  // 追加
    if (!ofs.is_open())
    {
        cout << "open file error" << endl;
        return 0;
    }
    ofs << "Hello" << endl;
    ofs << "World!" << endl;
    ofs.close();

    ifstream ifs("test.txt");       // 默认是ios::in
    if (!ifs.is_open())
    {
        cout << "open file error" << endl;
        return 0;
    }
    string str;
    ifs >> str;     // 流输入
    cout << str << endl;
    while (getline(ifs, str))       // 从ifs中读一行到str
    {
        sleep(1);
        cout << str << endl;
    }
    ifs.close();
    #endif
    /* 以open成员函数打开 */
    #if 0
    ifstream ifs;
    ifs.open("test.txt");
    if (!ifs.is_open())
    {
        cout << "open file error" << endl;
        return 0;
    }
    string str;
    while (getline(ifs, str))
    {
        cout << str << endl;
    }
    ifs.close();
    #endif
    return 0;
}