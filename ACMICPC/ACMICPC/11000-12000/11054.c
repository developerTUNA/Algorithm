#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem11054(void)
{
    int nNumLen = 0;
    int nResult = 0;
    int *p_nNumList = NULL;
    int *p_nNumUpDP = NULL;
    int *p_nNumDownDP = NULL;

    scanf("%d", &nNumLen);
    p_nNumList = (int*)malloc(sizeof(int)*(nNumLen + 1));
    p_nNumUpDP = (int*)malloc(sizeof(int)*(nNumLen + 1));
    p_nNumDownDP = (int*)malloc(sizeof(int)*(nNumLen + 1));
    memset(p_nNumList, 0, sizeof(int)*(nNumLen + 1));
    memset(p_nNumUpDP, 0, sizeof(int)*(nNumLen + 1));
    memset(p_nNumDownDP, 0, sizeof(int)*(nNumLen + 1));
    
    for(int i = 1; i <= nNumLen; i++)
    {
        scanf("%d", &p_nNumList[i]);
    }

    for(int i = 1; i <= nNumLen; i++)
    {
        p_nNumUpDP[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(p_nNumList[j] < p_nNumList[i] && p_nNumUpDP[i] <= p_nNumUpDP[j])
            {
                p_nNumUpDP[i] = p_nNumUpDP[j] + 1;
            }
        }
    }
    for(int i = nNumLen; 0 < i; i--)
    {
        p_nNumDownDP[i] = 1;
        for(int j = nNumLen; i < j; j--)
        {
            if(p_nNumList[j] < p_nNumList[i] && p_nNumDownDP[i] <= p_nNumDownDP[j])
            {
                p_nNumDownDP[i] = p_nNumDownDP[j] + 1;
            }
        }
    }
    for(int i = 1; i <= nNumLen; i++)
    {
        if(nResult < p_nNumUpDP[i] + p_nNumDownDP[i] - 1)
        {
            nResult = p_nNumUpDP[i] + p_nNumDownDP[i] - 1;
        }
    }

    printf("%d\n", nResult);

    free(p_nNumList);
    free(p_nNumUpDP);
    free(p_nNumDownDP);
    return 0;
}
