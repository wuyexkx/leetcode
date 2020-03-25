#include <string.h>

// 用c语言简单模拟映射，罗马字基本就是左边大于右边，特殊情况是左边小于右边，减去的后面会加上
int romanToInt(char * s){
    int roman[26];
    roman['I' - 'A'] = 1;
    roman['V' - 'A'] = 5;
    roman['X' - 'A'] = 10;
    roman['L' - 'A'] = 50;
    roman['C' - 'A'] = 100;
    roman['D' - 'A'] = 500;
    roman['M' - 'A'] = 1000;

    int len = strlen(s), result = 0, i = 0;
    for(; i<len-1; ++i){
        if(roman[s[i] - 'A'] < roman[s[i+1] - 'A']){
            result -= roman[s[i] - 'A'];
        } else {
            result += roman[s[i] - 'A'];
        }
    }
    return result + roman[s[i] - 'A'];
}

// 与上面基本一样
// inline int romanMap(char c)
// {
//     int nums[7] = {1,5,10,50,100,500,1000};
//     char *s = "IVXLCDM";
//     int i = 0;
//     while(s[i] != c){
//         ++i;
//     }
//     return nums[i];
// }

// int romanToInt(char * s){

//     int result = 0, i = 0;
//     for(; i<strlen(s)-1; ++i){
//         if(romanMap(s[i]) < romanMap(s[i+1])){
//             result -= romanMap(s[i]);
//         } else {
//             result += romanMap(s[i]);
//         }
//     }
//     return result + romanMap(s[i]);
// }


// // C++的 罗马字基本就是左边大于右边，特殊情况是左边小于右边，减去的后面会加上
// class Solution {
// public:
//     int romanToInt(string s) {
//         unordered_map<char, int> romanMap = {{'I',1},{'V',5},{'X',10},{'L',50},
//                                             {'C',100},{'D',500},{'M',1000}};
//         int result = 0;
//         int i = 0;
//         for(; i<s.length() - 1; ++i){
//             if(romanMap[s[i]] < romanMap[s[i+1]]){
//                 result -= romanMap[s[i]];
//             } else {
//                 result += romanMap[s[i]];
//             }
//         }
//         return result + romanMap[s[i]];
//     }
// };

// 暴力法
int romanToInt(char * s){
    int len = strlen(s), result = 0;
    // 遍历所有字符
    for(int i=0; i<len; ++i){
        if(s[i] == 'M'){
            result += 1000;
        }
        else if(s[i] == 'D'){
            result += 500;
        }
        else if(s[i] == 'C'){
            if(s[i+1] == 'M'){
                result += 900;
                ++i;
            } 
            else if(s[i+1] == 'D'){
                result += 400;
                ++i;
            } else {
                result += 100;
            }
        }
        else if(s[i] == 'L'){
            result += 50;
        }
        else if(s[i] == 'X'){
            if(s[i+1] == 'C'){
                result += 90;
                ++i;
            }
            else if(s[i+1] == 'L'){
                result += 40;                
                ++i;
            } else {
                result += 10;
            }
        }
        else if(s[i] == 'V'){
            result += 5;
        }
        else if(s[i] == 'I'){
            if(s[i+1] == 'X'){
                result += 9;
                ++i;
            }
            else if(s[i+1] == 'V'){
                result += 4;
                ++i;
            } else {
                result += 1;
            }
        }
    }
    return result;
}