#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem11053(void)
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
    for (int i = 1; i <= nNumLen; i++)
    {
        scanf("%d", &p_nNumList[i]);
    }

    for (int i = 1; i <= nNumLen; i++)
    {
        p_nNumDP[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (p_nNumList[j] < p_nNumList[i] && p_nNumDP[i]<= p_nNumDP[j])
            {
                p_nNumDP[i] = p_nNumDP[j] + 1;
            }
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