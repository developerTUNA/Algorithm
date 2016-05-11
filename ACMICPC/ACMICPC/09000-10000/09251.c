#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Problem09251(void)
{
    char szRow[1002] = {0,};
    char szCol[1002] = {0,};
    int nMaxLen = 0;
    int **pp_nAB_DP = NULL;
    size_t nLenA = 0;
    size_t nLenB = 0;
    
    szRow[0] = ' ';
    szCol[0] = ' ';
    scanf("%s", &szRow[1]);
    scanf("%s", &szCol[1]);
    nLenA = strlen(szRow);
    nLenB = strlen(szCol);

    pp_nAB_DP = (int**)malloc(sizeof(int *)*(nLenA+1));
    for(int i = 0; i <= nLenA; i++)
    {
        pp_nAB_DP[i] = (int*)malloc(sizeof(int)*(nLenB+1));
        memset(pp_nAB_DP[i], 0, sizeof(int)*(nLenB+1));
    }

    nMaxLen = 0;
    for(int i = 1; i < nLenA; i++)
    {
        for(int j = 1; j < nLenB; j++)
        {
            if(szRow[i] == szCol[j])
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
    printf("%d\n", pp_nAB_DP[nLenA-1][nLenB-1]);

    for(int i = 0; i <= nLenA; i++)
    {
        free(pp_nAB_DP[i]);
    }
    free(pp_nAB_DP);
    return 0;
}