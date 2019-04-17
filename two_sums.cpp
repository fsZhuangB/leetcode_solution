/* Given an array of integers
** Return indices of the two numbers such that they add up to a specific target.
** You may assume that each input would have exactly one solution, 
** And you may not use the same element twice.
*/
#include <vector>
#include <iostream>

/*
** force method
**/
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }

            }       
        }
        return result;
    }
};


int main()
{
    std::vector<int> num{1, 4, 3, 6, 5};
    std::vector<int> result;
    Solution s;
    result = s.twoSum(num, 7);
    for (auto i:result)
        std::cout << i << " ";
}