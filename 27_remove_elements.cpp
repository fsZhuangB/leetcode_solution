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

/**
 * Solution3:
 * double pointer: if the array has few elements to delete, such as num = [1, 2, 3, 4, 5], val = 4
 * the previous solution may have unecessary swap to the 4 elements.
 * SO the SOLUTION is: when we nums[i] == val, we can swap the elements with the last elements.
 * Also, we have to release the last elements.
 * You gave to pay attention that the question said the order of the elements are not required.
 * So we can use this algorithm.
*/
class Solution3 
{
    int removeElements(vector<int>& nums, int val)
    {
        int i = 0; // the index
        int n = nums.size(); // the last element
        while (i < n)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[n - 1];
                n--;
            }
            else
            {
                i++;
            }
        }
        return n;
    }
};

class Solution3_2
{
    public:
    int removeElement(vector<int>& nums, int val)
    {
        int i = 0;
        int n = nums.size();
        /**
         * I just modified the while loop to the for loop
        */
        for (; i < n;)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[n-1];
                n--;
            }
            else
                i++;
        }
        return n;
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