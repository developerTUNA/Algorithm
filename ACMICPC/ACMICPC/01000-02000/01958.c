#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Problem01958(void)
{
    char szA[102] = {0,};
    char szB[102] = {0,};
    char szC[102] = {0,};
    char szResult[102] = {0,};
    int ***ppp_nLCS_DP = NULL;
    size_t nLenA = 0;
    size_t nLenB = 0;
    size_t nLenC = 0;
    size_t nLenResult = 0;

    szA[0] = ' ';
    szB[0] = ' ';
    szC[0] = ' ';
    scanf("%s", &szA[1]);
    scanf("%s", &szB[1]);
    scanf("%s", &szC[1]);
    nLenA = strlen(szA);
    nLenB = strlen(szB);
    nLenC = strlen(szC);

    ppp_nLCS_DP = (int***)malloc(sizeof(int **)*(nLenA + 1));
    for(int i = 0; i <= nLenA; i++)
    {
        ppp_nLCS_DP[i] = (int**)malloc(sizeof(int*)*(nLenB + 1));
        for(int j = 0; j <= nLenB; j++)
        {
            ppp_nLCS_DP[i][j] = (int*)malloc(sizeof(int)*(nLenC + 1));
            memset(ppp_nLCS_DP[i][j], 0, sizeof(int)*(nLenC + 1));
        }
    }


    for(int i = 1; i < nLenA; i++)
    {
        for(int j = 1; j < nLenB; j++)
        {
            for(int k = 1; k < nLenC; k++)
            {
                if(szA[i] == szB[j] && szB[j] == szC[k])
                {
                    ppp_nLCS_DP[i][j][k] = ppp_nLCS_DP[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    ppp_nLCS_DP[i][j][k] = ppp_nLCS_DP[i - 1][j][k];
                    if(ppp_nLCS_DP[i][j][k] < ppp_nLCS_DP[i][j - 1][k])
                    {
                        ppp_nLCS_DP[i][j][k] = ppp_nLCS_DP[i][j - 1][k];
                    }
                    if(ppp_nLCS_DP[i][j][k] < ppp_nLCS_DP[i][j][k - 1])
                    {
                        ppp_nLCS_DP[i][j][k] = ppp_nLCS_DP[i][j][k - 1];
                    }
                }
            }
        }
    }
    nLenResult = ppp_nLCS_DP[nLenA - 1][nLenB - 1][nLenC - 1];
    printf("%zd\n", nLenResult);

    for(int i = 0; i <= nLenA; i++)
    {
        for(int j = 0; j <= nLenB; j++)
        {
            free(ppp_nLCS_DP[i][j]);
        }
        free(ppp_nLCS_DP[i]);
    }
    free(ppp_nLCS_DP);
    return 0;
}