#include<stdlib.h>
#include<stdio.h>

int wiggleMaxLength(int* nums, int numsSize){
        if (numsSize == 1)
        {
                return 1;
        }

        if (numsSize == 2)
        {
                if (nums[0] != nums[1])
                {
                        return 2;
                }
                return 1;
        }

        int index = 1;
        int wiggleNums[1000] = {nums[0], nums[1]};
        int i = 2;
        for (; i < numsSize; ++i)
        {
                // printf("%d\n", wiggleNums[index]);
                if ((wiggleNums[index] > wiggleNums[index-1] && wiggleNums[index] > nums[i]) || (wiggleNums[index] < wiggleNums[index-1] && wiggleNums[index] < nums[i]))
                {
                        wiggleNums[++index] = nums[i];
                }
        }
        return index+1;
}

int main(int argc, char const *argv[])
{
        // int nums[] = {1,7,4,9,2,5}; //6
        int nums[] = {1,17,5,10,13,15,10,5,16,8}; //7
        int numsSize = sizeof(nums)/sizeof(int);

        int length = wiggleMaxLength((int*)nums, numsSize);
        printf("%d\n", length);
        return 0;
}
