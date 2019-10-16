/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 思路就是先将数字提取出来，然后反转，看看两个数字是否一样
*/
#include <math.h>
#include <iostream>

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 错误解法，只是单纯的考虑到了单个数字情况，无法处理如同[-129, -129]这样的情况
*/
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode *current = head;
//         ListNode *ss = head;
//         int number = 0;
//         int length = 0;
//         int rev = 0;
//         while (current) {
//             current = current->next;
//             length++;
//         }
//         while (ss) {
//             if (ss->val < 0)
//                 return false;
//             number += (ss->val) * pow(10, length-1);
//             ss = ss->next;
//             length--;
//         }

//         int test_number = number;
//         while (test_number) {
//             // 取个位数
//             int tmp_num = test_number % 10;
//             rev = rev * 10 + tmp_num;
//             test_number /= 10;
//         }
//           std::cout << rev << std::endl;

//         if (rev == number) 
//             return true;
//         else 
//             return false;
//     }
// };

/**
 * 使用快慢指针
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;

        while (fast) { // find the mid node
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }

        while (slow) { // reverse
            ListNode *ovn = slow->next;
            slow->next = prev;
            prev = slow;
            slow = ovn;
        }
        while (head && prev) {
            if (head->val != prev->val) {
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
int main()
{
    Solution s3;

    ListNode node1(-129);
    ListNode node2(3);
    ListNode node3(-129);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    if (s3.isPalindrome(&node1))
        std::cout << "This is a palindrome list!\n";
    else
        std::cout << "This is not a palindrome list!\n";
}