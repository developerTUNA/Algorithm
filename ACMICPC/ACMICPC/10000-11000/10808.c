#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int Problem10808(void)
{
    char szString[101] = {0,};
    int arr_nCount[26] = {0,};
    int nStringLen = 0;
    
    scanf("%s", szString);
    nStringLen = strlen(szString);

    for(int i = 0; i < nStringLen; i++)
    {
        arr_nCount[szString[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        printf("%d ", arr_nCount[i]);
    }
    return 0;
}