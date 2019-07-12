#include <string>
#include <map>
#include <iostream>

using namespace std;
/**
 * Given a roman numeral, convert it to an integer. 
 * Input is guaranteed to be within the range from 1 to 3999.
 */

class Solution {
public:
    int romanToInt(string s) {
       map<char, int> value_map;
       value_map['I'] = 1;
       value_map['V'] = 5;
       value_map['X'] = 10;
       value_map['L'] = 50;
       value_map['C'] = 100;
       value_map['D'] = 500;
       value_map['M'] = 1000;
       int result = 0, i, j;
       result += value_map[s[0]];
       for (i = 0, j = 1; j < s.size(); ++i, ++j)
       {
           result += value_map[s[j]];
           if (value_map[s[i]] < value_map[s[j]])
           {
               result = result - 2 * value_map[s[i]];
           }
       }
        return result;
    }
};

class Solution2 
{
    public:
        int romanToInt(string s)
        {
            int i, j;
            int result = 0;
            for (i = 0, j = 1; j < s.size(); i++, j++)
            {
                switch (s[i])
                {
                case 'I':
                    result += 1;
                case 'V':
                    if (result )
                default:
                    break;
                }
            }

        }
};

int main()
{
    string s = "XL";
    Solution sl;
    int num = sl.romanToInt(s);
    cout << num << endl;
}