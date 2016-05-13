#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem11060(void)
{
    int nLen = 0;
    int nJump = 0;
    int *p_nNum = NULL;
    int *p_DP = NULL;

    scanf("%d", &nLen);
    p_nNum = (int*)malloc(sizeof(int)*nLen);
    p_DP = (int*)malloc(sizeof(int)*nLen);
    memset(p_nNum, 0, sizeof(int)*nLen);
    memset(p_DP, 0, sizeof(int)*nLen);

    for(int i = 0; i < nLen; i++)
    {
        scanf("%d", &p_nNum[i]);
    }
    p_DP[0] = 1;

    for(int i = 0; i < nLen; i++)
    {
        nJump = p_nNum[i];
        for(int j = i+1; j <= i + nJump; j++)
        {
            if(j < nLen)
            {
                if(p_DP[i] + 1 < p_DP[j] || p_DP[j] == 0 && p_DP[i] != 0)
                {
                    p_DP[j] = p_DP[i] + 1;
                }
            }
        }
    }
    
    if (p_DP[nLen - 1])
    {
        printf("%d\n", p_DP[nLen - 1]-1);
    }
    else
    {
        printf("-1\n");
    }
    free(p_nNum);
    free(p_DP);
    return 0;
}