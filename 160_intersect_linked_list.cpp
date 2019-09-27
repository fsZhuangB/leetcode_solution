#include <iostream>

class ListNode 
{
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);

        int i;
        if (lengthA < lengthB)
        {
            for (i = 0; i < lengthB - lengthA; ++i)
                /** 把短的链表向前移动 */
                headB = headB->next;
        }
        else
        {
            for (i = 0; i < lengthA - lengthB; ++i)
                headA = headA->next;
        }

        /**
         * 直接进行比较即可
        */
        while (headA && headB && headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        
        return (headA && headB) ? headA : NULL;

    }

    int getLength(ListNode * header)
    {
        ListNode *current = header;
        int count = 0;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }



};