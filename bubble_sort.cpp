#include <iostream>
#include <vector>

class Solution {
    public:
    void bubble_sort(std::vector<int> &arr)
    {
        int i, j;
        for (i = 0; i < arr.size(); i++)
        {
            for (j = 0; j < arr.size() - i - 1; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
};

int main()
{
    std::vector<int> arr{2, 1, 3, 11, 9, 8, 6};
    Solution s;
    s.bubble_sort(arr);

    for (auto i : arr)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
