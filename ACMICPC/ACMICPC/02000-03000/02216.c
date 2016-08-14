#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX02216(a,b) (((a) < (b)) ? (b) : (a))

int Problem02216(void)
{
    char szA[3002] = {0,};
    char szB[3002] = {0,};
    int nScoreMatch = 0;
    int nScoreBlank = 0;
    int nScoreMiss = 0;
    int **pp_nScore_DP = NULL;
    size_t nLenA = 0;
    size_t nLenB = 0;

    scanf("%d %d %d\n", &nScoreMatch, &nScoreBlank, &nScoreMiss);
    scanf("%s\n", szA+1);
    scanf("%s\n", szB+1);
    szA[0] = ' ';
    szB[0] = ' ';
    nLenA = strlen(szA);
    nLenB = strlen(szB);

    pp_nScore_DP = (int **)malloc(sizeof(int*)*nLenA);
    for(size_t i = 0; i < nLenA; i++)
    {
        pp_nScore_DP[i] = (int*)malloc(sizeof(int)*nLenB);
        memset(pp_nScore_DP[i], 0, sizeof(int)*nLenB);
    }

    for(size_t i = 0; i < nLenA; i++)
    {
        pp_nScore_DP[i][0] = i * nScoreBlank;
    }
    for(size_t i = 0; i < nLenB; i++)
    {
        pp_nScore_DP[0][i] = i * nScoreBlank;
    }

    for(size_t i = 1; i < nLenA; i++)
    {
        for(size_t j = 1; j < nLenB; j++)
        {
            if(szA[i] == szB[j])
            {
                pp_nScore_DP[i][j] = pp_nScore_DP[i - 1][j - 1] + nScoreMatch;
            }
            else
            {
                pp_nScore_DP[i][j] = MAX02216(pp_nScore_DP[i - 1][j], pp_nScore_DP[i][j - 1]) + nScoreBlank;
                pp_nScore_DP[i][j] = MAX02216(pp_nScore_DP[i][j], pp_nScore_DP[i - 1][j - 1] + nScoreMiss);
            }
        }
    }
    printf("%d\n", pp_nScore_DP[nLenA-1][nLenB-1]);
    
    for(size_t i = 0; i < nLenA; i++)
    {
        free(pp_nScore_DP[i]);
    }
    free(pp_nScore_DP);
    return 0;
}