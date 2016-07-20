#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01912(void)
{
    int nNumLen = 0;
    int nResult = 0;
    int *p_nNumList = NULL;
    int *p_nNumDP = NULL;
    scanf("%d", &nNumLen);
    
    p_nNumList = (int*)malloc(sizeof(int)*(nNumLen + 1));
    p_nNumDP = (int*)malloc(sizeof(int)*(nNumLen + 1));
    memset(p_nNumList, 0, sizeof(int)*(nNumLen + 1));
    memset(p_nNumDP, 0, sizeof(int)*(nNumLen + 1));
    for(int i = 1; i <= nNumLen; i++)
    {
        scanf("%d", &p_nNumList[i]);
    }
    nResult = p_nNumList[1];
    for(int i = 1; i <= nNumLen; i++)
    {
        p_nNumDP[i] = p_nNumList[i];
        if(p_nNumDP[i] < p_nNumDP[i - 1] + p_nNumList[i])
        {
            p_nNumDP[i] = p_nNumDP[i - 1] + p_nNumList[i];
        }
        if(nResult < p_nNumDP[i])
        {
            nResult = p_nNumDP[i];
        }
    }

    printf("%d\n", nResult);
    free(p_nNumList);
    free(p_nNumDP);
    return 0;
}