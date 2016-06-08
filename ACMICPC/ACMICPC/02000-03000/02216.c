#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02216(void)
{
    char szA[3001] = {0,};
    char szB[3001] = {0,};
    int nLenA = 0;
    int nLenB = 0;
    int nScoreMatch = 0;
    int nScoreBlank = 0;
    int nScoreMiss = 0;
    int nScorePass = 0;
    int **ppnScore_DP = NULL;

    scanf("%d %d %d", &nScoreMatch, &nScoreBlank, &nScoreMiss);
    scanf("%s", szA);
    scanf("%s", szB);
    nLenA = strlen(szA);
    nLenB = strlen(szB);

    ppnScore_DP = (int **)malloc(sizeof(int*)*nLenA);
    for(int i = 0; i < nLenA; i++)
    {
        ppnScore_DP[i] = (int*)malloc(sizeof(int)*nLenB);
        memset(ppnScore_DP[i], 0, sizeof(int)*nLenB);
    }

    nScorePass = nScoreBlank;
    if(nScoreBlank < nScoreMiss)
    {
        nScorePass = nScoreMiss;
    }

    for(int i = 0; i < nLenA; i++)
    {
        for(int j = 0; j < nLenB; j++)
        {
            if(szA[i] == szB[j] && 0 <= i - 1 && 0 <= j - 1)
            {
                ppnScore_DP[i][j] = ppnScore_DP[i - 1][j - 1] + nScoreMatch;
            }
            else
            {
                if(0 <= i - 1 && 0 <= j - 1 && ppnScore_DP[i][j - 1] < ppnScore_DP[i - 1][j])
                {
                    ppnScore_DP[i][j] = ppnScore_DP[i - 1][j] + nScorePass;
                }
                else
                {
                    if(0 <= j - 1)
                    {
                        ppnScore_DP[i][j] = ppnScore_DP[i][j - 1] + nScorePass;
                    }
                    else{
                        ppnScore_DP[i][j] = 2 * nScorePass;
                    }
                }
            }
        }
    }
    return 0;
}