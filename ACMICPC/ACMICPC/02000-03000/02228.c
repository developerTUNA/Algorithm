#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GO_DP02228(int nNum_Num, int nDivide_Num, int *p_nNum_Data, int ***ppp_nNum_DP, int nStart, int nEnd, int nDivide_Remain)
{
    if(nDivide_Remain == 0)
    {
        int nSum = 0;
        for(int i = nStart; i <= nEnd; i++)
        {
            nSum += p_nNum_Data[i];
        }
        ppp_nNum_DP[nStart][nEnd][1] = nSum;
        return nSum;
    }

    if(0 < ppp_nNum_DP[nStart][nEnd][nDivide_Remain])
    {
        return ppp_nNum_DP[nStart][nEnd][nDivide_Remain];
    }

    for(int i = 0; i < nDivide_Remain; i++)
    {
        int nSum = 0;
        for(int j = nStart; j <= nEnd; j++)
        {
            nSum = GO_DP02228(nNum_Num, nDivide_Num, p_nNum_Data, ppp_nNum_DP, nStart , j ,i)+
                GO_DP02228(nNum_Num, nDivide_Num, p_nNum_Data, ppp_nNum_DP, j+2 , nEnd, nDivide_Remain - i);
        }
    }
}

int Problem02228(void)
{
    int nNum_Num = 0;
    int nDivide = 0;
    int nResult = 0;
    int *p_nNum_Data = NULL;
    int ***ppp_nNum_DP = NULL;
    
    scanf_s("%d %d", &nNum_Num, &nDivide);
    p_nNum_Data = (int *)malloc(sizeof(int)*(nNum_Num));
    for(int i = 0; i < nNum_Num; i++)
    {
        scanf_s("%d", &p_nNum_Data[i]);
    }

    ppp_nNum_DP = (int ***)malloc(sizeof(int**)*(nNum_Num + 1));
    for(int i = 0; i <= nNum_Num; i++)
    {
        ppp_nNum_DP[i] = (int**)malloc(sizeof(int*)*(nNum_Num + 1));
        for(int j = 0; j <= nNum_Num; j++)
        {
            ppp_nNum_DP[i][j] = (int *)malloc(sizeof(int)*(nDivide + 1));
            memset(ppp_nNum_DP[i][j], 0, sizeof(int)*(nDivide + 1));
        }
    }

    nResult = GO_DP02228(nNum_Num, nDivide, p_nNum_Data, ppp_nNum_DP, 0, nNum_Num - 1, nDivide);
    printf("%d\n", nResult);

    free(p_nNum_Data);
    for(int i = 0; i <= nNum_Num; i++)
    {
        for(int j = 0; j <= nNum_Num; j++)
        {
            free(ppp_nNum_DP[i][j]);
        }
        free(ppp_nNum_DP[i]);
    }
    free(ppp_nNum_DP);
    return 0;
}