#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02172(void)
{
    int nSize = 0;
    int nLength = 0;
    int nResult = 0;
    int **pp_nBox = NULL;
    int *****ppppp_nBox_DP = NULL;

    scanf("%d %d", &nSize, &nLength);

    pp_nBox = malloc(sizeof(int*)*(nSize));
    memset(pp_nBox, 0, sizeof(int*)*(nSize));
    for(int i = 0; i < nSize; i++)
    {
        pp_nBox[i] = malloc(sizeof(int)*(nSize));
        memset(pp_nBox[i], 0, sizeof(int)*(nSize));
    }

    ppppp_nBox_DP = malloc(sizeof(int****)*(nLength+1));
    memset(ppppp_nBox_DP, 0, sizeof(int****)*(nLength+1));
    for(int i = 0; i <= nLength; i++)
    {
        ppppp_nBox_DP[i] = malloc(sizeof(int***)*(nSize));
        memset(ppppp_nBox_DP[i], 0, sizeof(int***)*(nSize));
        for(int j = 0; j < nSize; j++)
        {
            ppppp_nBox_DP[i][j] = malloc(sizeof(int**)*(nSize));
            memset(ppppp_nBox_DP[i][j], 0, sizeof(int**)*(nSize));
            for(int k = 0; k < nSize; k++)
            {
                ppppp_nBox_DP[i][j][k] = malloc(sizeof(int*)*(nSize));
                memset(ppppp_nBox_DP[i][j][k], 0, sizeof(int*)*(nSize));
                for(int l = 0; l < nSize; l++)
                {
                    ppppp_nBox_DP[i][j][k][l] = malloc(sizeof(int)*(nSize));
                    memset(ppppp_nBox_DP[i][j][k][l], 0, sizeof(int)*(nSize));
                }
            }
        }
    }
    for(int i = 0; i < nSize; i++)
    {
        for(int j = 0; j < nSize; j++)
        {
            scanf("%d", &pp_nBox[i][j]);
        }
    }

    for(int i = 0; i < nSize; i++)
    {
        for(int j = 0; j < nSize; j++)
        {
            ppppp_nBox_DP[1][i][j][i][j] = 1;
            if(2<=nLength)
            {
                if(i + 1 < nSize && j + 1 < nSize && pp_nBox[i][j] == pp_nBox[i + 1][j + 1])
                {
                    ppppp_nBox_DP[2][i][j][i + 1][j + 1] = 1;
                }
                if(i + 1 < nSize && 0 <= j - 1 && pp_nBox[i][j] == pp_nBox[i + 1][j - 1])
                {
                    ppppp_nBox_DP[2][i][j][i + 1][j - 1] = 1;
                }
                if(0 <= i - 1 && j + 1 < nSize&&pp_nBox[i][j] == pp_nBox[i - 1][j + 1])
                {
                    ppppp_nBox_DP[2][i][j][i - 1][j + 1] = 1;
                }
                if(0 <= i - 1 && 0 <= j - 1 && pp_nBox[i][j] == pp_nBox[i - 1][j - 1])
                {
                    ppppp_nBox_DP[2][i][j][i - 1][j - 1] = 1;
                }
                if(j + 1 < nSize && pp_nBox[i][j] == pp_nBox[i][j + 1])
                {
                    ppppp_nBox_DP[2][i][j][i][j + 1] = 1;
                }
                if(0 <= j - 1 && pp_nBox[i][j] == pp_nBox[i][j - 1])
                {
                    ppppp_nBox_DP[2][i][j][i][j - 1] = 1;
                }
                if(i + 1 < nSize && pp_nBox[i][j] == pp_nBox[i + 1][j])
                {
                    ppppp_nBox_DP[2][i][j][i + 1][j] = 1;
                }
                if(0 <= i - 1 && pp_nBox[i][j] == pp_nBox[i - 1][j])
                {
                    ppppp_nBox_DP[2][i][j][i - 1][j] = 1;
                }
            }
        }
    }



    for(int i = 3; i <= nLength; i++)
    {
        for(int j = 0; j < nSize; j++)
        {
            for(int k = 0; k < nSize; k++)
            {
                for(int l = 0; l < nSize; l++)
                {
                    for(int m = 0; m < nSize; m++)
                    {
                        if(pp_nBox[j][k] == pp_nBox[l][m])
                        {
                            for(int n = j - 1; n <= j + 1; n++)
                            {
                                if(0<=n && n<nSize)
                                {
                                    for(int o = k - 1; o <= k + 1; o++)
                                    {
                                        if( 0<= o && o<nSize)
                                        {
                                            for(int p = l - 1; p <= l + 1; p++)
                                            {
                                                if(0 <= p && p < nSize)
                                                {
                                                    for(int q = m - 1; q <= m + 1; q++)
                                                    {
                                                        if(0 <= q && q < nSize)
                                                        {
                                                            if(!(j == n && k == o) && !(l==p && m==q))
                                                            {
                                                                ppppp_nBox_DP[i][j][k][l][m] += ppppp_nBox_DP[i - 2][n][o][p][q];
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < nSize; i++)
    {
        for(int j = 0; j < nSize; j++)
        {
            for(int k = 0; k < nSize; k++)
            {
                for(int l = 0 ; l < nSize; l++)
                {
                    nResult += ppppp_nBox_DP[nLength][i][j][k][l];
                }
            }
        }
    }

    printf("%d\n", nResult);

    for(int i = 0; i < nSize; i++)
    {
        free(pp_nBox[i]);
    }
    free(pp_nBox);

    for(int i = 0; i <= nLength; i++)
    {
        for(int j = 0; j < nSize; j++)
        {
            for(int k = 0; k < nSize; k++)
            {
                for(int l = 0; l < nSize; l++)
                {
                    free(ppppp_nBox_DP[i][j][k][l]);
                }
                free(ppppp_nBox_DP[i][j][k]);
            }
            free(ppppp_nBox_DP[i][j]);
        }
        free(ppppp_nBox_DP[i]);
    }
    free(ppppp_nBox_DP);

    return 0;
}