#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *result = (int *)malloc(sizeof(int)*2);
    
    if(result == NULL) return;
    for(int i=0; i<numsSize; ++i){
        for(int j=i+1; j<numsSize; ++j){
            if(target - nums[i] == nums[j]){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}

// // 测试程序
// int main()
// {
//     int nums[4] = {2, 7, 11, 15};
//     int returnSize;
//     int target = 13;
//     int *res = twoSum(nums, 4, target, &returnSize);

//     for(int i=0; i<returnSize; ++i){
//         printf("%d ", res[i]);
//     }

//     return 0;
// }