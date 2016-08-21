#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX02240(a, b) ((a)<(b))?(b):(a)

int GO_02240(int nTime, int nMove, int *p_nDripTime, int ***ppp_PlumCount_DP, int nTime_Now, int nMove_Now, int nPoz_Now)
{
    if(nTime < nTime_Now || nMove < nMove_Now)
    {
        return 0;
    }
    
    if(ppp_PlumCount_DP[nTime_Now][nMove_Now][nPoz_Now]!= -1)
    {
        return ppp_PlumCount_DP[nTime_Now][nMove_Now][nPoz_Now];
    }

    ppp_PlumCount_DP[nTime_Now][nMove_Now][nPoz_Now] = MAX02240(GO_02240(nTime, nMove, p_nDripTime, ppp_PlumCount_DP, nTime_Now + 1, nMove_Now, nPoz_Now),
                                                                GO_02240(nTime, nMove, p_nDripTime, ppp_PlumCount_DP, nTime_Now + 1, nMove_Now + 1, 3 - nPoz_Now));
    if(p_nDripTime[nTime_Now] == nPoz_Now)
    {
        ppp_PlumCount_DP[nTime_Now][nMove_Now][nPoz_Now] ++;
    }

    return ppp_PlumCount_DP[nTime_Now][nMove_Now][nPoz_Now];
}

int Problem02240(void)
{
    int nTime = 0;
    int nMove = 0;
    int nResult = 0;
    int *p_nDropTime = NULL;
    int ***ppp_PlumCount_DP = NULL;

    scanf("%d %d", &nTime, &nMove);
    p_nDropTime = (int*)malloc(sizeof(int)*(nTime + 1));
    for(int i = 1; i <= nTime; i++)
    {
        scanf("%d", &p_nDropTime[i]);
    }

    ppp_PlumCount_DP = (int***)malloc(sizeof(int**)*(nTime + 1));
    for(int i = 0; i <= nTime; i++)
    {
        ppp_PlumCount_DP[i] = (int **)malloc(sizeof(int*)*(nMove + 1));
        for(int j = 0; j <= nMove; j++)
        {
            ppp_PlumCount_DP[i][j] = (int*)malloc(sizeof(int)*(3));
            memset(ppp_PlumCount_DP[i][j], -1, sizeof(int)*(3));
        }
    }

    nResult = MAX02240 (GO_02240(nTime, nMove,p_nDropTime, ppp_PlumCount_DP,1,0,1), GO_02240(nTime, nMove, p_nDropTime, ppp_PlumCount_DP, 1, 1, 2));
    printf("%d\n", nResult);

    for(int i = 0; i <= nTime; i++)
    {
        for(int j = 0; j <= nMove; j++)
        {
            free(ppp_PlumCount_DP[i][j]);
        }
        free(ppp_PlumCount_DP[i]);
    }
    free(ppp_PlumCount_DP);
    free(p_nDropTime);
    return 0;
}