#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int Problem10808(void)
{
    char szString[101] = {0,};
    int a_nCount[26] = {0,};
    size_t llnStringLen = 0;
    
    scanf("%s", szString);
    llnStringLen = strlen(szString);

    for(size_t i = 0; i < llnStringLen; i++)
    {
        a_nCount[szString[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        printf("%d ", a_nCount[i]);
    }
    return 0;
}