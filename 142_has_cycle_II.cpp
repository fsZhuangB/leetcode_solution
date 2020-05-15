/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <set>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        std::set<ListNode *> set_list;
        while (head != nullptr) {
            if (set_list.count(head) == 1)
                return head;
            else
                set_list.insert(head);
            head = head->next;
        }
        return nullptr;    
    }
};