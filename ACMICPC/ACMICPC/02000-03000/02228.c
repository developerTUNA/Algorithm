#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX02228(a, b) ((a)<(b))?(b):(a)

int GO_DP02228(int nNum_Num, int nDivide_Num, int *p_nNum_Data, int **pp_nNum_DP, int **pp_nNum_Check, int nNum_Remain, int nDivide_Remain)
{
    int nSum = 0;

    if(nDivide_Remain == 0)
    {
        return 0;
    }
    if(nNum_Remain <= 0)
    {
        return -32768 * 101;
    }
    if(pp_nNum_Check[nNum_Remain][nDivide_Remain] == 1)
    {
        return pp_nNum_DP[nNum_Remain][nDivide_Remain];
    }
    pp_nNum_Check[nNum_Remain][nDivide_Remain] = 1;

    pp_nNum_DP[nNum_Remain][nDivide_Remain] = GO_DP02228(nNum_Num, nDivide_Num, p_nNum_Data, pp_nNum_DP, pp_nNum_Check, nNum_Remain - 1, nDivide_Remain);
    for(int i = nNum_Remain; 1 <= i; i--)
    {
        nSum += p_nNum_Data[i];
        pp_nNum_DP[nNum_Remain][nDivide_Remain] = MAX02228(pp_nNum_DP[nNum_Remain][nDivide_Remain], GO_DP02228(nNum_Num, nDivide_Num, p_nNum_Data, pp_nNum_DP, pp_nNum_Check, i - 2, nDivide_Remain - 1)+nSum);
    }
    return pp_nNum_DP[nNum_Remain][nDivide_Remain];
}

int Problem02228(void)
{
    int nNum_Num = 0;
    int nDivide = 0;
    int nResult = 0;
    int *p_nNum_Data = NULL;
    int **pp_nNum_DP = NULL;
    int **pp_nNum_Check = NULL;

    scanf_s("%d %d", &nNum_Num, &nDivide);
    p_nNum_Data = (int *)malloc(sizeof(int)*(nNum_Num+1));
    for(int i = 1; i <= nNum_Num; i++)
    {
        scanf_s("%d", &p_nNum_Data[i]);
    }

    pp_nNum_DP = (int **)malloc(sizeof(int*)*(nNum_Num + 1));
    pp_nNum_Check = (int **)malloc(sizeof(int*)*(nNum_Num + 1));
    for(int i = 0; i <= nNum_Num; i++)
    {
        pp_nNum_DP[i] = (int*)malloc(sizeof(int)*(nNum_Num + 1));
        pp_nNum_Check[i] = (int*)malloc(sizeof(int)*(nNum_Num + 1));
        memset(pp_nNum_DP[i], 0, sizeof(int)*(nNum_Num + 1));
        memset(pp_nNum_Check[i], 0, sizeof(int)*(nNum_Num + 1));
    }

    nResult = GO_DP02228(nNum_Num, nDivide, p_nNum_Data, pp_nNum_DP, pp_nNum_Check, nNum_Num , nDivide);
    printf("%d\n", nResult);

    free(p_nNum_Data);
    for(int i = 0; i <= nNum_Num; i++)
    {
        free(pp_nNum_DP[i]);
        free(pp_nNum_Check[i]);
    }
    free(pp_nNum_DP);
    free(pp_nNum_Check);
    return 0;
}


int GO_DP02228_2(int nNum_Num, int nDivide_Num, int *p_nNum_Data, int ***ppp_nNum_DP, int ***ppp_nNum_Check, int nStart, int nEnd, int nDivide_Remain)
{
    if(ppp_nNum_Check[nStart][nEnd][nDivide_Remain]==1)
    {
        return ppp_nNum_DP[nStart][nEnd][nDivide_Remain];
    }
    
    if(nDivide_Remain == 0)
    {
        int nMax = p_nNum_Data[nStart];
        int nSum = 0;
        for(int i = nStart; i <= nEnd; i++)
        {
            nSum += p_nNum_Data[i];
            if(nMax < nSum)
            {
                nMax = nSum;
            }
            else if(nSum < 0)
            {
                nSum = 0;
            }
        }
        ppp_nNum_DP[nStart][nEnd][nDivide_Remain] = nMax;
        ppp_nNum_Check[nStart][nEnd][nDivide_Remain] = 1;
        return nMax;
    }

    for(int i = 0; i < nDivide_Remain; i++)
    {
        int nSum = 0;
        for(int j = nStart+i*2; j <= nEnd-i*2 && j+2 <= nNum_Num && 0 <= nDivide_Remain - 2 - i; j++)
        {
            nSum = GO_DP02228_2(nNum_Num, nDivide_Num, p_nNum_Data, ppp_nNum_DP, ppp_nNum_Check, nStart , j ,i) +
                GO_DP02228_2(nNum_Num, nDivide_Num, p_nNum_Data, ppp_nNum_DP, ppp_nNum_Check, j+2 , nEnd, nDivide_Remain - 2 - i);
            if(ppp_nNum_Check[nStart][nEnd][nDivide_Remain] == 0 || ppp_nNum_DP[nStart][nEnd][nDivide_Remain] < nSum)
            {
                ppp_nNum_DP[nStart][nEnd][nDivide_Remain] = nSum;
                ppp_nNum_Check[nStart][nEnd][nDivide_Remain] = 1;
            }
        }
    }
    return ppp_nNum_DP[nStart][nEnd][nDivide_Remain];
}

int Problem02228_2(void)
{
    int nNum_Num = 0;
    int nDivide = 0;
    int nResult = 0;
    int *p_nNum_Data = NULL;
    int ***ppp_nNum_DP = NULL;
    int ***ppp_nNum_Check = NULL;
    
    scanf_s("%d %d", &nNum_Num, &nDivide);
    p_nNum_Data = (int *)malloc(sizeof(int)*(nNum_Num));
    for(int i = 0; i < nNum_Num; i++)
    {
        scanf_s("%d", &p_nNum_Data[i]);
    }

    ppp_nNum_DP = (int ***)malloc(sizeof(int**)*(nNum_Num + 1));
    ppp_nNum_Check = (int ***)malloc(sizeof(int**)*(nNum_Num + 1));
    for(int i = 0; i <= nNum_Num; i++)
    {
        ppp_nNum_DP[i] = (int**)malloc(sizeof(int*)*(nNum_Num + 1));
        ppp_nNum_Check[i] = (int**)malloc(sizeof(int*)*(nNum_Num + 1));
        for(int j = 0; j <= nNum_Num; j++)
        {
            ppp_nNum_DP[i][j] = (int *)malloc(sizeof(int)*(nDivide + 1));
            memset(ppp_nNum_DP[i][j], 0, sizeof(int)*(nDivide + 1));
            ppp_nNum_Check[i][j] = (int *)malloc(sizeof(int)*(nDivide + 1));
            memset(ppp_nNum_Check[i][j], 0, sizeof(int)*(nDivide + 1));
        }
    }

    nResult = GO_DP02228_2(nNum_Num, nDivide, p_nNum_Data, ppp_nNum_DP, ppp_nNum_Check, 0, nNum_Num - 1, nDivide);
    printf("%d\n", nResult);

    free(p_nNum_Data);
    for(int i = 0; i <= nNum_Num; i++)
    {
        for(int j = 0; j <= nNum_Num; j++)
        {
            free(ppp_nNum_DP[i][j]);
            free(ppp_nNum_Check[i][j]);
        }
        free(ppp_nNum_DP[i]);
        free(ppp_nNum_Check[i]);
    }
    free(ppp_nNum_DP);
    free(ppp_nNum_Check);
    return 0;
}