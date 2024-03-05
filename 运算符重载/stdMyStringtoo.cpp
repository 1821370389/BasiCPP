#include "stdMyStringtoo.hpp"
#include <cstring>


/* 无参构造 */
stdMyString::stdMyString()
{
    this->str = new char[15];
    this->size = 0;
    this->capacity = 15;
}
/* 带参构造 */
stdMyString::stdMyString(const char *str)
{
    this->str = new char[strlen(str) + 1];
    this->size = strlen(str);
    this->capacity = strlen(str) + 1;
    strncpy(this->str, str, this->size);
}
/* 复制构造 */
stdMyString::stdMyString(const stdMyString& str)
{
    this->str = new char[str.size];
    memset(this->str, 0, str.size);
    this->size = str.size;
    this->capacity = str.capacity;
    strncpy(this->str, str.str, this->size);
}
/* 析构函数 */
stdMyString::~stdMyString()
{
    delete[] this->str;
    this->str = nullptr;
    this->size = 0;
    this->capacity = 0;
}
/* 外部获取字符串大小 */
int stdMyString::Size()
{
    return this->size;
}
/* 重载运算符 */
std::ostream& operator<<(std::ostream& os, const stdMyString& str)
{
    os << str.str;
    return os;
}
std::istream& operator>>(std::istream& in, const stdMyString& str)
{
    /* todo */
}
stdMyString& stdMyString::operator+(const stdMyString& str)
{
    this->size += str.size;
    if(this->size >= this->capacity)                //  判断是否扩容
    {
        this->capacity = this->size + 1;
        char* temp = new char[this->capacity];
        memset(temp, 0, this->capacity);
        strncpy(temp, this->str, this->capacity);
        delete[] this->str;
        this->str = temp;
    }
    strncat(this->str, str.str, str.size);
    return *this;
}
stdMyString stdMyString::operator-(const stdMyString& str)
{
    char* temp = strstr(this->str, str.str);        // 返回第一个匹配的字符串的位置
    while(temp != nullptr)
    {
        char* backs = temp + str.size;              // 跳过要删除的字符串
        while(*backs != '\0')
        {
            *temp++ = *backs++;                     // 覆盖
        }
        *temp = '\0';
        temp = strstr(this->str, str.str);          // 更新要删除的位置
        this->size -= str.size;
        this->capacity = this->size >=15 ? this->size+1 : 15;
    }
    return *this;
}
stdMyString& stdMyString::operator=(const stdMyString& str)
{
    this->size = str.size;
    this->capacity = str.capacity;
    delete[] this->str;
    this->str = new char[this->capacity];
    memset(this->str, 0, this->capacity);
    strncpy(this->str, str.str, this->capacity);
    return *this;
}
stdMyString& stdMyString::operator+=(const stdMyString& str)
{
    *this = *this + str;
    return *this;
}
stdMyString& stdMyString::operator+=(const char c)
{
    if( this->size + 1 >= this->capacity)
    {
        this->capacity *= 2;
        char* temp = new char[this->capacity];
        memset(temp, 0, this->capacity);
        strncpy(temp, this->str, this->size);
        delete[] this->str;
        this->str = temp;
    }
    this->str[this->size++] = c;
    this->str[this->size] = '\0';
    return *this;
}

/* 重载[] */
char& stdMyString::operator[](int index)
{
    return this->str[index];
}

/* 重载强转 */
stdMyString::operator int()
{
    return atoi(this->str);
}
stdMyString::operator double()
{
    return atof(this->str);
}

/* 重载逻辑运算符 */
bool stdMyString::operator==(const stdMyString& str)
{
    return strcmp(this->str, str.str) == 0;
}
bool stdMyString::operator!=(const stdMyString& str)
{
    return strcmp(this->str, str.str) != 0;
}
bool stdMyString::operator>(const stdMyString& str)
{
    return strcmp(this->str, str.str) > 0;
}
bool stdMyString::operator<(const stdMyString& str)
{
    return strcmp(this->str, str.str) < 0;
}

/* 切割特定字符串 */
MyStringList stdMyString::split(const char* str)
{
    MyStringList list;
    stdMyString tempStr(*this);
    char* temp = strtok(tempStr.str, str);
    while(temp != nullptr)
    {
        list += temp;
        temp = strtok(nullptr, str);
    }
    return list;
}

/* 字符串数组 */
/* 构造函数 */
MyStringList::MyStringList()
{
    this->size = 0;
    this->capacity = 15;
    this->str = new stdMyString[this->capacity];
}
/* 析构函数*/
MyStringList::~MyStringList()
{
    delete[] this->str;
    this->str = nullptr;
    this->size = 0;
    this->capacity = 0;
}
/* 删除指定位置的字符串 */
void MyStringList::removeByIndex(int index)
{
    if(index < 0 || index >= this->size)
    {
        return;
    }
    for(int idx = index; idx < this->size - 1; idx++)
    {
        this->str[idx] = this->str[idx + 1];
    }
    this->size--;
}
/* 获取数组的大小 */
int MyStringList::getsize()
{
    return this->size;
}
/* 重载运算符 */
MyStringList& MyStringList::operator+=(const stdMyString& str)
{
    if(this->size + 1 >= this->capacity)            // 判断是否需扩容
    {
        this->capacity *= 2;
        stdMyString* temp = new stdMyString[this->capacity];
        memset(temp, 0, this->capacity);
        for(int idx = 0; idx < this->size; idx++)
        {
            temp[idx] = this->str[idx];
        }
        delete[] this->str;
        this->str = temp;
    }
    this->str[this->size++] = str;
    return *this;
}
MyStringList& MyStringList::operator-=(const stdMyString& str)
{
    int idx = 0;
    while (idx < this->size)
    {
        if(this->str[idx] == str)
        {
            this->removeByIndex(idx);
        }
        else
        {
            idx++;
        }
    }
    return *this;
}
stdMyString& MyStringList::operator[](int index)
{
    return this->str[index];
}
std::ostream& operator<<(std::ostream& os, const MyStringList& str)
{
    
}