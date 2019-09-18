#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr);
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = dummy->next;

/** 移动指针 */
        for (int i = 1; i < m; i++)
        {
            pre = pre->next;
            cur = cur->next;
        }
        for (int i = 0; i < n-m; i++)
        {
            /** 交换 */
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }
};