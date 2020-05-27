/**
 * You are climbing a stair case. 
 * It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top?
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int climbStairs(int n)
        {
            if (n <= 1)
                return n;
            vector<int> dp(1000, 0);
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 2;
            for (int i = 3; i <= n; ++i)
            {
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
        }
};

/**
 * Recursion solution:
 * This solution i use recursion to calculate every simple condition:
 * n == 1 && n == 2 condition
*/
class Solution2 {
    public:
    int climbStairs(int n)
    {
        return climbStairs(0, n);

    }
    /**
     * i指目前阶数
     * n指目标阶数
    */
    int climbStairs(int i, int n)
    {
        if (i > n)
        {
            return 0;
        }
        if (i == n)
        {
            return 1;
        }
        return climbStairs(i + 1, n) + climbStairs(i + 2, n);
    }
};