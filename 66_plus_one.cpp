/**
 * Given a non-empty array of digits representing a non-negative integer, 
 * plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list, 
 * and each element in the array contain a single digit.
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
    public:
    vector<int> plusOne(vector<int>& digits)
    {
        for (int i = digits.size() - 1; i > 0; i--)
        {
            ++digits[i];
            // if digits don't need to carry, we can simply return digits
            if (digits[i] != 10)
                return digits;
            else
            // or we need to set the bit to 0, and carry
                digits[i] = 0;
        }
        /**
         * If the first digits need to be (carry) plus one, like 9999, we have to insert 1 into it
        */
        digits.insert(digits.begin(), 1);
        return digits;
    }

};