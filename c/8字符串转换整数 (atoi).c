
int myAtoi(char * str){
    #define MAX_32_VALUE (2147483647)
    #define MIN_32_VALUE (-2147483648)
    // 保存有效数字索引 和 符号
    int start = 0 , end = 0, sign = 0;      
    // 先去除空格，更新索引
    while(str[start] == ' '){               // "  -123"
        end = ++start;
    }
    // 查看是否为符号，更新索引 及 符号标志
    if(str[start] == '-'){                  // "  -123"
        start = end = start + 1;
        sign = 1;
    } 
    else if(str[start] == '+'){             // "  +123"  
        start = end = start + 1;
    } 
    // 如果接下来的字符不是0~9,那么直接返回0      "  -qwert"
    if(!(str[start] >= '0' && str[start] <= '9')) 
        return 0;
    // 去掉前面的0，更新索引，                   "000000001234"
    while(str[start] == '0'){
        end = ++start;
    }
    // 寻找有效数字的区间，更新end
    while(str[end] >= '0' && str[end] <= '9'){
        ++end;
    }

    // 如果长度超过有符号32位最值，返回最值，防止后面计算大范围溢出。如"200000000000000000000"
    if(sign && end - start > 10) return MIN_32_VALUE;   // "-2147483648 ~ 2147483647"
    if(!sign && end - start > 10) return MAX_32_VALUE;  //     都是10位数字

    // 算出这个数字，long防溢出
    long rate = 1, result = 0;
    for(int i=end-1; i>=start; --i){
        result += (str[i] - '0') * rate;
        rate *= 10;
    }

    // 根据符号标志 和 这个数的范围 返回这个数
    if(sign){
        if(-result >= MIN_32_VALUE) return -result;
        else return MIN_32_VALUE;
    } else {
        if(result <= MAX_32_VALUE) return result;
        else return MAX_32_VALUE;        
    }
}