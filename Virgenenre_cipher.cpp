#include <iostream>
#include <vector>
#include <string>

class Encrypt {
    private:
    static std::string charStr = "abcdefghijklmnopqrstuvwxyz";

    public:
    std::string encrypt(std::string plainText, std::string key)
    {
        std::vector<int> plainTextArr, cipherTextArr, keyArr;
        // if (plainText == nullptr || plainText == "")
        //     return nullptr;
        plainText = preDeal(plainText);
        key = preDeal(key);

        for (int i = 0, j = 0; i < plainText.length(); ++i, ++j)
        {
            j = j % key.length();
            cipherTextArr[i] = (plainText[i] - key[i] + 26) % 26;
        }
        std::string cypherText;
        cypherText = convertToString(cipherTextArr);
        return cypherText;
        
    }

    std::string preDeal(std::string text)
    {
        std::string dealAfter = "";
        auto beg = text.begin();
        auto end = text.end();
        for (;beg != end; ++beg)
        {
            tolower(*beg);
        }
        return text;
    }

    /**
     * 将vector转换为字符串
    */
    std::string convertToString(std::vector<int> numArr)
    {
        std::string str = "";
        for (int i = 0; i < numArr.length(); ++i)
        {
            str += charStr[numArr[i]];
        }
        return str;
    }

    /**
     * 将字符串转换成vector
    */
   std::vector<int> stringToVector(std::string str)
   {
       std::vector<int> numArr;
       auto beg = str.begin();
       auto end = str.end();
       for (; beg != end; ++beg)
       {
           numArr.push_back(str.find(*beg));
       }
       return numArr;
   }
};