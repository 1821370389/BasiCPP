// #pragma once
#ifndef __LINKLIST_CPP__
#define __LINKLIST_CPP__
template <typename T>
class Node
{
public:
	Node(const T& data) : data(data) {}
	T data;
	Node<T>* next = nullptr;
};
template <typename T>
class LinkedList
{
public:
	LinkedList() : head(nullptr),size(0) {}
    LinkedList(const T& data);
	~LinkedList();

    /* 头插 */
    void insertHead(const T& data);
    /* 尾插 */
    void insertTail(const T& data);
    /* 指定位置插入 */
	void insert(int pos, const T& data);
    /* 重载+ */
    void operator+(const T& data);
    /* 头删 */
    void removeHead();
    /* 尾删 */
    void removeTail();
    /* 指定位置删除*/
	void remove(int pos);
    /* 获取指定位置的值 */
    T get(int pos);
    /* 重载[] */
    T operator[](int pos);
    /* 获取长度 */
    int length();
    /* 打印链表 */
	void print();
    /* 反转 */
    void reverse();
    /* 排序 */
    void sort();
    /* 销毁 */
    void destroy();

private:
	Node<T>* head;
    int size;
};
// #include "linkList.cpp"
#endif // __LINKLIST_CPP__