/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        // we have to pay attention to the condition:
        // [3,4,5] we want to delete 3
        if (head->val == val)
            return head->next;

        // This code is not necessary, so we can depreacted this
        // ListNode* willDeleted = head;
        // while (willDeleted->val != val)
        //     willDeleted = willDeleted->next;

        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur->val != val)
        {
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
        return head;
    }
};