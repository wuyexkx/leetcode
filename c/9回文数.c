
// 题目中要求判断负数，直接就是false
bool isPalindrome(int x){
    if(x < 0) return false;
    if(x < 10) return true;

    int nums[10], xx = x, digits = 0;
    while(xx){
        nums[digits++] = xx % 10;
        xx /= 10;
    }
    for(int i=0, j=digits-1; i < j; ++i, --j){
        if(nums[i] != nums[j]) return false;
    }
    return true;
}