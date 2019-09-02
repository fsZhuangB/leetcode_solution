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


class Solution2
{
    public: 
    bool isValid(string s)
    {
        /**首先，需要一个栈str */
        stack<char> str;
        auto begin = s.begin();
        auto end = s.end();


        /**利用循环，读取string中的字符*/
        while(begin != end)
        {
            /** 如果是左括号*/
            if (*begin == '{' || *begin == '[' || *begin == '(')
            {
                str.push(*begin);
                ++begin;
            }
            /** 如果不是左括号 */
            else
            {
                /**如果栈不为空 */
                if (!str.empty())
                {
                    char current_stack = str.top();
                    str.pop();
                    /**注意begin应该一直是右括号而不是左括号 */
                    if (!((*begin == ')' && current_stack == '(') || (*begin == ']' && current_stack == '[') || (*begin == '}' && current_stack == '{')))
                        return false;
                }
                /**要检测栈为空，而且有字符的情况 */
                else
                {
                    return false;
                } 
                ++begin;
            }    
        }
        /**无字符、并且栈为空的情况 */
            if (str.empty())
                return true;
            else
            {
                return false;
            }
    }

};

int main()
{
    
    Solution2 s;
    string str = "]";
    if (s.isValid(str))
        cout << "good!" << endl;
    else
    {
        cout << "bad!" << endl;
    }
    
}