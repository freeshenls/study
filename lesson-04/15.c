#include<stdlib.h>
#include<stdio.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    return NULL;
}

int main(int argc, char const *argv[])
{
    int nums[] = {-1,0,1,2,-1,4};
    // int nums[] = {0,1,1}
    // int *nums = {0,0,0}
    int *returnSize = (int*)malloc(sizeof(int));
    int** returnColumnSizes;

    threeSum(nums, sizeof(nums)/sizeof(int), returnSize, returnColumnSizes);
    free(returnSize);
    return 0;
}
