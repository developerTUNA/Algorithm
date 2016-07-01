#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02092(void)
{
    int nTemp = 0;
    int nResult = 0;
    int nNumBig = 0;    //가장 큰 수
    int nNumCount = 0;  //수의 개수
    int nNumStart = 0;  //집합 최소 갯수
    int nNumEnd = 0;    //집합 최대 갯수
    int *p_nNumCount = NULL;
    int **pp_nDP = NULL;
    scanf("%d %d %d %d", &nNumBig, &nNumCount, &nNumStart, &nNumEnd);
    p_nNumCount = malloc(sizeof(int)*(nNumBig + 1));
    memset(p_nNumCount, 0, sizeof(int)*(nNumBig + 1));
    pp_nDP = malloc(sizeof(int*)*(nNumBig + 1));
    for(int i = 0; i < (nNumBig + 1); i++)
    {
        pp_nDP[i] = malloc(sizeof(int)*(nNumCount + 1));
        memset(pp_nDP[i], 0, sizeof(int)*(nNumCount + 1));
    }
    for(int i = 0; i < nNumCount; i++)
    {
        scanf("%d", &nTemp);
        p_nNumCount[nTemp]++;
    }

    for(int i = 0; i <= p_nNumCount[1]; i++)
    {
        pp_nDP[1][i] = 1;
    }

    for(int i = 2; i <= nNumBig; i++)
    {
        pp_nDP[i][0] = 1;
        for(int j = 1; j <= nNumCount; j++)
        {
            for(int k = 0; k <= p_nNumCount[i]; k++)
            {
                if(0 <= j - k)
                {
                    pp_nDP[i][j] += pp_nDP[i - 1][j - k];
                    pp_nDP[i][j] %= 1000000;
                }
            }
        }
    }
    for(int i = nNumStart; i <= nNumEnd; i++)
    {
        nResult += pp_nDP[nNumBig][i];
        nResult %= 1000000;
    }

    printf("%d\n", nResult);

    free(p_nNumCount);
    for(int i = 0; i < (nNumBig + 1); i++)
    {
        free(pp_nDP[i]);
    }
    free(pp_nDP);
    return 0;
}