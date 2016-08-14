#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Problem09252(void)
{
    char szA[1002] = {0,};
    char szB[1002] = {0,};
    char szResult[1002] = {0,};
    int **pp_nAB_DP = NULL;
    size_t nLenA = 0;
    size_t nLenB = 0;
    size_t nLenResult = 0;

    szA[0] = ' ';
    szB[0] = ' ';
    scanf("%s", &szA[1]);
    scanf("%s", &szB[1]);
    nLenA = strlen(szA);
    nLenB = strlen(szB);

    pp_nAB_DP = (int**)malloc(sizeof(int *)*(nLenA + 1));
    for(size_t i = 0; i <= nLenA; i++)
    {
        pp_nAB_DP[i] = (int*)malloc(sizeof(int)*(nLenB + 1));
        memset(pp_nAB_DP[i], 0, sizeof(int)*(nLenB + 1));
    }

    nLenResult = 0;
    for(size_t i = 1; i < nLenA; i++)
    {
        for(size_t j = 1; j < nLenB; j++)
        {
            if(szA[i] == szB[j])
            {
                pp_nAB_DP[i][j] = pp_nAB_DP[i - 1][j - 1] + 1;
            }
            else
            {
                pp_nAB_DP[i][j] = pp_nAB_DP[i - 1][j];
                if(pp_nAB_DP[i][j] < pp_nAB_DP[i][j - 1])
                {
                    pp_nAB_DP[i][j] = pp_nAB_DP[i][j - 1];
                }
            }
        }
    }
    nLenResult = pp_nAB_DP[nLenA - 1][nLenB - 1];
    printf("%zd\n", nLenResult);
    
    for(size_t i = nLenA-1; 0 < i ; i--)
    {
        for(size_t j = nLenB-1; 0 < j ; j--)
        {
            if(szA[i] == szB[j] && nLenResult == pp_nAB_DP[i][j])
            {
                szResult[pp_nAB_DP[i][j] - 1] = szA[i];
                nLenB--;
                nLenResult--;
                break;
            }
        }
    }
    printf("%s\n",szResult);
    for(size_t i = 0; i <= nLenA; i++)
    {
        free(pp_nAB_DP[i]);
    }
    free(pp_nAB_DP);
    return 0;
}