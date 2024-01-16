#include<stdlib.h>
#include<stdio.h>

int maxSubArray(int* nums, int numsSize)
{
        int max = nums[0];
        int start = nums[0];
        int i = 1;
        for (; i < numsSize; ++i)
        {
                start = nums[i] >= start ? nums[i] : start + nums[i];
                if (max <= start)
                {
                        max = start;
                }
        }
        return max;
}

int main(int argc, char const *argv[])
{
        // int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; //6
        // int nums[] = {1}; //1
        int nums[] = {5, 4, -1, 7, 8}; //23

        int max = maxSubArray((int*)nums, sizeof(nums)/sizeof(int));
        printf("%d\n", max);
        return 0;
}
