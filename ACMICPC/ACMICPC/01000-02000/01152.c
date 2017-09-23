#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Problem01152(void)
{
    char cString[1000002] = { 0, };
    int nCount = 0;
    int nLen = 0;
    cString[0] = ' ';
    scanf("%[a-z,A-Z, ]", cString + 1);

    nLen = strlen(cString);
    for (int i = 0; i < nLen - 1; i++)
    {
        if (cString[i] == ' ' &&cString[i + 1] != ' ')
        {
            nCount++;
        }
    }

    printf("%d\n", nCount);
    return 0;
}