/**
 * Given two (singly) linked lists, 
 * determine if the two lists intersect. 
 * Return the inter­ secting node. 
 * Note that the intersection is defined based on reference, not value. 
 * That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.
*/
////////////////////////////////////////////

////////////////////////////////////////////
/**
 * 这道题目是很容易想到的双指针题，相交链表的形状：
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2)
        {
            // 如果走到最后，就直接回到从headB开头
            p1 = (p1 == nullptr) ? headB : p1 = p1->next;
            p2 = (p2 == nullptr) ? headA : p2 = p2->next;
        }
        return p1;
    }

};
