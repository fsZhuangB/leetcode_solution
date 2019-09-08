/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <unordered_map>

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *create_list(std::vector<int> &a, int n)
{
    ListNode *head = NULL;
    ListNode *p = NULL;
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
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

class Solution
{
public:

    ListNode* deleteDuplicates(ListNode* head) 
    {
        std::vector<int> a;
        std::unordered_map<int, int> int_count;
        ListNode *current = head;
        for (; current != NULL; current = current->next)
            ++int_count[current->val];
        for (const auto &w : int_count)
        {
            //std::cout << w.first << "is " << w.second << std::endl;

            if (w.second == 1)
                a.insert(a.begin(), w.first);
        }
    ListNode *head2 = NULL;
    ListNode *p = NULL;
    for (int i = 0; i < a.size(); i++)
    {
        if (head2 == NULL)
        {
            head2= p = new ListNode(a[i]);
        }
        else
        {
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head2;
                        
        
    }
};



int main()
{
    Solution s;
    std::vector<int> a{1, 2, 3, 3, 4, 4, 5};

    iterate(s.deleteDuplicates(create_list(a, a.size())));

}