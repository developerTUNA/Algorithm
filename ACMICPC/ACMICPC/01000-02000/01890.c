#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01890(void)
{
    int nSize = 0;
    int nResult = 0;
    int ** pp_nBox = NULL;
    long long ** pp_llnBox_DP = NULL;

    scanf("%d", &nSize);
    pp_nBox = (int **)malloc(sizeof(int*)*(nSize+1));
    pp_llnBox_DP = (long long **)malloc(sizeof(long long*)*(nSize + 1));
    for(int i = 0; i <= nSize; i++)
    {
        pp_nBox[i] = (int*)malloc(sizeof(int)*(nSize + 1));
        pp_llnBox_DP[i] = (long long*)malloc(sizeof(long long)*(nSize + 1));
        memset(pp_nBox[i], 0, sizeof(int)*(nSize + 1));
        memset(pp_llnBox_DP[i], 0, sizeof(long long)*(nSize + 1));
    }

    for(int i = 1; i <= nSize; i++)
    {
        for(int j = 1; j <= nSize; j++)
        {
            scanf("%d", &pp_nBox[i][j]);
        }
    }

    pp_llnBox_DP[1][1] = 1;
    for(int i = 1; i <= nSize; i++)
    {
        for(int j = 1; j <= nSize; j++)
        {
            if(pp_nBox[i][j] == 0)
            {
                continue;
            }
            if(j + pp_nBox[i][j] <= nSize)
            {
                pp_llnBox_DP[i][j + pp_nBox[i][j]] += pp_llnBox_DP[i][j];
            }
            if(i + pp_nBox[i][j] <= nSize)
            {
                pp_llnBox_DP[i+pp_nBox[i][j]][j] += pp_llnBox_DP[i][j];
            }
        }
    }

    printf("%lld\n", pp_llnBox_DP[nSize][nSize]);
    for(int i = 0; i <= nSize; i++)
    {
        free(pp_nBox[i]);
        free(pp_llnBox_DP[i]);
    }
    free(pp_nBox);
    free(pp_llnBox_DP);

    return 0;
}

long long GO_DP01890(int **pp_nBox, long long **pp_llnBox_DP, int nSize, int nRow, int nCol)
{
    int nJump = 0;
    if(nSize == nRow && nSize == nCol)
    {
        return 1;
    }
    nJump = pp_nBox[nRow][nCol];
    if(nJump == 0)
    {
        return 0;
    }
    if(pp_llnBox_DP[nRow][nCol] != 0)
    {
        return pp_llnBox_DP[nRow][nCol];
    }

    if(nRow + nJump <= nSize)
    {
        pp_llnBox_DP[nRow][nCol] += GO_DP01890(pp_nBox, pp_llnBox_DP, nSize, nRow + nJump, nCol);
    }
    if(nCol + nJump <= nSize)
    {
        pp_llnBox_DP[nRow][nCol] += GO_DP01890(pp_nBox, pp_llnBox_DP, nSize, nRow, nCol + nJump);
    }
    return pp_llnBox_DP[nRow][nCol];
}

int Problem01890_2(void)
{
    int nSize = 0;
    int nResult = 0;
    int ** pp_nBox = NULL;
    long long ** pp_llnBox_DP = NULL;

    scanf("%d", &nSize);
    pp_nBox = (int **)malloc(sizeof(int*)*(nSize + 1));
    pp_llnBox_DP = (long long **)malloc(sizeof(long long*)*(nSize + 1));
    for(int i = 0; i <= nSize; i++)
    {
        pp_nBox[i] = (int*)malloc(sizeof(int)*(nSize + 1));
        pp_llnBox_DP[i] = (long long*)malloc(sizeof(long long)*(nSize + 1));
        memset(pp_nBox[i], 0, sizeof(int)*(nSize + 1));
        memset(pp_llnBox_DP[i], 0, sizeof(long long)*(nSize + 1));
    }

    for(int i = 1; i <= nSize; i++)
    {
        for(int j = 1; j <= nSize; j++)
        {
            scanf("%d", &pp_nBox[i][j]);
        }
    }
    GO_DP01890(pp_nBox, pp_llnBox_DP, nSize, 1, 1);

    printf("%lld\n", pp_llnBox_DP[1][1]);

    for(int i = 0; i <= nSize; i++)
    {
        free(pp_nBox[i]);
        free(pp_llnBox_DP[i]);
    }
    free(pp_nBox);
    free(pp_llnBox_DP);

    return 0;
}