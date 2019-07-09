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