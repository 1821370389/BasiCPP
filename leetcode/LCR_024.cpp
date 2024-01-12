/* 反转链表 */
#include <iostream>
using namespace std;    // 命名空间
#include <string.h>
#include <stdio.h>
#include <unistd.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) 
{
    if(head == NULL)
    {
        return head;
    }
    ListNode* traveNode = head->next;
    ListNode* preNode = head;

    while(traveNode != NULL)
    {
        swap(traveNode->next, preNode);
        swap(traveNode, preNode);
    }
    return preNode;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = reverseList(head);
    
    return 0;
}