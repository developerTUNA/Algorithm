#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int StringSwap11656(char szA[1001], char szB[1001])
{
    char szStringTemp[1001] = {0,};
    strcpy(szStringTemp, szA);
    strcpy(szA, szB);
    strcpy(szB, szStringTemp);
    return 0;
}

int QuickSortPartion11656(char a_szStringSub[1001][1001], int nLeft, int nRight)
{
    int nPivot = 0;
    int nStore = 0;
    nPivot = (nLeft + nRight) / 2;
    StringSwap11656(a_szStringSub[nPivot], a_szStringSub[nRight]);
    nStore = nLeft;
    for(int i = nLeft; i < nRight; i++)
    {
        if(strcmp(a_szStringSub[i], a_szStringSub[nRight]) < 0)
        {
            StringSwap11656(a_szStringSub[i], a_szStringSub[nStore]);
            nStore++;
        }
    }
    StringSwap11656(a_szStringSub[nStore], a_szStringSub[nRight]);
    return nStore;
}

int QuickSort11656(char a_szStringSub[1001][1001], int nLeft, int nRight)
{
    int nPartion = 0;
    if(nLeft < nRight)
    {
        nPartion = QuickSortPartion11656(a_szStringSub, nLeft, nRight);
        QuickSort11656(a_szStringSub, nLeft, nPartion-1);
        QuickSort11656(a_szStringSub, nPartion+1, nRight);
    }
    return 0;
}


int Problem11656(void)
{
    char szStringOrg[1001] = {0,};
    char a_szStringSub[1001][1001] = {0,};
    int nStringLen = 0;

    scanf("%s", szStringOrg);
    nStringLen = (int)strlen(szStringOrg);
    for(int i = 0; i < nStringLen; i++)
    {
        strncpy(a_szStringSub[i], szStringOrg + i, nStringLen - i);
    }
    QuickSort11656(a_szStringSub, 0, nStringLen-1);

    for(int i = 0; i < nStringLen; i++)
    {
        printf("%s\n", a_szStringSub[i]);
    }
    return 0;
}
