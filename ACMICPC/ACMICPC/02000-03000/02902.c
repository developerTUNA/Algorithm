#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int Problem02902(void)
{
    char szString[101] = {0,};
    char szResult[101] = {0,};
    int nStringLen = 0;
    int nResultLen = 0;
    
    scanf("%s", szString);
    nStringLen = (int)strlen(szString);

    for(int i = 0; i < nStringLen; i++)
    {
        if('A' <= szString[i] && szString[i] <= 'Z')
        {
            szResult[nResultLen] = szString[i];
            nResultLen++;
        }
    }
    printf("%s\n", szResult);
    
    return 0;
}