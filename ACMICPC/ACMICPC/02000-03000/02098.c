#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX02098(a,b) ((a)<(b))?(b):(a)
#define MIN02098(a,b) ((a)<(b))?(a):(b)

int Problem02098(void)
{
    int nCity = 0;
    int nResult = 0;
    int **pp_nCost = NULL;
    int **pp_nCost_DP = NULL;

    scanf("%d", &nCity);
    pp_nCost = (int**)malloc(sizeof(int*)*(nCity));
    for(int i = 0; i < nCity; i++)
    {
        pp_nCost[i] = (int*)malloc(sizeof(int)*(nCity ));
        memset(pp_nCost[i], 0, sizeof(int)*(nCity ));
    }
    pp_nCost_DP = (int**)malloc(sizeof(int*)*(1<<nCity));
    for(int i = 0; i < (1<<nCity); i++)
    {
        pp_nCost_DP[i] = (int*)malloc(sizeof(int)*(nCity));
        memset(pp_nCost_DP[i], 0, sizeof(int)*(nCity));
    }

    for(int i = 0; i < nCity; i++)
    {
        for(int j = 0; j < nCity; j++)
        {
            scanf("%d", &pp_nCost[i][j]);
        }
    }
    for(int i = 0; i < (1<<nCity); i++)
    {
        for(int j = 0; j < nCity; j++)
        {
            pp_nCost_DP[i][j] = (2 << 29) - 1;
        }
    }

    pp_nCost_DP[1][0] = 0;
    for(int i = 0; i < (1 << nCity); i++)
    {
        for(int j = 1; j < nCity; j++)
        {
            if(i & (1 << j))
            {
                for(int k = 0; k < nCity; k++)
                {
                    if(k != j && (i&(1 << k)) && pp_nCost[k][j])
                    {
                        pp_nCost_DP[i][j] = MIN02098(pp_nCost_DP[i][j], pp_nCost_DP[i - (1 << j)][k] + pp_nCost[k][j]);
                    }
                }
            }
        }
    }

    nResult =  (2 << 29) - 1;
    for(int i = 1; i < nCity; i++)
    {
        if(pp_nCost[i][0])
        {
            nResult = MIN02098(nResult, pp_nCost_DP[(1 << nCity) - 1][i] + pp_nCost[i][0]);
        }
    }

    printf("%d\n", nResult);
    for(int i = 0; i < nCity; i++)
    {
        free(pp_nCost[i]);
    }
    free(pp_nCost);
    return 0;
}