#include <string.h>

int lengthOfLongestSubstring(char * s){
    #define max(a, b) (a > b ? a : b)
    int start=0, length=0, sSize=strlen(s), max_length=0;
    int v[128];
    memset(v, -1, sizeof(int) * 128);
    for(int i=0; i<sSize; ++i){
        if(v[s[i]] >= start){
            start = v[s[i]] + 1;
            length = i - start;
        }
        v[s[i]] = i;
        ++length;
        max_length = max(length, max_length);
    }
    return max_length;
}

// // 滑动窗口实现，用类似两个指针start和i，还有映射去保存字符的索引
// int lengthOfLongestSubstring(char * s){
//     // c语言中没有max，需要自己定义
//     #define max(a, b) (a > b ? a : b)
//     int start=0, length=0, sSize=strlen(s), max_length=0;
//     // 用于存放对应字符的在s中的索引，初始化为-1，从0开始
//     int v[128];
//     memset(v, -1, sizeof(int) * 128);
//     // 一次遍历s
//     for(int i=0; i<sSize; ++i){
//         // 如果在start~i中找到了同样的字符，就把start指向该字符的下一个字符，
//         // 并计算无重复长度，这里start被+1，在后面需要给length加1
//         if(v[s[i]] >= start){
//             start = v[s[i]] + 1;
//             length = i - start;
//         }
//         // 每次保存更新字符的索引
//         v[s[i]] = i;
//         // 对应前面start被+1
//         ++length;
//         // 每次计算最大值
//         max_length = max(length, max_length);
//     }
//     return max_length;
// }
