#ifndef __STDMYSTRING_HPP__
#define __STDMYSTRING_HPP__
#include <iostream>

class MyStringList;

class stdMyString
{
private:
    char* str;        // 指针
    int size;       // 长度
    int capacity;   // 容量
public:
    stdMyString();
    stdMyString(const char* str);
    stdMyString(const stdMyString& str);
    ~stdMyString();
    int Size();

    friend std::ostream& operator<<(std::ostream& os, const stdMyString& str);
    friend std::istream& operator>>(std::istream& is, stdMyString& str);
    
    stdMyString& operator+(const stdMyString& str);
    stdMyString operator-(const stdMyString& str);
    stdMyString& operator=(const stdMyString& str);
    stdMyString& operator+=(const stdMyString& str);
    stdMyString& operator+=(const char c);

    char& operator[](int index);

    operator int();
    operator double();

    bool operator==(const stdMyString& str);
    bool operator!=(const stdMyString& str);
    bool operator>(const stdMyString& str);
    bool operator<(const stdMyString& str);
    // bool operator&&(const stdMyString& str);
    // bool operator&&(const char* str);
    
    MyStringList split(const char* str);
    
};

class MyStringList
{
private:
    stdMyString * str;
    int size;
    int capacity;
public:
    MyStringList();
    ~MyStringList();
    void removeByIndex(int index);
    int getsize();
    MyStringList& operator+=(const stdMyString& str);
    MyStringList& operator-=(const stdMyString& str);
    stdMyString& operator[](int index);
    friend std::ostream& operator<<(std::ostream& os, const MyStringList& str);
};

char* myStrtok(char* str, const char* delim);


#endif //__STDMYSTRING_HPP__