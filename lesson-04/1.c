#include<stdlib.h>
#include<stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
        int i = 0;
        int* resultNums = (int*)malloc(2 * sizeof(int));
        for (; i < numsSize; ++i)
        {
                int j = i + 1;
                for (; j < numsSize; ++j)
                {
                        if (target == nums[i] + nums[j])
                        {
                                resultNums[0] = i;
                                resultNums[1] = j;
                                *returnSize = 2;
                                return resultNums;
                        }
                }
        }
        return resultNums;
}

int main(int argc, char const *argv[])
{
        int* returnSize = (int*)malloc(sizeof(int));
        int *nums = (int*)malloc(4 * sizeof(int));
        nums[0] = 2;
        nums[1] = 7;
        nums[2] = 11;
        nums[3] = 15;
        int* resultNums = twoSum(nums, 4, 9, returnSize);
        printf("%d: 9 = %d + %d\n", *returnSize, nums[resultNums[0]], nums[resultNums[1]]);
        free(nums);
        free(resultNums);

        nums = (int*)malloc(3 * sizeof(int));
        nums[0] = 3;
        nums[1] = 2;
        nums[2] = 4;
        resultNums = twoSum(nums, 3, 6, returnSize);
        printf("%d: 6 = %d + %d\n", *returnSize, nums[resultNums[0]], nums[resultNums[1]]);
        free(nums);
        free(resultNums);

        nums = (int*)malloc(2 * sizeof(int));
        nums[0] = 3;
        nums[1] = 3;
        resultNums = twoSum(nums, 2, 6, returnSize);
        printf("%d: 6 = %d + %d\n", *returnSize, nums[resultNums[0]], nums[resultNums[1]]);
        free(nums);
        free(resultNums);

        free(returnSize);
        return 0;
}
