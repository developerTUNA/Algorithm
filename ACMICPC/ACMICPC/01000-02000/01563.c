#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01563(void)
{
    int nDay = 0;
    int nResult = 0;
    int***** ppppp_nAward_DP = NULL;
    scanf("%d", &nDay);

    if(nDay == 0)
    {
        printf("0\n");
        return 0;
    }
    else if(nDay == 1)
    {
        printf("3\n");
        return 0;
    }
    else if(nDay == 2)
    {
        printf("8\n");
        return 0;
    }
    ppppp_nAward_DP = malloc(sizeof(int****)*(nDay + 1));
    memset(ppppp_nAward_DP, 0, sizeof(int****)*(nDay + 1));
    for(int i = 0; i <= nDay; i++)
    {
        ppppp_nAward_DP[i] = malloc(sizeof(int***)*(3));
        memset(ppppp_nAward_DP[i], 0, sizeof(int***)*(3));
        for(int j = 0; j < 3; j++)
        {
            ppppp_nAward_DP[i][j] = malloc(sizeof(int**)*(3));
            memset(ppppp_nAward_DP[i][j], 0, sizeof(int**)*(3));
            for(int k = 0; k < 3; k++)
            {
                ppppp_nAward_DP[i][j][k] = malloc(sizeof(int*)*(3));
                memset(ppppp_nAward_DP[i][j][k], 0, sizeof(int*)*(3));
                for(int l = 0; l < 3; l++)
                {
                    ppppp_nAward_DP[i][j][k][l] = malloc(sizeof(int)*(2));
                    memset(ppppp_nAward_DP[i][j][k][l], 0, sizeof(int)*(2));
                }
            }
        }
    }


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(i == 1 && j == 1 && k == 1)      //결석 연속 3번
                {
                    continue;
                }
                else if(i == 2 && j == 2)           //지각 2번
                {
                    continue;
                }
                else if(j == 2 && k == 2)           //지각 2번
                {
                    continue;
                }
                else if(k == 2 && i == 2)           //지각 2번
                {
                    continue;
                }
                else if(i == 2 || j == 2 || k == 2) //3일중 1번 지각
                {
                    ppppp_nAward_DP[3][i][j][k][1] = 1;
                }
                else                               //지각이 없음 (정상, 결석만 있음)
                {
                    ppppp_nAward_DP[3][i][j][k][0] = 1;
                }
            }
        }
    }

    for(int i = 4; i <= nDay; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    ppppp_nAward_DP[i][0][j][k][0] += ppppp_nAward_DP[i - 1][j][k][l][0];
                    ppppp_nAward_DP[i][0][j][k][1] += ppppp_nAward_DP[i - 1][j][k][l][1];
                    ppppp_nAward_DP[i][0][j][k][0] %= 1000000;
                    ppppp_nAward_DP[i][0][j][k][1] %= 1000000;
                    if(!(j == 1 && k == 1))
                    {
                        ppppp_nAward_DP[i][1][j][k][0] += ppppp_nAward_DP[i - 1][j][k][l][0];
                        ppppp_nAward_DP[i][1][j][k][1] += ppppp_nAward_DP[i - 1][j][k][l][1];
                        ppppp_nAward_DP[i][1][j][k][0] %= 1000000;
                        ppppp_nAward_DP[i][1][j][k][1] %= 1000000;
                    }
                    ppppp_nAward_DP[i][2][j][k][1] += ppppp_nAward_DP[i - 1][j][k][l][0];
                    ppppp_nAward_DP[i][2][j][k][1] %= 1000000;
                }
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                nResult += ppppp_nAward_DP[nDay][i][j][k][0];
                nResult += ppppp_nAward_DP[nDay][i][j][k][1];
                nResult %= 1000000;
            }
        }
    }
    printf("%d\n", nResult);
    for(int i = 0; i <= nDay; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    free(ppppp_nAward_DP[i][j][k][l]);
                }
                free(ppppp_nAward_DP[i][j][k]);
            }
            free(ppppp_nAward_DP[i][j]);
        }
        free(ppppp_nAward_DP[i]);
    }
    free(ppppp_nAward_DP);
    return 0;
}


int Problem01563_2(void)
{
    int nDay = 0;
    int nResult = 0;
    int ****pppp_nAward_DP = NULL;

    scanf("%d", &nDay);

    pppp_nAward_DP = malloc(sizeof(int***)*(nDay + 1));
    memset(pppp_nAward_DP, 0, sizeof(int***)*(nDay + 1));
    for(int i = 0; i <= nDay; i++)
    {
        pppp_nAward_DP[i] = malloc(sizeof(int**)*(3));
        memset(pppp_nAward_DP[i], 0, sizeof(int**)*(3));
        for(int j = 0; j < 3; j++)
        {
            pppp_nAward_DP[i][j] = malloc(sizeof(int*)*(2));
            memset(pppp_nAward_DP[i][j], 0, sizeof(int*)*(2));
            for(int k = 0; k < 2; k++)
            {
                pppp_nAward_DP[i][j][k] = malloc(sizeof(int*)*(3));
                memset(pppp_nAward_DP[i][j][k], 0, sizeof(int*)*(3));
            }
        }
    }

    pppp_nAward_DP[1][0][0][0] = 1;
    pppp_nAward_DP[1][1][0][1] = 1;
    pppp_nAward_DP[1][0][1][2] = 1;

    for(int i = 2; i <= nDay; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                pppp_nAward_DP[i][0][k][0] += pppp_nAward_DP[i - 1][j][k][0];
                pppp_nAward_DP[i][0][k][0] += pppp_nAward_DP[i - 1][j][k][1];
                if(k + 1 < 2)
                {
                    pppp_nAward_DP[i][0][k+1][0] += pppp_nAward_DP[i - 1][j][k][2];
                    pppp_nAward_DP[i][0][k+1][0] %= 1000000;
                }

                pppp_nAward_DP[i][1][k][1] += pppp_nAward_DP[i - 1][j][k][0];
                pppp_nAward_DP[i][1][k][1] += pppp_nAward_DP[i - 1][j][k][2];
                pppp_nAward_DP[i][1][k][1] %= 1000000;
                if(j + 1 < 3)
                {
                    pppp_nAward_DP[i][j+1][k][1] += pppp_nAward_DP[i - 1][j][k][1];
                    pppp_nAward_DP[i][j+1][k][1] %= 1000000;
                }

                if(k + 1 < 2)
                {
                    pppp_nAward_DP[i][0][k+1][2] += pppp_nAward_DP[i - 1][j][k][0];
                    pppp_nAward_DP[i][0][k+1][2] += pppp_nAward_DP[i - 1][j][k][1];
                    pppp_nAward_DP[i][0][k+1][2] %= 1000000;
                }
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            nResult += pppp_nAward_DP[nDay][i][j][0];
            nResult += pppp_nAward_DP[nDay][i][j][1];
            nResult += pppp_nAward_DP[nDay][i][j][2];
            nResult %= 1000000;
        }
    }

    printf("%d\n", nResult);
    for(int i = 0; i <= nDay; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                free(pppp_nAward_DP[i][j][k]);
            }
            free(pppp_nAward_DP[i][j]);
        }
        free(pppp_nAward_DP[i]);
    }
    free(pppp_nAward_DP);
    return 0;
}