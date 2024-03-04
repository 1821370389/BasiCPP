#include "stdMyString.hpp"
#include <cstring>

char* myStrtok(char* str, const char* delim)
{
    static char* delimHeader = nullptr;
    if(str != nullptr)
    {
        delimHeader = str;
    }
    if(delimHeader == nullptr)
    {
        return nullptr;
    }
    char* ret = delimHeader;
    while(*delimHeader != '\0')
    {
        if(strchr(delim, *delimHeader))
        {
            *delimHeader = '\0';
            delimHeader++;
            break;
        }
        delimHeader++;
    }
    return ret;
}

stdMyString::stdMyString()
{
    // std::cout << "无参构造" << std::endl;
    this->size = 0;
    this->capacity = 15;
    this->str = new char[this->capacity];
    memset(this->str, 0 , this->capacity);
}
stdMyString::stdMyString(const char* str)
{
    // std::cout << "带参构造" << std::endl;
    this->size = strlen(str);
    this->capacity = this->size > 15 ? this->size + 1 : 16;
    this->str = new char[this->capacity];
    memset(this->str, 0, this->capacity);
    strncpy(this->str, str, this->capacity);
}
stdMyString::stdMyString(const stdMyString& str)
{
    // std::cout << "拷贝构造" << std::endl;
    this->size = str.size;
    this->capacity = str.capacity;
    this->str = new char[this->capacity];
    memset(this->str, 0, this->capacity);
    strncpy(this->str, str.str, this->capacity);
}
stdMyString::~stdMyString()
{
    // std::cout << "析构函数" << std::endl;
    delete[] this->str;
    this->str = nullptr;
    this->size = 0;
    this->capacity = 0;
}
int stdMyString::Size()
{
    return this->size;
}
std::ostream& operator<<(std::ostream& os, const stdMyString& str)
{
    os << str.str;
    return os;
}
std::istream& operator>>(std::istream& is, stdMyString& str)
{
    char c = '\0';
    while(c = getchar(), c != '\n')
    {
        str += c;
    }
    return is;
}
stdMyString& stdMyString::operator+(const stdMyString& str)
{
    this->size += str.size;
    if (this->size >= 15 )
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
stdMyString& stdMyString::operator+(const char* str)
{
    this->size += strlen(str);
    if (this->size >= 15 )
    {
        this->capacity = this->size + 1;
        char* temp = new char[this->capacity];
        memset(temp, 0, this->capacity);
        strncpy(temp, this->str, this->capacity);
        delete[] this->str;
        this->str = temp;
    }
    strncat(this->str, str, strlen(str));
    return *this;
}
stdMyString stdMyString::operator-(const stdMyString& str)
{
    char* deletes = strstr(this->str, str.str);
    while(deletes != nullptr)
    {
        char* backs = deletes + str.size;
        while(*backs != '\0')
            *deletes++ = *backs++;
        *deletes = '\0';
        deletes = strstr(this->str, str.str);
        this->size -= str.size;
        this->capacity = this->size >= 15 ? this->size + 1 : 15;
    }
    return *this;
}
stdMyString stdMyString::operator-(const char* str)
{
    char* deletes = strstr(this->str, str);
    while(deletes != nullptr)
    {
        char* backs = deletes + strlen(str);
        while(*backs != '\0')
            *deletes++ = *backs++;
        *deletes = '\0';
        deletes = strstr(this->str, str);
        this->size -= strlen(str);
        this->capacity = this->size >= 15 ? this->size + 1 : 15;
    }
    return *this;
}
stdMyString& stdMyString::operator=(const stdMyString& str)
{
    // if (this == &str)
    // {
    //     return *this;
    // }
    this->size = str.size;
    this->capacity = str.capacity;
    delete[] this->str;
    this->str = new char[this->capacity];
    memset(this->str, 0, this->capacity);
    strncpy(this->str, str.str, this->capacity);
    return *this;
}
stdMyString& stdMyString::operator=(const char* str)
{
    this->size = strlen(str);
    this->capacity = this->size > 15 ? this->size + 1 : 16;
    delete[] this->str;
    this->str = new char[this->capacity];
    memset(this->str, 0, this->capacity);
    strncpy(this->str, str, this->capacity);
    return *this;
}
stdMyString& stdMyString::operator+=(const stdMyString& str)
{
    *this = *this + str;
    return *this;
}
stdMyString& stdMyString::operator+=(const char* str)
{
    *this = *this + str;
    return *this;
}
stdMyString& stdMyString::operator+=(const char c)
{
    if(this->size + 1 == this->capacity )
    {
        /* 扩容 */
        this->capacity *= 2;
        char* temp = new char[this->capacity];
        memset(temp, 0, this->capacity);
        strncpy(temp, this->str, this->capacity);
        delete[] this->str;
        this->str = temp;
    }
    this->str[this->size++] = c;
    return *this;
}
char& stdMyString::operator[](int index)
{
    return this->str[index];
}
stdMyString::operator int()
{
    return atoi(this->str);
}
stdMyString::operator double()
{
    return atof(this->str);
}
bool stdMyString::operator==(const stdMyString& str)
{
    return strcmp(this->str, str.str) == 0;
}
bool stdMyString::operator==(const char* str)
{
    return strcmp(this->str, str) == 0;
}
bool stdMyString::operator!=(const stdMyString& str)
{
    return strcmp(this->str, str.str) != 0;
}
bool stdMyString::operator!=(const char* str)
{
    return strcmp(this->str, str) != 0;
}
bool stdMyString::operator>(const stdMyString& str)
{
    return strcmp(this->str, str.str) > 0;
}
bool stdMyString::operator>(const char* str)
{
    return strcmp(this->str, str) > 0;
}
bool stdMyString::operator<(const stdMyString& str)
{
    return strcmp(this->str, str.str) < 0;
}
bool stdMyString::operator<(const char* str)
{
    return strcmp(this->str, str) < 0;
}
// bool stdMyString::operator&&(const stdMyString& str)
// {
//     return this->size != 0 && str.size != 0;
// }
// bool stdMyString::operator&&(const char* str)
// {
//     return this->size != 0 && strlen(str) != 0;
// }

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

MyStringList::MyStringList()
{
    this->size = 0;
    this->capacity = 15;
    this->str = new stdMyString[this->capacity];
}
MyStringList::~MyStringList()
{
    delete[] this->str;
    this->str = nullptr;
    this->size = this->capacity = 0;
}
void MyStringList::removeByIndex(int index)
{
    if(index < 0 || index >= this->size)
    {
        return;
    }
    for (int i = index; i < this->size - 1; i++)
    {
        this->str[i] = this->str[i + 1];
    }
    this->size--;
}
int MyStringList::getsize()
{
    return this->size;
}
MyStringList& MyStringList::operator+=(const stdMyString& str)
{
    if (this->size == this->capacity)
    {
        this->capacity *= 2;
        stdMyString* temp = new stdMyString[this->capacity];
        memset(temp, 0, this->capacity);
        for (int i = 0; i < this->size; i++)
        {
            temp[i] = this->str[i];
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
    while(idx < this->size)
    {
        if (this->str[idx] == str)
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
std::ostream& operator<<(std::ostream& os, const MyStringList& list)
{
    for (int i = 0; i < list.size; i++)
    {
        os << list.str[i] << std::endl;
    }
    return os;
}

