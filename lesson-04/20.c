#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool isValid(char * s){
        if (strlen(s) == 0)
        {
                return true;
        }

        if (strlen(s) == 1)
        {
                return false;
        }

        int i = 1;
        for (; i < strlen(s); ++i)
        {
                if ((s[i] == ')' && s[i - 1] == '(') || (s[i] == ']' && s[i - 1] == '[') || (s[i] == '}' && s[i - 1] == '{'))
                {
                        char temp[sizeof(s) - 2 * sizeof(char)] = {0};
                        int j = 0;
                        for (; j < i - 1; ++j)
                        {
                                temp[j] = s[j];
                        }
                        strcat(temp, s + i + 1);
                        return isValid((char*)temp);
                }
        }
        return false;
}

int main(int argc, char const *argv[])
{
        // char * result = "()";
        // char * result2 = "()";

        // char temp[2 * sizeof(char)] = {0};
        // strcat(temp, result+1);
        // strcat(temp, result2+1);
        // printf("%d\n", strlen(temp));
        // printf("%p\n", &temp);
        // printf("%s\n", temp);

        bool result = isValid("()");
        printf("%d\n", result);
        result = isValid("()[]{}");
        printf("%d\n", result);
        // false
        result = isValid("(]");
        printf("%d\n", result);
        // false
        result = isValid("([)]");
        printf("%d\n", result);
        result = isValid("{[]}");
        printf("%d\n", result);
        return 0;
}
