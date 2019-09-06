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
    Solution s;
    ListNode node1(1);
    ListNode node2(3);
    ListNode node3(4);
    ListNode node4(4);
    ListNode node5(6);
    

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;

    iterate(s.deleteDuplicates(&node1));

    return 0;
}