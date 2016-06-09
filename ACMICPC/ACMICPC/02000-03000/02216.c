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
    int **ppnScore_DP = NULL;
    size_t nLenA = 0;
    size_t nLenB = 0;

    scanf("%d %d %d\n", &nScoreMatch, &nScoreBlank, &nScoreMiss);
    scanf("%s\n", szA+1);
    scanf("%s\n", szB+1);
    szA[0] = ' ';
    szB[0] = ' ';
    nLenA = strlen(szA);
    nLenB = strlen(szB);

    ppnScore_DP = (int **)malloc(sizeof(int*)*nLenA);
    for(int i = 0; i < nLenA; i++)
    {
        ppnScore_DP[i] = (int*)malloc(sizeof(int)*nLenB);
        memset(ppnScore_DP[i], 0, sizeof(int)*nLenB);
    }

    for(int i = 0; i < nLenA; i++)
    {
        ppnScore_DP[i][0] = i * nScoreBlank;
    }
    for(int i = 0; i < nLenB; i++)
    {
        ppnScore_DP[0][i] = i * nScoreBlank;
    }

    for(int i = 1; i < nLenA; i++)
    {
        for(int j = 1; j < nLenB; j++)
        {
            if(szA[i] == szB[j])
            {
                ppnScore_DP[i][j] = ppnScore_DP[i - 1][j - 1] + nScoreMatch;
            }
            else
            {
                ppnScore_DP[i][j] = MAX02216(ppnScore_DP[i - 1][j], ppnScore_DP[i][j - 1]) + nScoreBlank;
                ppnScore_DP[i][j] = MAX02216(ppnScore_DP[i][j], ppnScore_DP[i - 1][j - 1] + nScoreMiss);
            }
        }
    }
    printf("%d\n", ppnScore_DP[nLenA-1][nLenB-1]);
    
    for(int i = 0; i < nLenA; i++)
    {
        free(ppnScore_DP[i]);
    }
    free(ppnScore_DP);
    return 0;
}