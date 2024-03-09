#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
    Node(T data, Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev) {}
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DoublyLinkedList();
    DoublyLinkedList(T data);
    ~DoublyLinkedList();
    /* 插入数据 */
    void insert(T data);
    /* 插入数据到指定位置 */
    void insert(T data, int index);
    /* 头插 */
    void insertHead(T data);
    /* 尾插 */
    void insertTail(T data);
    /* 删除指定位置的节点 */
    void remove(int index);
    /* 头删 */
    void removeHead();
    /* 尾删 */
    void removeTail();
    /* 删除指定数据的节点 */
    void removeByValue(const T& data);
    /* 打印链表 */
    void print();
    /* 获取链表长度 */
    int getSize();
    /* 判断链表是否为空 */
    bool isEmpty();
    /* 清空链表 */
    void clear();
    /* 获取指定位置的值 */
    T& get(int index);
    /* 修改指定位置的值 */
    void set(int index, T data);
    /* 反转链表 */
    void reverse();
    /* 排序 */
    void sort();
    
    /* 重载[]*/
    T& operator[](int index);
    /* 重载+ */
    DoublyLinkedList& operator+(T data);
    /* 重载- */
    DoublyLinkedList& operator-(const T& data);
    

};
template<typename T> DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template<typename T> DoublyLinkedList<T>::DoublyLinkedList(T data)
{
    head = new Node<T>(data);
    tail = head;
    size = 1;
}
template<typename T> DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}
template<typename T> void DoublyLinkedList<T>::insert(T data)
{
    if (head == nullptr) {
        head = new Node<T>(data);
        tail = head;
    }
    else {
        tail->next = new Node<T>(data);
        tail->next->prev = tail;
        tail = tail->next;
    }
    size++;
}
template<typename T> void DoublyLinkedList<T>::insert(T data, int index)
{
    if (index < 0 || index > size) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (index == 0) {
        insertHead(data);
        return;
    }
    if (index == size) {
        insertTail(data);
        return;
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    Node<T>* newNode = new Node<T>(data, current, current->prev);
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}
template<typename T> void DoublyLinkedList<T>::insertHead(T data)
{
    if (head == nullptr) {
        head = new Node<T>(data);
        tail = head;
    }
    else {
        head = new Node<T>(data, head, nullptr);
        head->next->prev = head;
    }
    size++;
}
template<typename T> void DoublyLinkedList<T>::insertTail(T data)
{
    if (tail == nullptr) {
        tail = new Node<T>(data);
        head = tail;
    }
    else {
        tail->next = new Node<T>(data, nullptr, tail);
        tail = tail->next;
    }
    size++;
}
template<typename T> void DoublyLinkedList<T>::remove(int index)
{
    if (index < 0 || index >= size) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (index == 0) {
        removeHead();
        return;
    }
    if (index == size - 1) {
        removeTail();
        return;
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}
template<typename T> void DoublyLinkedList<T>::removeHead()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    size--;
}
template<typename T> void DoublyLinkedList<T>::removeTail()
{
    if (tail == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node<T>* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    size--;
}
template<typename T> void DoublyLinkedList<T>::removeByValue(const T& data)
{
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            if (current == head) {
                removeHead();
                return;
            }
            if (current == tail) {
                removeTail();
                return;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
    std::cout << "Data not found" << std::endl;
}
template<typename T> void DoublyLinkedList<T>::print()
{
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
template<typename T> int DoublyLinkedList<T>::getSize()
{
    return size;
}
template<typename T> bool DoublyLinkedList<T>::isEmpty()
{
    return size == 0;
}
template<typename T> void DoublyLinkedList<T>::clear()
{
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template<typename T> T& DoublyLinkedList<T>::get(int index)
{
    if (index < 0 || index >= size) {
        std::cout << "Invalid index" << std::endl;
        return head->data;
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}
template<typename T> void DoublyLinkedList<T>::set(int index, T data)
{
    if (index < 0 || index >= size) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = data;
}
template<typename T> void DoublyLinkedList<T>::reverse()
{
    Node<T>* current = head;
    Node<T>* temp;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        head = temp->prev;
    }
}
template<typename T> void DoublyLinkedList<T>::sort()
{
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* minNode = current;
        Node<T>* temp = current->next;
        while (temp != nullptr) {
            if (temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != current) {
            T tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;
        }
        current = current->next;
    }
}

template<typename T> T& DoublyLinkedList<T>::operator[](int index)
{
    return get(index);
}
template<typename T> DoublyLinkedList<T>& DoublyLinkedList<T>::operator+(T data)
{
    insert(data);
    return *this;
}
template<typename T> DoublyLinkedList<T>& DoublyLinkedList<T>::operator-(const T& data)
{
    removeByValue(data);
    return *this;
}
int main()
{
    DoublyLinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.print();
    list.remove(2);
    list.print();
    list.removeByValue(2);
    list.print();
    list.insertHead(0);
    list.print();
    list.insertTail(6);
    list.print();
    list.set(0, -1);
    list.print();
    list.reverse();
    list.print();
    list.sort();
    list.print();
    return 0;
}
