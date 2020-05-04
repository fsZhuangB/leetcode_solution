/**
 * Given a sorted array nums
 * remove the duplicates in-place such that each element appear only once 
 * and return the new length.
 * Do not allocate extra space for another array, 
 * you must do this by modifying the input array in-place with O(1) extra memory.
*/
#include <vector>
#include <iostream>
using namespace std;

/**
 * two-pointer method
 * Remember, elements int a sorted array must stay together.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int i = 0, j = 1;
        for (; j < nums.size(); ++j)
        {
            if (nums[i] != nums[j])
                {
                    i++;
                    nums[i] = nums[j];
                }
        }
        return i + 1;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 2, 3, 4, 4};
    s.removeDuplicates(a);

    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << endl;
    }
}