/**
 * Given an array nums of n integers, 
 * are there elements a, b, c in nums such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>

/**
 * This is the simple solution! The time complexity is O(n^3)
*/
class Solution {
    public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::set<int> nums2;
        int i, j, k;
        for (i = 0; i < nums.size(); ++i)
        {
            nums2.insert(nums[i]);
        }
        std::vector<std::vector<int>> result;
        for (i = 0; i < nums2.size() - 2; ++i)
        {
            for (j = i + 1; j < nums2.size() - 1; ++j)
            {
                for (k = j + 1; k < nums2.size(); ++k)
                {
                    if (nums2[i] + nums2[j] + nums2[k] == 0)
                        {
                            std::vector<int> a;
                            a.push_back(nums[i]);
                            a.push_back(nums[j]);
                            a.push_back(nums[k]);
                            result.push_back(a);
                        }
                }
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> a{-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> result;
    Solution s;
    result = s.threeSum(a);

    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << result[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int i, j;
//         map<int, int> tools;
//         vector<vector<int>> result, sum;
//         for (i = 0; i < nums.size(); ++i)
//         {
//             tools[nums[i]] = i;
//         }
        
//         for (i = 0; i < nums.size()-1; ++i)
//         {
//             for (j = 1; j < nums.size(); ++j)
//             {
//                 if (tools.find(0 - (nums[i] + nums[j])) != tools.end() && tools.find(-nums[i]-nums[j])->second != i && tools.find(-nums[i]-nums[j])->second != j)
//                 {
//                     vector<int> a;
//                     a.push_back(nums[i]);
//                     a.push_back(nums[j]);
//                     a.push_back(tools.find(-nums[i]-nums[j])->first);
//                     result.push_back(a);
//                 }
//             }
//         }
        
//         return result;
//     }
// };