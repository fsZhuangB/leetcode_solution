/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <set>

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 使用快慢指针：如果有环，则快指针与慢指针一定会相遇
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode * fast = head->next, *slow = head;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

/**
 * 使用哈希表：检查一个节点是否曾经被访问过
*/
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
         if (head == nullptr || head->next == nullptr)
            return false;

        std::set<ListNode *> set_list;
        while (head != nullptr) {
            if (set_list.count(head) == 1)
                return true;
            else 
                set_list.insert(head);
            head = head->next;
        }
        return false;
    }
};