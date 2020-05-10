/**
 * Given a sorted array and a target value, 
 * return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
*/

/**
 * We use binary search to solve this problem.
 * Remember it's hard to write a bug-free program about binary search, so practice!
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int BinarySearch(int lo, int hi, int target, vector<int>& nums)
    {
        while (lo < hi)
        {
            int mi = (lo + hi) >> 1;
            if (target < nums[mi])
            {
                hi = mi;
            }
            else if (target > nums[mi])
            {
                lo = mi + 1;
            }
            else 
                return mi;
        }
        /**
         * Remember there's another comparison in the last iteration
         * So we need to return lo, not mi
        */
        return lo;
    }
    int searchInsert(vector<int>& nums, int target) {
        return BinarySearch(0, nums.size(), target, nums);
    }
};