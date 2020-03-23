
int reverse(int x){
    #define MAX_INT_VALUE (2147483647)
    // 倒过来的数可能超过32位最值
    long xx = x;
    // 保存各位数字，一共多少位
    int nums[10], digits=0;
    // 小于0
    if(xx < 0) xx = -xx;
    // 取出各位，记录位数
    while(xx){
        nums[digits] = xx % 10;
        xx /= 10;
        ++digits;
    }
    // 找低位不为0的索引
    int not0 = 0;
    while(nums[not0] == 0){
        ++not0;
    }
    // 倒组合数字
    long rate = 1;
    for(int i=digits-1; i>=not0; --i){
        xx += nums[i] * rate;
        rate *= 10;
    }
    // 如果超出32位范围，返回0
    if(xx > MAX_INT_VALUE) return 0;
    // 如果小于零则反符号
    if(x < 0) return -xx;
    // 大于等于0则直接返回
    return xx;
}
