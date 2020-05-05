/**
 * Given an array nums and a value val, 
 * remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, 
 * you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution1 {
    public:
    int removeElement(vector<int>& nums, int val) {
        auto beg = nums.begin();
        auto end = nums.end();

        for (; beg != end; beg++)
        {
            if (*beg == val)
                nums.erase(beg);
        }
        return nums.size();
}
};

/**
 * This solution is similar to leetcode 26_delete_duplicate_in_array
*/
class Solution {
    public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main()
{
    vector<int> a{1, 2, 2, 3, 4};
    Solution s;
    s.removeElement(a, 2);
    for (auto i : a)
    {
        cout << i << " ";
    }

    return 0;

}