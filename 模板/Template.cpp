/* 模板的概念 */
#include <iostream>
#include <cstring>
using namespace std;

/* 常量 */
const int default_value = 15;

/* 函数模板 */
template <typename T>
T add(T val1, T val2)
{
    return val1 + val2;
}

/* 类模板 */
template <class Item>
class Array
{
private:
    Item* m_data;
    int m_size;
    int m_capacity;
public:
    Array();
    Array(int capacity)
    {
        if(capacity <= 0)
        {
            capacity = default_value;
        }
        m_data = new Item[capacity];
        memset(m_data, 0, sizeof(Item) * capacity);
        m_capacity = capacity;
        m_size = 0;
    }
    ~Array();

    void add(Item value);
    void insert(int index, Item value);
    Item& get(int index);
    void remove(int index);
    int size();
    Item& operator[](int index);

    /* 模板类中的友元声明 */
    template <class T> friend ostream& operator<<(ostream& os, const Array<T>& arr);
};

/* 类模板外实现需要加上模板信息 */
template <class Item>
Array<Item>::Array():Array(default_value){};
template <class Item> Array<Item>::~Array()
{
    if (m_data)
    {
        delete[] m_data;
        m_data = NULL;
    }
    m_size = 0;
    m_capacity = 0;
}
template <class Item> void Array<Item>::add(Item value)
{
    /* 判断扩容 */
    if(this->m_size + 1 >= this->m_capacity)
    {
        this->m_capacity *= 2;
        Item* temp = new Item[this->m_capacity];
        memset(temp, 0, sizeof(Item) * this->m_capacity);
        for(int idx = 0; idx < this->m_size; idx++)
        {
            temp[idx] = this->m_data[idx];
        }
        delete[] this->m_data;
        this->m_data = temp;
    }
    this->m_data[m_size++] = value;
}
template <class Item> void Array<Item>::insert(int index, Item value)
{
    /* todo */
}
template <class Item> Item& Array<Item>::get(int index)
{
    if(index < 0 || index >= this->m_size)
    {
        return m_data[m_size];
    }
    return this->m_data[index];
}
template <class Item> Item& Array<Item>::operator[](int index)
{
    return get(index);
} 
template <class Item> ostream& operator<<(ostream& os, const Array<Item>& arr)
{
    os << "[" << arr.m_data[0];
    for(int idx = 1; idx < arr.m_size; idx++)
    {
        os << ", " << arr.m_data[idx];
    }
    os << "]";
    return os;
}

class Point
{
private:
    int m_x;
    int m_y;
public:
    Point(int x, int y) : m_x(x), m_y(y) {}
#if 0
    ostream& operator<<(ostream& os)
    {
        os << "(" << this->m_x << "," << this->m_y << ")";
        return os;
    }
#else
    /* 为什么重载<<要用友元 */
    friend ostream& operator<<(ostream& os, const Point& p);
#endif
    Point operator+(const Point& p);
};
ostream& operator<<(ostream& os, const Point& p)
{
    os << "(" << p.m_x << ", " << p.m_y << ")";
    return os;
}
Point Point::operator+(const Point& p)
{
    return Point(m_x + p.m_x, m_y + p.m_y);
}

int main()
{
#if 0
    int num1 = 10, num2 = 20;
    double d1 = 1.1, d2 = 2.2;
    cout << add<int>(num1, num2) << endl;
    cout << add<double>(d1, d2) << endl;
    float f1 = 1.1, f2 = 2.2;
    cout << add<float>(f1, f2) << endl;
    Point p1(1, 2), p2(3, 4);
#if 0
    add(p1,p2) << cout << endl;
#else
    cout << add<Point>(p1, p2) << endl;
#endif
#endif
    Array<int> arr;
    arr.add(11);
    arr.add(22);
    arr.add(33);
    cout << arr[0] << endl;
    cout << arr << endl;
    return 0;
}