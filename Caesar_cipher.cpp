/**
 * C++实现凯撒密码
*/
#include <iostream>
#include <string>
#include <unordered_map>
#define OFFSET 3

std::string encrypt(std::string test, std::unordered_map<char, int> m)
{
    std::string encrypted;
    auto beg = test.begin();
    auto end = test.end();
    for (; beg != end; beg++)
    {
        if (std::tolower(*beg) == ' ')
           {
            encrypted += *beg;
            ++beg;
           }
        else
        {
            // std::cout << enc << std::endl;
            int enc = (m[std::tolower(*beg)] + OFFSET) % 26;
            for (auto &v : m)
                {
                    if (v.second == enc)
                        encrypted += v.first;
                }   
        }
    }
    return encrypted;
}
int main()
{
    int i = 0;
    std::unordered_map<char, int> dict;
    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    std::string test = "HelloWorld";

    auto beg = letters.begin();
    auto end = letters.end();

    /**
     * 将各部分转换成数字
    */
    for (; beg != end; beg++)
    {
        dict[*beg] = i;
        i++;
    }

    /**
     * 读取字符串，并转换成数字
    */
    std::string encrypted_string = encrypt(test, dict);
    std::cout << encrypted_string << std::endl;


}

