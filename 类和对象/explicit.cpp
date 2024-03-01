#include <iostream>

class Interger
{
private:
    int m_a;
public:
    explicit Interger(int a);
    Interger();
    ~Interger();
    int getInterger();
};

Interger::Interger(int a)
{
    std::cout << "带参构造" << std::endl;
    m_a = a;
}
Interger::Interger()
{
    std::cout << "无参构造" << std::endl;
    m_a = 20;
}

Interger::~Interger()
{
    std::cout << "析构函数" << std::endl;
}

int Interger::getInterger()
{
    return m_a;
}


int main()
{
#if 0
    Interger i(10);
    // 构造函数的隐式转换: 数值会被隐式构造成类的对象
    i = 30;
    std::cout << i.getInterger() << std::endl;
#endif
    Interger i(10);
    // 构造函数的隐式转换: 数值会被隐式构造成类的对象
    // i = 30;     // 加 explicit 关键词解决问题
    std::cout << i.getInterger() << std::endl;
	return 0;
}