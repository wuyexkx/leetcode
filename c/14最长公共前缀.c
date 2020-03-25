#include <stdlib.h>
#include <string.h>

// 水平扫描
char * longestCommonPrefix(char ** strs, int strsSize){

    // 只有一个或者空的情况
    if(strsSize == 1) return strs[0];
    if(strsSize == 0) return "";

    // 找到最短的字符串并记录位置和长度
    int min_size = strlen(strs[0]), min_index = 0;
    for(int i=0; i<strsSize; ++i){
        if(strlen(strs[i]) < min_size){
            min_size = strlen(strs[i]);
            min_index = i;
        }
    }
    // 扫描相同的字符  以最短的字符串为基准, 
    //  外层for控制第res_size个字符, 内层for控制第i个字符串, 最终重复长度保存在res_size
    int res_size = 0;
    for(; res_size<min_size; ++res_size){
        int flag = 0;
        char temp = strs[min_index][res_size];
        for(int i=0; i<strsSize; ++i){
            if(temp != (strs[i][res_size])){
                flag = 1;
                break;
            } 
        } 
        if(flag) break;
    }

    // 处理重复长度结果res_size
    //  如果res_size为0
    if(!res_size) return "";
    //  如果res_size不为0
    char *result = malloc(sizeof(char) * (min_size + 1));
    memcpy(result, strs[min_index], sizeof(char) * res_size);
    result[res_size] = '\0';
    return result;
}