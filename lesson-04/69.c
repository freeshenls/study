#include<stdlib.h>
#include<stdio.h>

int mySqrt(int x){
        int min = 1;
        int max = x;
        int mid = 0;

        if (x==0)
        {
                return 0;
        }

        if (x==1)
        {
                return 1;
        }

        while(min<=max){
                mid = min+(max-min)/2;
                // printf("======%d\n", mid);
                if (mid * mid<x)
                {
                        min=mid + 1;
                }else if (mid * mid>x) {
                        max=mid -1;
                } else {
                        return mid;
                }
        }
        return max;
}


int main(int argc, char const *argv[])
{
        int result = mySqrt(0);
        printf("%d\n", result);
        result = mySqrt(1);
        printf("%d\n", result);
        result = mySqrt(8);
        printf("%d\n", result);
        result = mySqrt(9);
        printf("%d\n", result);
        result = mySqrt(1001);
        printf("%d\n", result);
        return 0;
}
