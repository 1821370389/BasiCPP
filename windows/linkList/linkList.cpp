#include "linkList.hpp"
#include <iostream>
#include <cstring>
using namespace std;

template<class T> LinkedList<T>::LinkedList(const T& data)
{
    head = new Node<T>(data);
    // memset(head, 0, sizeof(Node<T>));
    size = 1;
}
template<class T> LinkedList<T>::~LinkedList()
{
    destroy();
}
template<class T> void LinkedList<T>::insertHead(const T& data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    size++;
}
template<class T> void LinkedList<T>::insertTail(const T& data)
{
    Node<T> *newNode = new Node<T>(data);
    // memset(newNode, 0, sizeof(Node<T>));
    if(head == nullptr)
    {
        head = newNode;
        return;
    }
    Node<T> *temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}
template<class T> void LinkedList<T>::insert(int pos, const T& data)
{
    if(pos == 0)
    {
        insertHead(data);
        return;
    }
    if(pos == size)
    {
        insertTail(data);
        return;
    }
    Node<T> *newNode = new Node<T>(data);
    // memset(newNode, 0, sizeof(Node<T>));
    Node<T> *temp = head;
    for(int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}
template<class T> void LinkedList<T>::operator+(const T& data)
{
    insertTail(data);
}
template<class T> void LinkedList<T>::remove(int pos)
{
    if(pos == 0)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    Node<T> *temp = head;
    for(int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    Node<T> *del = temp->next;
    temp->next = del->next;
    delete del;
    size--;
}
template<class T> void LinkedList<T>::removeHead()
{
    remove(0);
}
template<class T> void LinkedList<T>::removeTail()
{
    remove(size - 1);
}
template<class T> T LinkedList<T>::get(int pos)
{
    Node<T> *temp = head;
    for(int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}
template<class T> T LinkedList<T>::operator[](int pos)
{
    return get(pos);
}
template<class T> int LinkedList<T>::length()
{
    return size;
}
template<class T> void LinkedList<T>::print()
{
    Node<T> *temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}
template<class T> void LinkedList<T>::reverse()
{
    Node<T> *prev = nullptr;
    Node<T> *curr = head;
    Node<T> *next = nullptr;
    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
template<class T> void LinkedList<T>::sort()
{
    Node<T> *i = head;
    Node<T> *j = nullptr;
    T temp;
    for(i = head; i->next != nullptr; i = i->next)
    {
        for(j = i->next; j != nullptr; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
template<class T> void LinkedList<T>::destroy()
{
    Node<T> *temp = head;
    while(temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    size = 0;
}