// #include <iostream>
// #include <vector>
// #include <string>

// class Encrypt {
//     private:
//     std::string charStr = "abcdefghijklmnopqrstuvwxyz";

//     public:
//     std::string encrypt(std::string plainText, std::string key)
//     {
//         std::vector<int> plainTextArr, cipherTextArr, keyArr;
//         // if (plainText == nullptr || plainText == "")
//         //     return nullptr;
//         plainText = preDeal(plainText);
//         key = preDeal(key);

//         for (int i = 0, j = 0; i < plainText.length(); ++i, ++j)
//         {
//             j = j % key.length();
//             cipherTextArr[i] = (plainText[i] - key[i] + 26) % 26;
//         }
//         std::string cypherText;
//         cypherText = convertToString(cipherTextArr);
//         return cypherText;
        
//     }

//     std::string preDeal(std::string text)
//     {
//         std::string dealAfter = "";
//         auto beg = text.begin();
//         auto end = text.end();
//         for (;beg != end; ++beg)
//         {
//             tolower(*beg);
//         }
//         return text;
//     }

//     /**
//      * 将vector转换为字符串
//     */
//     std::string convertToString(std::vector<int> numArr)
//     {
//         std::string str = "";
//         for (int i = 0; i < numArr.size(); ++i)
//         {
//             str += charStr[numArr[i]];
//         }
//         return str;
//     }

//     /**
//      * 将字符串转换成vector
//     */
//    std::vector<int> stringToVector(std::string str)
//    {
//        std::vector<int> numArr;
//        auto beg = str.begin();
//        auto end = str.end();
//        for (; beg != end; ++beg)
//        {
//            numArr.push_back(str.find(*beg));
//        }
//        return numArr;
//    }
// };

// int main()
// {
//     Encrypt e;
//     std::string key = "whatthefuck";
//     std::string text = "Heywhatareyoudoingthere";
//     std::string new_text = e.preDeal(text);
//     std::string ss = e.encrypt(new_text, key);
//     std::cout << ss << std::endl;


// }

// 凯撒密码实现
// 将明文字母变为它后面的三个字母，后面的循环到前面
// 公式 f(a) = (f(a) + 3) % 26
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
 
void caesar_encode_single(char* p, char* c, char key) {
    if (*p >= 'a' && *p <= 'z') { /// 小写字母
        *c = (*p - 'a'+ key) % 26 + 'a';
    }
    else if (*p >= 'A' && *p <= 'Z') { /// 大写字母
        *c = (*p - 'A'+ key) % 26 + 'A';
    }
    else { /// 其它转换成空格
    *c = ' ';
    }
}
 
void caesar_decode_single(char* c, char* p, char key) {
    char offset = (*c) - key;
   
    if (*c >= 'a' && *c <= 'z') { /// 小写字母
        offset = (offset >= 'a') ? offset : offset + 26;
        *p = offset;
    }
    else if (*c >= 'A' && *c <= 'Z') { /// 大写字母
        offset = (offset >= 'A') ? offset : offset + 26;
        *p = offset;
    }
    else { /// 其它转换成空格
        *p = ' ';
    }
}
 
void caesar_encode(char* plain, char* cipher, char key) {
         for (int i = 0; plain[i] != '\0'; ++i) { /// 逐个加密
                   caesar_encode_single(&plain[i], &cipher[i], key);
         }
}
 
void caesar_decode(char* cipher, char* plain, char key) {
         for (int i = 0; cipher[i] != '\0'; ++i) { /// 逐个解密
                   caesar_decode_single(&cipher[i], &plain[i], key);
         }
}
 
int main(int argc, char** argv) {
    if (argc < 3) {
        printf("usage: %s plain key\n", argv[0]);
        return -1;
    }
        
    char P[128];    
    char P2[128];  
    char C[128];    
    memset(P, 0, sizeof(P));
    memset(P2, 0, sizeof(P2));
    memset(C, 0, sizeof(C));
    strncpy(P, argv[1], sizeof(P));
    int K = atoi(argv[2]);
 
    caesar_encode(P, C, K);  
 
    printf("the ciphertext is \n%s\n", C); /// 输出密文
 
    caesar_decode(C, P2, K);
    printf("decode ciphertext is\n%s\n", P2);/// 输出解码明文
    return 0;
}