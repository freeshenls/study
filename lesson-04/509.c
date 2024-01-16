#include<stdlib.h>
#include<stdio.h>

int fib(int n){
        if (n==0)
        {
                return 0;
        }

        if (n==1)
        {
                return 1;
        }

        return fib(n-2) + fib(n-1);
}

int main(int argc, char const *argv[])
{
        int result = fib(2);
        printf("%d\n", result);
        result = fib(3);
        printf("%d\n", result);
        result = fib(4);
        printf("%d\n", result);
        result = fib(10);
        printf("%d\n", result);
        return 0;
}
