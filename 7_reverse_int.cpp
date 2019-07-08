#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
        int num = 0;
        while (x)
        {
            if (num > INT_MAX / 10 || num < INT_MIN / 10)
                return 0;
            num = num * 10 + x % 10;
            x = x / 10;
        }  
        return num;
    }
};

int main()
{
    Solution s;
    int x = 321;
    int y = s.reverse(x);
    cout << x << endl;
    cout << "Reversed: " << endl;
    cout << y << endl;

    return 0;
}