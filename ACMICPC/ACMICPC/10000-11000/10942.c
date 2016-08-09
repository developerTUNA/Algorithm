#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GO_DP10942(int **pp_nNumber_DP, int *p_nNumber, int nStart, int nEnd)
{
    if(pp_nNumber_DP[nStart][nEnd] == 0)
    {
        return 0;
    }
    else if(pp_nNumber_DP[nStart][nEnd] == 1)
    {
        return 1;
    }

    if(nStart == nEnd)
    {
        pp_nNumber_DP[nStart][nEnd] = 1;
        return 1;
    }
    if(nStart == (nEnd - 1))
    {
        if(p_nNumber[nStart] == p_nNumber[nEnd])
        {
            pp_nNumber_DP[nStart][nEnd] = 1;
            return 1;
        }
        else
        {
            pp_nNumber_DP[nStart][nEnd] = 0;
            return 0;
        }
    }
    if(p_nNumber[nStart] != p_nNumber[nEnd])
    {
        pp_nNumber_DP[nStart][nEnd] = 0;
        return 0;
    }

    pp_nNumber_DP[nStart][nEnd] = GO_DP10942(pp_nNumber_DP, p_nNumber, nStart + 1, nEnd - 1);
    return pp_nNumber_DP[nStart][nEnd];
}

int Problem10942(void)
{
    int nSize = 0;
    int nProblem_Num = 0;
    int nStart = 0;
    int nEnd = 0;
    int nResult = 0;
    int *p_nNumber = NULL;
    int **pp_nNumber_DP = NULL;

    scanf("%d", &nSize);
    p_nNumber = (int *)malloc(sizeof(int)*(nSize+1));
    memset(p_nNumber, 0, sizeof(int)*(nSize + 1));
    pp_nNumber_DP = (int **)malloc(sizeof(int*)*(nSize + 1));
    for(int i = 0; i <= nSize; i++)
    {
        pp_nNumber_DP[i] = (int *)malloc(sizeof(int)*(nSize + 1));
        memset(pp_nNumber_DP[i], -1, sizeof(int)*(nSize + 1));
    }

    for(int i = 1; i <= nSize; i++)
    {
        scanf("%d", &p_nNumber[i]);
    }

    scanf("%d", &nProblem_Num);
    for(int i = 0; i < nProblem_Num; i++)
    {
        scanf("%d %d", &nStart, &nEnd);
        nResult = GO_DP10942(pp_nNumber_DP, p_nNumber, nStart, nEnd);
        printf("%d\n", nResult);
    }

    free(p_nNumber);
    for(int i = 0; i <= nSize; i++)
    {
        free(pp_nNumber_DP[i]);
    }
    free(pp_nNumber_DP);
    return 0;
}

int Problem10942_2(void)
{
    int nSize = 0;
    int nProblem_Num = 0;
    int nStart = 0;
    int nEnd = 0;
    int nResult = 0;
    int *p_nNumber = NULL;
    int **pp_nNumber_DP = NULL;

    scanf("%d", &nSize);
    p_nNumber = (int *)malloc(sizeof(int)*(nSize + 1));
    memset(p_nNumber, 0, sizeof(int)*(nSize + 1));

    pp_nNumber_DP = (int **)malloc(sizeof(int*)*(nSize + 2));
    for(int i = 0; i <= nSize+1; i++)
    {
        pp_nNumber_DP[i] = (int *)malloc(sizeof(int)*(nSize + 2));
        memset(pp_nNumber_DP[i], -1, sizeof(int)*(nSize + 2));
    }

    for(int i = 1; i <= nSize; i++)
    {
        scanf("%d", &p_nNumber[i]);
    }

    for(int i = 1; i <= nSize; i++)
    {
        pp_nNumber_DP[i][i] = 1;
    }
    for(int i = 2; i <= nSize; i++)
    {
        if(p_nNumber[i-1] == p_nNumber[i])
        {
            pp_nNumber_DP[i - 1][i] = 1;
        }
        else
        {
            pp_nNumber_DP[i - 1][i] = 0;
        }
    }

    for(int nGap = 2; nGap < nSize; nGap++)
    {
        for(int i = 1; i <= nSize - nGap; i++)
        {
            int j = i + nGap;
            if(p_nNumber[i] == p_nNumber[j] && pp_nNumber_DP[i+1][j-1] == 1)
            {
                pp_nNumber_DP[i][j] = 1;
            }
            else
            {
                pp_nNumber_DP[i][j] = 0;
            }
        }
    }

    scanf("%d", &nProblem_Num);
    for(int i = 0; i < nProblem_Num; i++)
    {
        scanf("%d %d", &nStart, &nEnd);
        nResult = pp_nNumber_DP[nStart][nEnd];
        printf("%d\n", nResult);
    }

    free(p_nNumber);
    for(int i = 0; i <= nSize+1; i++)
    {
        free(pp_nNumber_DP[i]);
    }
    free(pp_nNumber_DP);
    return 0;
}