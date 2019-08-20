#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> str;

        auto begin = s.begin();
        auto end = s.end();
        for (; begin != end; ++begin)
        {
            if (*begin == '{' || *begin == '[' || *begin == '(')
                str.push(*begin);
            // 左括号
            else
            {
                if (!str.empty())
                {
                    char t = str.top();
                    str.pop();
                    if (!((*begin == ']' && t == '[') || (*begin == '}' && t == '{') || (*begin == ')' && t == '(')))
                        return false;
                }
                /**
                 * condition: ']'
                 */
                else
                    return false;

            }
        }
        if (str.empty())
            return true;
        else
            return false; 
    }
};

int main()
{
    Solution s;
    string str = "]";
    if (s.isValid(str))
        cout << "good!" << endl;
    else
    {
        cout << "bad!" << endl;
    }
    
}