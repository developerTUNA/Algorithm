#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int GCD01086(int nX, int nY)
{
    if(nY == 0)
    {
        return nX;
    }
    else
    {
        return GCD01086(nY, nX%nY);
    }
}

int Problem01086(void)
{
    int nNum_Count = 0;
    int nDiv = 0;
    int nTotal_Count = 0;
    int nResult_Count = 0;
    int nGcd = 0;
    int *p_nRemain = NULL;
    int *p_nNum_Len = NULL;
    int **pp_nRemain_DP = NULL;
    char **pp_szNum = NULL;
    
    scanf("%d", &nNum_Count);
    pp_szNum = malloc(sizeof(char *)*(nNum_Count));
    memset(pp_szNum, 0, sizeof(char *)*(nNum_Count));
    for(int i = 0; i < nNum_Count; i++)
    {
        pp_szNum[i] = malloc(sizeof(char)*(51));
        memset(pp_szNum[i], 0, sizeof(char)*(51));
    }
    p_nRemain = malloc(sizeof(int)*(nNum_Count));
    memset(p_nRemain, 0, sizeof(int)*(nNum_Count));
    p_nNum_Len = malloc(sizeof(int)*(nNum_Count));
    memset(p_nNum_Len, 0, sizeof(int)*(nNum_Count));

    for(int i = 0; i < nNum_Count; i++)
    {
        scanf("%s", pp_szNum[i]);
    }
    scanf("%d", &nDiv);

    pp_nRemain_DP = malloc(sizeof(int*)*(1<<nNum_Count));
    memset(pp_nRemain_DP, 0, sizeof(int*)*(1<<nNum_Count));
    for(int i = 0; i < (1 << nNum_Count); i++)
    {
        pp_nRemain_DP[i] = malloc(sizeof(int)*(nDiv));
        memset(pp_nRemain_DP[i], 0, sizeof(int)*(nDiv));
    }

    for(int i = 0; i < nNum_Count; i++)
    {
        p_nNum_Len[i] = strlen(pp_szNum[i]);
        for(int j = 0; j < p_nNum_Len[i]; j++)
        {
            p_nRemain[i] = (p_nRemain[i] * 10 + (pp_szNum[i][j] - '0')) % nDiv;
        }
    }

    pp_nRemain_DP[0][0] = 1;
    for(int i = 0; i < (1 << nNum_Count); i++)
    {
        for(int j = 0; j < nDiv; j++)
        {
            for(int k = 0; k < nNum_Count; k++)
            {
                if((i&(1<<k)) == 0)
                {
                    int nNext = 1;
                    for(int l = 0; l < p_nNum_Len[k]; l++)
                    {
                        nNext = (nNext * 10)%nDiv;
                    }
                    nNext = (nNext*j + p_nRemain[k]) % nDiv;
                    pp_nRemain_DP[i | (1 << k)][nNext] += pp_nRemain_DP[i][j];
                }
            }
        }
    }

    nResult_Count = pp_nRemain_DP[(1 << nNum_Count)-1][0];
    nTotal_Count = 1;
    for(int i = 1; i <= nNum_Count; i++)
    {
        nTotal_Count *= i;
    }

    nGcd = GCD01086(nResult_Count, nTotal_Count);
    nResult_Count /= nGcd;
    nTotal_Count /= nGcd;
    printf("%d/%d\n", nResult_Count, nTotal_Count);

    for(int i = 0; i < nNum_Count; i++)
    {
        free(pp_szNum[i]);
    }
    for(int i = 0; i < (1 << nNum_Count); i++)
    {
        free(pp_nRemain_DP[i]);
    }
    free(pp_szNum);
    free(pp_nRemain_DP);
    free(p_nRemain);
    free(p_nNum_Len);

    return 0;
}