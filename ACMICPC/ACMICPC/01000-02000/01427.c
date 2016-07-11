#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
int InsertSort01427(char *szNum, int nSize)
{
    char cTemp = 0;
    int nPoz = 0;
    for(int i = 1; i < nSize; i++)
    {
        cTemp = szNum[i];
        int j = 0;
        j = i - 1;
        while(0 <= j && szNum[j] < cTemp)
        {
            szNum[j + 1] = szNum[j];
            j = j - 1;
        }
        szNum[j + 1] = cTemp;
    }
    return 0;
}

int Problem01427(void)
{
    char szNum[11] = {0,};
    int nSize = 0;
    scanf("%s", szNum);
    nSize = strlen(szNum);
    InsertSort01427(szNum, nSize);

    printf("%s", szNum);
    return 0;
}