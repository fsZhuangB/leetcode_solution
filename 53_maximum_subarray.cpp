/**
 * Given an integer array nums, 
 * find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum.
*/
#include <iostream>
#include <algorithm>

// this is the first solution
// I use the DP method
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] > 0)
                nums[i] += nums[i-1];
        }

        return *std::max_element(nums.begin(), nums.end());
    }
};