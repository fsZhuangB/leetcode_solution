/**
 * 美团面试题，leetcode 第8题：实现atoi函数
*/

#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

int my_atoi(string literal)
{
    unsigned long len = literal.length();
    int index = 0;
    // 跳过空格
    while (index < len)
    {
        if (literal[index] != ' ')
            break;
        index++;
    }
    if (index == len)
        return 0;
    
    // 跳过空格后，处理正负号
    int sign = 1;
    if (literal[index] == '+')
    {
        index++;
    }
    else if (literal[index] == '-')
    {
        index++;
        sign = -1;
    }

    int result = 0;
    while (index < len)
    {
        char curChar = literal[index];
        // 不合法情况
        if (curChar < '0' || curChar > '9')
            break;

        // 处理正常的数字
        result = result * 10 + sign * (curChar - '0');
        index++;
    }
    return result;
   
}
int main()
{
    string a =  "123";
    int val = my_atoi(a);

    cout << val;
}