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
        if (head->val == val)
            return head->next;
        ListNode* willDeleted = head;
        while (willDeleted->val != val)
            willDeleted = willDeleted->next;

        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur != willDeleted)
        {
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = willDeleted->next;
        delete willDeleted;
        return head;
    }
};