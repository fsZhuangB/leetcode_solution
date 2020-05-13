/**
 * Given a non-negative integer numRows, 
 * generate the first numRows of Pascal's triangle.
*/
#include <vector>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> generate(int numRows)
    {
        // use numRows to initializd the vector
        vector<vector<int>> ans(numRows);
        if (numRows == 0) return ans;

        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0 || j == i)
                {
                    // if it's the edge of the left or the right, we just push 1
                    ans[i].push_back(1);
                }
                else 
                {
                    ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
        }
        return ans;
    }

};