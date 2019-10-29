/* Given an array of integers
** Return indices of the two numbers such that they add up to a specific target.
** You may assume that each input would have exactly one solution, 
** And you may not use the same element twice.
*/
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
/*
** force method
**/
namespace sf
{
class Solution 
{
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
}

namespace sn 
{
    class Solution2
    {
        public:
        std::vector<int> twoSum(std::vector<int> &nums, int target)
        {
            std::unordered_map<int, int> m;
            std::vector<int> result;
            for (int i = 0; i < nums.size(); i++)
            {
                // if not found the num
                if (m.find(nums[i]) == m.end())
                    m[target - nums[i]] = i;
                else
                {
                    result.push_back(m[nums[i]]);
                    result.push_back(i);
                    break;
                }
                
            }
            return result;
        }
    };

}

class Solution3 {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> tools;
        vector<int> result;
        int i = 0, length = nums.size();
        for (; i < length; ++i)
            tools[nums[i]] = i;
        for (int j = 0; j < length; ++j)
        {
            // if not find
            if (tools.find(target - nums[j]) != tools.end() && tools[target - nums[j]] != j)
            {
                result.push_back(j);
                result.push_back(tools[target-nums[j]]);
                break;
            }    
        }
        return result;
    }
};

int main()
{
    std::vector<int> num{1, 4, 3, 6, 5};
    std::vector<int> result;
    sn::Solution2 s;
    result = s.twoSum(num, 7);
    for (auto i:result)
        std::cout << i << " ";
}
