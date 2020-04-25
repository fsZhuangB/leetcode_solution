#include <vector>
#include <iostream>
typedef int Rank;
using namespace std;

class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = 0; // 指向nums1
    int j = 0; // 指向nums2
    int k = 0; // 指向num
    vector<int> num(nums1.begin(), nums1.begin()+m);
    while (j < n && k < m)
    {
        if (num[k] < nums2[j])
            nums1[i++] = num[k++];
        else
            nums1[i++] = nums2[j++];
    }
    
    while (j < n)  // j还没到头
        nums1[i++] = nums2[j++];
    while (k < m)  // k还没到头
        nums1[i++] = num[k++];
}
};

int main()
{
    vector<int> n1{1, 2, 4, 0, 0, 0};
    vector<int> n2{6, 7, 8};
    Solution s;
    s.merge(n1, 3, n2, 3);

}