#include <stdio.h>
int stringLength(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}
int patternExists(const char *str, const char *pattern)
{
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        j = 0;
        while (pattern[j] != '\0' && str[i + j] == pattern[j])
        {
            j++;
        }
        if (pattern[j] == '\0')
        {
            return i;
        }
        i++;
    }
    return -1;
    ﻿
// output
// Enter the main string: rnsitrnsitrnsit
// Enter the pattern string:r
// Enter the replace string:R
// Pattern not found in the main string. 
// Modified String: RnsitRnsitRnsit
}
void findAndReplace(char *str, const char *pattern, const char *replace)
{
    int patLen = stringLength(pattern);
    int repLen = stringLength(replace);
    int strLen = stringLength(str);
    int index = patternExists(str, pattern);
    while (index != -1)
    {
        for (int i = 0; i < repLen; i++)
        {
            str[index + i] = replace[i];
        }
        strLen = stringLength(str);
        index = patternExists(str, pattern);
    }
    if (index == -1)
    {
        printf("Pattern not found in the main string.\n");
    }
}
int main()
{
    char mainString[100], pattern[50], replace[50];
    printf("Enter the main string: \n");
    scanf(" %s", mainString);
    printf("Enter the pattern string:\n ");
    scanf(" %s", pattern);
    printf("Enter the replace string: \n");
    scanf(" %s", replace);
    findAndReplace(mainString, pattern, replace);
    printf("Modified String: %s\n", mainString);
    return 0;
}
