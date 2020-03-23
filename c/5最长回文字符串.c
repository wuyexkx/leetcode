#include <string.h>

// 动态规划


// 中心扩展法
char * longestPalindrome(char * s){
    int length = strlen(s);
    int max_length=0, start=0, end=0;
    // 处理子串是奇数的情况
    for(int i=0; i<length; ++i){ // abcba abbcb
        int ss=i-1, ee=i+1; // 主要是这一行不同
        while(ss >=0 && ee < length && s[ss] == s[ee]){
            ss--;
            ee++;
        }
        if(ee - ss - 1 > max_length){
            max_length = ee - ss - 1;
            start = ++ss;
            end = --ee;
        }
    }
    // 处理子串是偶数的情况
    for(int i=0; i<length; ++i){ // abbac  bacbbca
        int ss=i, ee=i+1;  // 主要是这一行不同
        while(ss >=0 && ee < length && s[ss] == s[ee]){
            ss--;
            ee++;
        }
        if(ee - ss - 1 > max_length){
            max_length = ee - ss - 1;
            start = ++ss;
            end = --ee;
        }
    }
    // 最终直接折断s返回s就行了
    if(max_length > 0){
        s[end+1] = '\0';
        return s + start;
    }
    // 空的情况
    s[0] = '\0';
    return s;
}


// 暴力法，超时，通过97/103
bool huiwen(char * s, int start, int end)
{
    for(int i=start, j=end; i < j; ++i, --j){
        if(s[i] != s[j])
            return false;
    }
    return true;
}

char * longestPalindrome(char * s){
    int length = strlen(s);
    char *strs = malloc(sizeof(char) * 1001);
    int max_length = -1;
    int start, end;
    for(int i=0; i<length; ++i){
        for(int j=i; j<length; ++j){
            if(huiwen(s, i, j)){
                if(j-i > max_length){
                    max_length = j - i;
                    start = i;
                    end = j;
                }
            }
        }
    }
    if(max_length > -1){
        memcpy(strs, &s[start], sizeof(char)*(end-start+1));
        strs[end-start+1] = '\0';
        return strs;
    }
    strs[0] = '\0';
    return strs;
}
