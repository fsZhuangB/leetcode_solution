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
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:

int sizeList(ListNode* node)
{
    int size = 0;
    ListNode *current = node;
    while (current != NULL)
    {
        ++size;
        current = current->next;
    }
    return size;
}

ListNode* getEndList(ListNode* node)
{
    ListNode *current = node;
    ListNode *end;
    while (current != NULL)
    {
        end = current;
        current = current->next;
    }
    return end;
}
    // ListNode *bubbleSortLists(ListNode *node)
    // {
    //     if (node == NULL)
    //         return NULL;
    //     else
    //     {
    //         int i;
    //         ListNode *current = node;
    //         int size = sizeList(node);
    //         for (i = 0; i < size; i++)
    //         {
    //             while (current->next != NULL)
    //             {
    //                 if (current->val > current->next->val)
    //                 {
    //                     int temp;
    //                     temp = current->val;
    //                     current->val = current->next->val;
    //                     current->next->val = temp;
    //                 }
    //                 current = current->next;
    //             }
    //             /**每次遍历结束，current都要重新回到链表头部 */
    //             current = node;
    //         }
    //     }
    //     return node;
    // }

ListNode* bubbleSortLists(ListNode* node)
{
    if (node == NULL)
        return NULL;

    else
    {
    
    ListNode *current = node;
    int i;
    for (i = 0; i < sizeList(node); ++i)
    {
        while (current->next != NULL)
        {
            if (current->val > current->next->val)
            {
                /**交换 */
                int temp = current->val;
                current->val = current->next->val;
                current->next->val = temp;
            }
            current = current->next;
        }
        /** 每次循环结束，都要让current重新指向node头节点 */
        current = node;
    }
    }
    return node;

}
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
         /** 要注意判断l1或者l2是否为空 */
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else
        {
            /**将两个链表连接在一起 */
            ListNode *endList = getEndList(l1);

            endList->next = l2;
            return bubbleSortLists(l1);
        }

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

class Solution2
{
    /** 使用递归解决 */
    public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else
        {
            if (l1->val > l2->val)
               { 
                    l2->next = mergeTwoLists(l1, l2->next);
                    return l2;
               }
            else
            {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }   
        }
    }



};

int main()
{
    Solution s2;

    ListNode node1(1);
    ListNode node2(3);
    ListNode node3(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    ListNode node4(2);
    ListNode node5(3);
    ListNode node6(9);
    node4.next = &node5;
    node5.next = &node6;
    node6.next = NULL;

    ListNode *newNode = s2.mergeTwoLists(&node1, &node4);
    
    iterate(newNode);

    return 0;
}

