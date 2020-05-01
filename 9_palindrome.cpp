#include <string>
#include <iostream>

/**
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 示例 1:
 * 输入: 121
 * 输出: true
 * 
 * 示例 2:
 * 输入: -121
 * 输出: false
 */

/**
 * Solution1: we convert the number into string
 */
class Solution1 {
public:
    bool isPalindrome(int x) {
        std::string stringX = std::to_string(x);
        std::string s;
        auto iter = stringX.rbegin();
        auto iter2 = stringX.rend();
        for (; iter != iter2; iter++)
        {
            s.push_back(*iter);
        }
        return s == stringX;     
    }
};

/**
 * Solve it without converting the integer to a string
 * Thinking: we reverse the int number and judge whether it is a negative number
 * If it is, return; 
 * If not, calculate the reverse number of this number, and compare with the origin number.
 */
class Solution2 {
    public:
        bool isPalindrome(int x) {
            if (x < 0)
                return false;
            int num = 0;
            int num2 = x;
            while (x)
            {
                /**
                 * Check whether the int overflow
                 */
                if (num > INT_MAX / 10 || num < INT_MIN / 10) return 0;
                num = num * 10 + x % 10;
                x = x / 10;
            }
            return num == num2;
        }
};

/**
 * Reverse part of the number, this can avoid the possible overflow of reversing number.
 * number % 10 can get the last number of the number
 * Then we use number / 10 to get rid of the last number
 * To judge whether we reach the middle of the number, we can use:
 * if the original number has bigger than the reverse number, we can know that we have reverse the part of the number
*/
class Solution3 {
        bool isPalindrome(int x) {
            // special condition
            // when x < 0, return false
            // when the last bit the number is 0, the first bit must be 0, it can be the right number
            if (x < 0 || (x % 10 == 0 && x != 0))
                return false;
            
            int reverseNumber = 0;
            // find whether we reach the middle of the number
            while (x > reverseNumber)
            {
                reverseNumber = reverseNumber * 10 + x % 10;
                x /= 10; // remove the last bit
            }

            // if the number is odd, the number in the middle doesn't affect the judgement
            // so we can remove the number
            return x == reverseNumber || x == reverseNumber/10;
        }
};

int main()
{
    Solution1 s;
    int x = -121;
    if (s.isPalindrome(x))
        std::cout << "good number!" << std::endl;
    else
        std::cout << "bad number!" << std::endl;

    Solution2 s2;
    int x2 = -121;
    if (s2.isPalindrome(x2))
        std::cout << "good number!" << std::endl;
    else
        std::cout << "bad number!" << std::endl;

}