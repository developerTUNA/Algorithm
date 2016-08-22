#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01328(void)
{
    int nBuildingNum = 0;
    int nLeftCount = 0;
    int nRightCount = 0;
    long long ***ppp_llnBuilding_DP = NULL;

    scanf("%d %d %d", &nBuildingNum, &nLeftCount, &nRightCount);
    
    ppp_llnBuilding_DP = (long long ***)malloc(sizeof(long long **)*(nBuildingNum + 1));
    for(int i = 0; i <= nBuildingNum; i++)
    {
        ppp_llnBuilding_DP[i] = (long long **)malloc(sizeof(long long *)*(nLeftCount + 1));
        for(int j = 0; j <= nLeftCount; j++)
        {
            ppp_llnBuilding_DP[i][j] = (long long *)malloc(sizeof(long long )*(nRightCount + 1));
            memset(ppp_llnBuilding_DP[i][j], 0, sizeof(long long)*(nRightCount + 1));
        }
    }

    ppp_llnBuilding_DP[1][1][1] = 1;
    for(int i = 1; i <= nBuildingNum; i++)
    {
        for(int j = 1; j <= nLeftCount; j++)
        {
            for(int k = 1; k <= nRightCount; k++)
            {
                ppp_llnBuilding_DP[i][j][k] += ppp_llnBuilding_DP[i - 1][j - 1][k];
                ppp_llnBuilding_DP[i][j][k] += ppp_llnBuilding_DP[i - 1][j][k - 1];
                ppp_llnBuilding_DP[i][j][k] += ppp_llnBuilding_DP[i - 1][j][k] * (i - 2);
                ppp_llnBuilding_DP[i][j][k] %= 1000000007;
            }
        }
    }
    printf("%lld\n", ppp_llnBuilding_DP[nBuildingNum][nLeftCount][nRightCount]);
    for(int i = 1; i <= nBuildingNum; i++)
    {
        for(int j = 1; j <= nLeftCount; j++)
        {
            free(ppp_llnBuilding_DP[i][j]);
        }
        free(ppp_llnBuilding_DP[i]);
    }
    free(ppp_llnBuilding_DP);
    return 0;
}