#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01983(void)
{
    int nTemp = 0;
    int nBoxLen = 0;
    int nBoxUpLen = 0;
    int nBoxDownLen = 0;
    int *p_nBoxUpList = NULL;
    int *p_nBoxDownList = NULL;
    long long ***ppp_llnBoxDP = NULL;

    scanf("%d", &nBoxLen);
    p_nBoxUpList = (int*)malloc(sizeof(int)*(nBoxLen+1));
    p_nBoxDownList = (int*)malloc(sizeof(int)*(nBoxLen + 1));
    memset(p_nBoxUpList, 0, sizeof(int)*(nBoxLen + 1));
    memset(p_nBoxDownList, 0, sizeof(int)*(nBoxLen + 1));
    ppp_llnBoxDP = (long long ***)malloc(sizeof(long long**)*(nBoxLen + 1));
    for(int i = 0; i <= nBoxLen; i++)
    {
        ppp_llnBoxDP[i] = (long long **)malloc(sizeof(long long*)*(nBoxLen + 1));
        for(int j = 0; j <= nBoxLen; j++)
        {
            ppp_llnBoxDP[i][j] = (long long*)malloc(sizeof(long long)*(nBoxLen + 1));
            memset(ppp_llnBoxDP[i][j], 0, sizeof(long long)*(nBoxLen + 1));
        }
    }

    for(int i = 1; i <= nBoxLen; i++)
    {
        scanf("%d", &nTemp);
        if(nTemp != 0)
        {
            nBoxUpLen += 1;
            p_nBoxUpList[nBoxUpLen] = nTemp;
        }
    }
    for(int i = 1; i <= nBoxLen; i++)
    {
        scanf("%d", &nTemp);
        if(nTemp != 0)
        {
            nBoxDownLen += 1;
            p_nBoxDownList[nBoxDownLen] = nTemp;
        }
    }

    for(int i = 1; i <= nBoxLen; i++)
    {
        for(int j = 1; j <= nBoxUpLen && j <= i; j++)
        {
            for(int k = 1; k <= nBoxDownLen && k <= i; k++)
            {
                ppp_llnBoxDP[i][j][k] = ppp_llnBoxDP[i - 1][j - 1][k - 1] + p_nBoxUpList[j] * p_nBoxDownList[k];
                if(ppp_llnBoxDP[i][j][k] < ppp_llnBoxDP[i - 1][j - 1][k] && k <= i - 1)
                {
                    ppp_llnBoxDP[i][j][k] = ppp_llnBoxDP[i - 1][j - 1][k];
                }
                if(ppp_llnBoxDP[i][j][k] < ppp_llnBoxDP[i - 1][j][k - 1] && j <= i - 1)
                {
                    ppp_llnBoxDP[i][j][k] = ppp_llnBoxDP[i - 1][j][k - 1];
                }
            }
        }
    }
    
    printf("%lld\n", ppp_llnBoxDP[nBoxLen][nBoxUpLen][nBoxDownLen]);

    free(p_nBoxUpList);
    free(p_nBoxDownList);
    for(int i = 0; i <= nBoxLen; i++)
    {
        for(int j = 0; j <= nBoxLen; j++)
        {
            free(ppp_llnBoxDP[i][j]);
        }
        free(ppp_llnBoxDP[i]);
    }
    free(ppp_llnBoxDP);

    return 0;
}