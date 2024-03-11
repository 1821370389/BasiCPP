/* 文件拷贝 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in;
    ofstream out;
    cout << "argc = " << argc << endl;
    in.open(argv[1], ios::binary  | ios::in);
    out.open(argv[2], ios::binary | ios::out);
    if (in.is_open() && out.is_open())
    {
        char ch;
        while (in.get(ch))
        {
            out.put(ch);
        }
        in.close();
        out.close();
    }
    return 0;
}
