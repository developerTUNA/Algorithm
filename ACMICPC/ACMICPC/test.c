#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int test()
{
    int nGoal = 0;
    int nCoinNum = 0;
    int *p_nCoinList = NULL;

    scanf("%d %d", &nGoal, &nCoinNum);
    p_nCoinList = (int*)malloc(sizeof(int)*(nCoinNum + 1));
    memset(p_nCoinList, 0, sizeof(int)*(nCoinNum + 1));
    for(int i = 0; i<nCoinNum; i++)
    {
        scanf("%d", &p_nCoinList[i]);
    }


    for(int i = 1; i<nCoinNum; i++)
    {
        int nPick = p_nCoinList[i];
        int nPos = i - 1;
        while(0 <= nPos  && nPick < p_nCoinList[nPos])
        {
            p_nCoinList[nPos + 1] = p_nCoinList[nPos];
            nPos--;
        }
        p_nCoinList[nPos + 1] = nPick;
    }


    long long *p_nCoin_DP = NULL;
    p_nCoin_DP = (long long*)malloc(sizeof(long long)*(nGoal + 1));
    memset(p_nCoin_DP, 0, sizeof(long long)*(nGoal + 1));


    for(int i = 0; i<nCoinNum; i++)
    {
        p_nCoin_DP[p_nCoinList[i]]++;
        for(int j = p_nCoinList[i]; j <= nGoal; j++)
        {
            if(0<j - p_nCoinList[i])
            {
                p_nCoin_DP[j] += p_nCoin_DP[j - p_nCoinList[i]];
            }
        }
    }

    printf("%lld\n", p_nCoin_DP[nGoal]);
    free(p_nCoinList);
    free(p_nCoin_DP);

    return 0;
}
    