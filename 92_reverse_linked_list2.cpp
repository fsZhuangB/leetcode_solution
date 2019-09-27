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

class Solution2 {
    public:
    /**
     * 这是我的第二种解法，与第一种解法大同小异，都是一种两两交换、直接插入的方法
    */
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode * dummyNode = new ListNode(0);
        ListNode * pre = dummyNode;
        dummyNode->next = head;

        /**
         * 从 dummy Node 移动 pre 节点 m-1 步，使其移至我们需要的移动节点之前
        */
        for (int i = 0; i < m - 1; ++i) pre = pre->next;

        ListNode * cur = pre->next;

        /**
         * 开始插入节点
        */
       /** 没看懂链表怎么移动 */
       for (int i = m; i < n; i++)
       {
           ListNode *tmp = cur->next;

           cur->next = tmp->next;
           tmp->next = pre->next;
           pre->next = tmp;
       }
        return dummyNode->next;

    }

};