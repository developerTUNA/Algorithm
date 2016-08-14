#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem01023(void)
{
    unsigned long long nBracketSize = 0;
    unsigned long long nBracketPoz = 0;
    unsigned long long *nBracketNonNum_DP = NULL;
    unsigned long long **pp_ullBracketNonNum_DP = NULL;
    scanf("%lld %lld", &nBracketSize, &nBracketPoz);

    if((unsigned long long)(1LL << nBracketSize)<=nBracketPoz)
    {
        printf("-1\n");
        return 0;
    }
    if(nBracketSize % 2 == 1)
    {
        for(unsigned long long i = nBracketSize-1; 0 <= i; i--)
        {
            if(nBracketPoz & (1LL << i))
            {
                printf(")");
            }
            else
            {
                printf("(");
            }
            if(i == 0)
            {
                break;
            }
        }
        printf("\n");
        return 0;
    }

    nBracketNonNum_DP = (unsigned long long*)malloc(sizeof(unsigned long long)*((size_t)nBracketSize + 1));
    memset(nBracketNonNum_DP, 0, sizeof(unsigned long long)*((size_t)nBracketSize + 1));
    nBracketNonNum_DP[2] = 1;
    unsigned long long test = 0;
    for(unsigned long long i = 4; i <= nBracketSize; i += 2)
    {
        nBracketNonNum_DP[i] = (nBracketNonNum_DP[i - 2] - 1) * 3 + 2;
        test += nBracketNonNum_DP[i];
    }

    pp_ullBracketNonNum_DP = (unsigned long long**)malloc(sizeof(unsigned long long*)*((size_t)nBracketSize + 1));
    memset(pp_ullBracketNonNum_DP, 0, sizeof(unsigned long long*)*((size_t)nBracketSize + 1));
    for(unsigned long long i = 2; i <= nBracketSize; i += 2)
    {
        pp_ullBracketNonNum_DP[i] = (unsigned long long*)malloc(sizeof(unsigned long long)*(size_t)nBracketNonNum_DP[i]);
        memset(pp_ullBracketNonNum_DP[i], 0, sizeof(unsigned long long)*(size_t)nBracketNonNum_DP[i]);
    }


    pp_ullBracketNonNum_DP[2][0] = 0b1;
    for(unsigned long long i = 2; i <= nBracketSize-2; i += 2)
    {
        unsigned long long nBracketNonNum = nBracketNonNum_DP[i];
        pp_ullBracketNonNum_DP[i + 2][0] = (pp_ullBracketNonNum_DP[i][0] << 2) + 0b1;
        pp_ullBracketNonNum_DP[i + 2][1] = (pp_ullBracketNonNum_DP[i][0] << 1) + 0b1;
        for(unsigned long long j = 1; j < nBracketNonNum; j++)
        {
            pp_ullBracketNonNum_DP[i + 2][j * 3 - 1] = (pp_ullBracketNonNum_DP[i][j] << 2) + 0b1;
            pp_ullBracketNonNum_DP[i + 2][j * 3] = (pp_ullBracketNonNum_DP[i][j] << 1) + 0b1;
            pp_ullBracketNonNum_DP[i + 2][j * 3 + 1] = pp_ullBracketNonNum_DP[i][j] + (1LL << i);
        }
    }

    if((1LL << nBracketSize) - nBracketNonNum_DP[nBracketSize] <= nBracketPoz)
    {
        printf("-1\n");
    }
    else
    {
        unsigned long long nBigNumSave = 0;
        unsigned long long nBigNum = 0;
        while(1)
        {
            nBigNum = 0;
            for(unsigned long long i = 0; i < nBracketNonNum_DP[nBracketSize]; i++)
            {
                if(pp_ullBracketNonNum_DP[nBracketSize][i]<= nBracketPoz + nBigNumSave)
                {
                    nBigNum++;
                }
            }
            if (nBigNumSave == nBigNum)
            {
                break;
            }
            nBigNumSave = nBigNum;
        }
        nBracketPoz +=nBigNumSave;
        for(unsigned long long i = nBracketSize - 1; 0 <= i; i--)
        {
            if(nBracketPoz & (1LL << i))
            {
                printf(")");
            }
            else
            {
                printf("(");
            }
            if(i == 0)
            {
                break;
            }
        }
        printf("\n");
    }

    free(nBracketNonNum_DP);
    for(unsigned long long i = 0; i < nBracketSize; i += 2)
    {
        free(pp_ullBracketNonNum_DP[i]);
    }
    free(pp_ullBracketNonNum_DP);
    return 0;
}
