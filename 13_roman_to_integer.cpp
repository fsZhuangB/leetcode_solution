#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
/**
 * Given a roman numeral, convert it to an integer. 
 * Input is guaranteed to be within the range from 1 to 3999.
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> valueMap;
        valueMap['I'] = 1;
        valueMap['V'] = 5;
        valueMap['X'] = 10;
        valueMap['L'] = 50;
        valueMap['C'] = 100;
        valueMap['D'] = 500;
        valueMap['M'] = 1000;
        int size = s.length();
        int arr[size], i, j;
        int result = 0;
        for (i = 0; i < size; i++)
        {
            arr[i] = valueMap[s[i]];
            cout << arr[i] << endl;
        }
        
        for (j = 0; j < size; j++)
        {
            if (arr[j - 1] < arr[j])
            {
                result += arr[j] - arr[j - 1];
                j++;
            }
            else 
            {
                result += arr[j - 1];
                if (j == size - 1)
                {
                    result += arr[j];
                }
            }
        }
        return result;
    }
};

int main()
{
    string s = "III";
    Solution sl;
    int num = sl.romanToInt(s);
    cout << num << endl;
}