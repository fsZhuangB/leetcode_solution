/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /** 递归方法 */
        if (head == nullptr || head->next == nullptr)
            return head;
        /** 其实该地址空间一直存放着最后一个节点的地址 */
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

class Solution2 {
    public:
    ListNode* reverseList2(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head;
        ListNode *newHead = nullptr;
        while (p != nullptr)
        {
            ListNode *tmp = p->next;
            p->next = newHead;
            newHead = p;
            p = tmp;
        }
        return newHead;
    }
};

class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummyNode = NULL;
        ListNode *current = head;

        while (current)
        {
            ListNode *tmp = current->next;
            current->next = dummyNode;
            dummyNode = current;
            current = tmp;
        }
        return dummyNode;
    }
};

void iterate(ListNode *node)
{
    ListNode *current = node;
    while (current != NULL)
    {
        std::cout << current->val << std::endl;
        current = current->next;
    }
}

int main()
{
    Solution3 s3;

    ListNode node1(1);
    ListNode node2(3);
    ListNode node3(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    s3.reverseList(&node1);
    iterate(&node1);


    return 0;
}