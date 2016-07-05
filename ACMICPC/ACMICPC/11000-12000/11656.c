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

size_t QuickSortPartion11656(char arr_szStringSub[1001][1001], size_t llnLeft, size_t llnRight)
{
    size_t llnPivot = 0;
    size_t llnStore = 0;
    llnPivot = (llnLeft + llnRight) / 2;
    StringSwap11656(arr_szStringSub[llnPivot], arr_szStringSub[llnRight]);
    llnStore = llnLeft;
    for(size_t i = llnLeft; i < llnRight; i++)
    {
        if(strcmp(arr_szStringSub[i], arr_szStringSub[llnRight]) < 0)
        {
            StringSwap11656(arr_szStringSub[i], arr_szStringSub[llnStore]);
            llnStore++;
        }
    }
    StringSwap11656(arr_szStringSub[llnStore], arr_szStringSub[llnRight]);
    return llnStore;
}

int QuickSort11656(char arr_szStringSub[1001][1001], size_t llnLeft, size_t llnRight)
{
    size_t llnPartion = 0;
    if(llnLeft < llnRight)
    {
        llnPartion = QuickSortPartion11656(arr_szStringSub, llnLeft, llnRight);
        QuickSort11656(arr_szStringSub, llnLeft, llnPartion-1);
        QuickSort11656(arr_szStringSub, llnPartion+1, llnRight);
    }
    return 0;
}


int Problem11656(void)
{
    char szStringOrg[1001] = {0,};
    char arr_szStringSub[1001][1001] = {0,};
    size_t llnStringLen = 0;

    scanf("%s", szStringOrg);
    llnStringLen = strlen(szStringOrg);
    for(int i = 0; i < llnStringLen; i++)
    {
        strncpy(arr_szStringSub[i], szStringOrg + i, llnStringLen - i);
    }
    QuickSort11656(arr_szStringSub, 0, llnStringLen-1);

    for(int i = 0; i < llnStringLen; i++)
    {
        printf("%s\n", arr_szStringSub[i]);
    }
    return 0;
}
