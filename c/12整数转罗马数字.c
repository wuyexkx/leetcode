#include <string.h>


char * intToRoman(int num){  
    char Romes[34][5] = {"","I","II","III","IV","V","VI","VII","VIII","IX", 
                         "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC", 
                         "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM", 
                         "","M","MM","MMM"};                               
    static char results[16]; 
    int nums[4], digits = 0;
    while(num){
        nums[digits++] = num % 10;
        num /= 10;
    }

    int end = 0;
    for(int i=digits-1; i>=0; --i){
            strcpy(results+end, Romes[nums[i] + i*10]);
            end += strlen(Romes[nums[i] + i*10]);
    }
    *(results + end) = '\0';
    return results;
}

// 便于理解的版本
// char * intToRoman(int num){  
//     // 将千百十个位的罗马数对应保存起来，直接用索引取值，""对应位的数字为0的情况
//     char Romes[34][5] = {"","I","II","III","IV","V","VI","VII","VIII","IX", // 1~9      (1~9)
//                          "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC", // 10~90    (11~19)
//                          "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM", // 100~900  (21~29)
//                          "","M","MM","MMM"};                                // 1000~3000(31~33)

//     // 保存结果
//     static char results[16]; 
//     int nums[4], digits = 0;

//     // 取出各位数字保存在nums[], 计算总的位数digits
//     while(num){
//         nums[digits++] = num % 10;
//         num /= 10;
//     }

//     int end = 0;
//     for(int i=digits-1; i>=0; --i){
//         // 处理千位 1000~3000
//         if(i == 3){
//             strcpy(results, Romes[nums[i] + 30]);
//             end += strlen(Romes[nums[i] + 30]);
//         }
//         // 处理百位 100~900
//         else if(i == 2){
//             strcpy(results+end, Romes[nums[i] + 20]);
//             end += strlen(Romes[nums[i] + 20]);
//         }
//         // 处理十位 10~90
//         else if( i == 1){
//             strcpy(results+end, Romes[nums[i] + 10]);
//             end += strlen(Romes[nums[i] + 10]);            
//         }
//         // 处理个位 0~9
//         else if( i == 0){
//             strcpy(results+end, Romes[nums[i] + 0]);
//             end += strlen(Romes[nums[i] + 0]);            
//         }
//     }
//     // 字符结束符
//     *(results + end) = '\0';
//     return results;
// }