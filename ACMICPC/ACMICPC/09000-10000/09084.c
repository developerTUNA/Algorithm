#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem09084(void)
{
    int nTestCase = 0;
    int nCoinNum = 0;
    int nPriceGoal = 0;
    int *p_nCoinPrice = NULL;
    int *p_nCoinPriceDP = NULL;

    scanf("%d", &nTestCase);
    for(int i = 0; i < nTestCase; i++)
    {
        scanf("%d", &nCoinNum);
        p_nCoinPrice = (int*)malloc(sizeof(int)*(nCoinNum+1));
        memset(p_nCoinPrice, 0, sizeof(int)*(nCoinNum + 1));
        for(int j = 0; j < nCoinNum; j++)
        {
            scanf("%d", &p_nCoinPrice[j]);
        }
        scanf("%d", &nPriceGoal);
        p_nCoinPriceDP = (int*)malloc(sizeof(int)*(nPriceGoal + 1));
        memset(p_nCoinPriceDP, 0, sizeof(int)*(nPriceGoal + 1));
        p_nCoinPriceDP[0] = 1;
        for(int j = 0; j < nCoinNum ; j++)
        {
            for(int k = p_nCoinPrice[j]; k <= nPriceGoal; k++)
            {
                if(0 <= k - p_nCoinPrice[j])
                {
                    p_nCoinPriceDP[k] += p_nCoinPriceDP[k - p_nCoinPrice[j]];
                }
            }
        }
        printf("%d\n", p_nCoinPriceDP[nPriceGoal]);
        free(p_nCoinPrice);
        free(p_nCoinPriceDP);
    }
    return 0;
}