


// 暴力法，求出每条边与其他所有边矩形的面积，选出最大的面积
int maxArea(int* height, int heightSize){
    int length, width, result = 0;
    for(int i=0; i<heightSize; ++i){
        for(int j=i+1; j<heightSize; ++j){
            width = j - i;
            length = height[i] < height[j] ? height[i] : height[j];
            result = length * width > result ? length * width : result;
        }
    }
    return result;
}

// 双指针法，一个头一个尾，计算面积，短边移动。
// 对于第一个矩形来说，矮边已经决定这个矩形的高度，只能通过增加宽度来增大面积，
//  但是已经宽度已经是最宽了，所以舍弃矮边，依次往下计算。
// 牛人讲解：https://leetcode-cn.com/problems/container-with-most-water/solution/on-shuang-zhi-zhen-jie-fa-li-jie-zheng-que-xing-tu/
// int maxArea(int* height, int heightSize){
//     int length, width, result = 0;
//     for(int i=0, j=heightSize-1; i<j; ){
//         width = j - i;
//         // 最短边为高，移动指针
//         length = height[i] < height[j] ? height[i++] : height[j--];
//         result = length * width > result ? length * width : result;
//     }
//     return result;
// }
