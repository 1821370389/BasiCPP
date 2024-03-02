#include <iostream>

class Test
{
public:
    Test(int a, int b): m_a(a),b(b)     // 初始化列表
    {
    }

    void showInfo()
    {
        std::cout << m_a << std::endl;
    }

    const int* func()
    {
        return &b;
    }

    void func2(const int &a)
    {
    
    }

    void func3()const
    {
        
    }
private:
    const int m_a;
    int b;
};

int main()
{
    Test t(5,10);
    t.showInfo();
    const int *p = t.func();
    return 0;
}
