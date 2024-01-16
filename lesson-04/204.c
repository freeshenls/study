#include<stdlib.h>
#include<stdio.h>

int isPrime(int num){
        int i = 2;
        for (; i <= num-1; ++i)
        {
                if (num%i == 0)
                {
                        return 0;
                }
        }
        return 1;
}

int countPrimes(int n){
        int count = 1;
        if (n==0 || n==1)
        {
                return 0;        
        }

        if (n==2)
        {
                return 1;        
        }

        for (; 3 <= n; --n)
        {
                if (isPrime(n))
                {
                        printf("%d\n", n);
                        count++;
                }
        }
        return count;
}

int main(int argc, char const *argv[])
{
        int count = countPrimes(10);
        // int count = countPrimes(1);
        // int count = countPrimes(0);
        printf("%d\n", count);
        return 0;
}
