#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Problem05582(void)
{
    int nMaxLen = 0;
    int **pp_nAB_DP = NULL;
    size_t nLenA = 0;
    size_t nLenB = 0;

    scanf("%s", szA);
    scanf("%s", szB);
    nLenA = strlen(szA);
    nLenB = strlen(szB);

    pp_nAB_DP = (int**)malloc(sizeof(int *)*nLenA);
    for(int i = 0; i < nLenA; i++)
    {
        pp_nAB_DP[i] = (int*)malloc(sizeof(int)*nLenB);
        memset(pp_nAB_DP[i], 0, sizeof(int)*nLenB);
    }

    nMaxLen = 0;
    for(int i = 0; i < nLenA; i++)
    {
        for(int j = 0; j < nLenB; j++)
        {
            if(szA[i] == szB[j])
            {
                if(0 <= i - 1 && 0 <= j - 1 &&
                   szA[i - 1] == szB[j - 1])
                {
                    pp_nAB_DP[i][j] = pp_nAB_DP[i - 1][j - 1] + 1;
                }
                else
                {
                    pp_nAB_DP[i][j] = 1;
                }
                if(nMaxLen < pp_nAB_DP[i][j])
                {
                    nMaxLen = pp_nAB_DP[i][j];
                }
            }
        }
    }
    printf("%d\n", nMaxLen);
    
    for(int i = 0; i < nLenA; i++)
    {
        free(pp_nAB_DP[i]);
    }
    free(pp_nAB_DP);
    return 0;
}
