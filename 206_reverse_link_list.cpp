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
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /** 递归方法 */
        if (head == nullptr || head->next == nullptr)
            return head;
        /** 其实该地址空间一直存放着最后一个节点的地址 */
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

class Solution2 {
    public:
    ListNode* reverseList2(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head;
        ListNode *newHead = nullptr;
        while (p != nullptr)
        {
            ListNode *tmp = p->next;
            p->next = newHead;
            newHead = p;
            p = tmp;
        }
        return newHead;
    }
};

int main()
{

    return 0;
}