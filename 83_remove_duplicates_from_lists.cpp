/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 思路：
 * 由于输入的链表已经排序，可以通过比较当前节点的值与它之后节点的值来确定它是否是重复节点。
 * 如果它是重复节点，我们可以直接修改当前节点的next指针，使它指向下下个节点即可。
*/
#include <iostream>


class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        else {
            ListNode *current = head;
            while (current && current->next) {
                if (current->val == current->next->val) {
                    ListNode *tmp = current->next;
                    current->next = current->next->next;
                    /** 这里如果不进行释放内存，会产生大量的野指针 */ 
                    delete tmp;
                }
                else
                    current = current->next;
            }
            return head;
        }  
    }
};


ListNode* createList(int a[], int n)
{
    ListNode *head = NULL, *p = NULL;
    for (int i = 0; i < n; i++)
    {
        if (head==NULL)
        {
            head = p = new ListNode(a[i]);
        }
        else
        {
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

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
    public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        /** 第一步，处理平凡条件，head == NULL || head->next == NULL时 */
        if (head == NULL || head->next == NULL)
            return head;
        head->next = deleteDuplicates(head->next);
        if (head->val == head->next->val)
            head = head->next;
        
        return head;
        
    }
};
int main()
{
    Solution2 s2;
    int a[]={1,1,2,3,3};


    iterate(s2.deleteDuplicates(createList(a, sizeof(a)/sizeof(int))));

    return 0;
}