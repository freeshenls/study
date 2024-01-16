#include<stdlib.h>
#include<stdio.h>

int* shortestToChar(char * s, char c, int* returnSize)
{
        *returnSize = strlen(s);
        int* result = (int*)malloc(*returnSize * sizeof(int));

        int i = 0;
        for (; i < *returnSize; ++i)
        {
                if (s[i] != c)
                {
                        continue;
                }

                result[i] = 0;
                int addj = i;
                int subj = i;
                printf("i====%d\n", i);

                while(subj-- > 0){
                        if (s[subj] == c)
                        {
                                break;
                        }
                        // printf("subj====%d\n", subj);
                        if (result[subj] == 0 || result[subj] > i - subj)
                        {
                                result[subj] = i - subj;
                        }
                        // printf("result-subj====%d\n", result[subj]);

                }

                while(addj++ < *returnSize){
                        if (s[addj] == c)
                        {
                                break;
                        }
                        // printf("addj====%d\n", addj);
                        if (result[addj] == 0 || result[addj] > addj - i)
                        {
                                result[addj] = addj - i;
                        }
                        // printf("result-addj====%d\n", result[addj]);
                }

        }
        return result;
}

int main(int argc, char const *argv[])
{
        // char * s = "loveleetcode";
        // char * c = "e";
        char * s = "aaab";
        char * c = "b";

        int* returnSize = (int*)malloc(sizeof(int));

        int* result = shortestToChar(s, c[0], returnSize);
        int i = 0;
        for (; i < *returnSize; ++i)
        {
                printf("%d\n", result[i]);
        }
        free(result);
        free(returnSize);
        return 0;
}
