#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


long long GCD01086(long long nX, long long nY)
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
    int nNum_Len_Max = 0;
    long long llnTotal_Count = 0;
    long long llnResult_Count = 0;
    long long llnGcd = 0;
    int *p_nNext = NULL;
    int *p_nRemain = NULL;
    int *p_nNum_Len = NULL;
    char **pp_szNum = NULL;
    long long **pp_llnRemain_DP = NULL;
    
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

    pp_llnRemain_DP = malloc(sizeof(long long*)*(1<<nNum_Count));
    memset(pp_llnRemain_DP, 0, sizeof(long long*)*(1<<nNum_Count));
    for(int i = 0; i < (1 << nNum_Count); i++)
    {
        pp_llnRemain_DP[i] = malloc(sizeof(long long)*(nDiv));
        memset(pp_llnRemain_DP[i], 0, sizeof(long long)*(nDiv));
    }

    for(int i = 0; i < nNum_Count; i++)
    {
        p_nNum_Len[i] = strlen(pp_szNum[i]);
        if(nNum_Len_Max < p_nNum_Len[i])
        {
            nNum_Len_Max = p_nNum_Len[i];
        }
        for(int j = 0; j < p_nNum_Len[i]; j++)
        {
            p_nRemain[i] = (p_nRemain[i] * 10 + (pp_szNum[i][j] - '0')) % nDiv;
        }
    }

    p_nNext = malloc(sizeof(int)*(nNum_Len_Max+1));
    memset(p_nNext, 0, sizeof(int)*(nNum_Len_Max+1));
    p_nNext[0] = 1;
    for (int i = 1; i<= nNum_Len_Max;i++)
    {
        p_nNext[i] = (p_nNext[i-1] * 10) % nDiv;
    }

    pp_llnRemain_DP[0][0] = 1;
    for(int i = 0; i < (1 << nNum_Count); i++)
    {
        for(int j = 0; j < nDiv; j++)
        {
            for(int k = 0; k < nNum_Count; k++)
            {
                if((i&(1<<k)) == 0)
                {
                    int nNext = 1;
                    nNext = (p_nNext[p_nNum_Len[k]]*j + p_nRemain[k]) % nDiv;
                    pp_llnRemain_DP[i | (1 << k)][nNext] += pp_llnRemain_DP[i][j];
                }
            }
        }
    }

    llnResult_Count = pp_llnRemain_DP[(1 << nNum_Count)-1][0];
    llnTotal_Count = 1;
    for(int i = 1; i <= nNum_Count; i++)
    {
        llnTotal_Count *= i;
    }

    llnGcd = GCD01086(llnResult_Count, llnTotal_Count);
    llnResult_Count /= llnGcd;
    llnTotal_Count /= llnGcd;
    printf("%lld/%lld\n", llnResult_Count, llnTotal_Count);

    for(int i = 0; i < nNum_Count; i++)
    {
        free(pp_szNum[i]);
    }
    for(int i = 0; i < (1 << nNum_Count); i++)
    {
        free(pp_llnRemain_DP[i]);
    }
    free(pp_szNum);
    free(pp_llnRemain_DP);
    free(p_nRemain);
    free(p_nNum_Len);
    free(p_nNext);

    return 0;
}