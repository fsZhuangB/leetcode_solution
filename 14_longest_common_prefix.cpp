#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int i;
        string prefix = strs[0];
        // int len = 0;
        for (i = 1; i < strs.size(); i++)
        {
            if (prefix.size() == 0)
                return "";
            int len = 0;
            while (len < min(prefix.size(), strs[i].size()))
            {
                if (prefix[len] != strs[i][len])
                    break;
                len++;
            }
            prefix = prefix.substr(0, len);
        }
        return prefix;
    }
};

int main()
{
    vector<string> test{"string", "striop", "strr"};
    Solution s1;
    cout << s1.longestCommonPrefix(test) << endl;
}
