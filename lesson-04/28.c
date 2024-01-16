#include<stdlib.h>
#include<stdio.h>

int strStr(char * haystack, char * needle){
        int index = -1;

        if (strlen(haystack)==0 && strlen(needle)==0)
        {
                return 0;
        }

        int i = 0;
        for (; i < strlen(haystack); ++i)
        {
                if (strlen(needle)==0)
                {
                        return 0 ;
                }

                int j = 0;
                for (; j < strlen(needle); ++j)
                {
                        if (haystack[i+j] != '\0' && needle[j] == haystack[i+j])
                        {
                                if (index == -1)
                                {
                                        index = i;
                                }
                        } else {
                                index = -1;
                                break;
                        }
                }
                if (index != -1)
                {
                        return index;
                }
        }
        return -1;
}

int main(int argc, char const *argv[])
{
        int index = strStr("hellohello", "ll"); //2
        printf("%d\n", index);
        
        index = strStr("hello", "ll"); //2
        printf("%d\n", index);

        index = strStr("aaaaa", "bba"); //-1
        printf("%d\n", index);

        index = strStr("aaaaa", ""); //0
        printf("%d\n", index);

        index = strStr("", ""); //0
        printf("%d\n", index);
        return 0;
}
