#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Problem02705(void)
{
    int nRound = 0;
    int nMax = 0;
    int *p_nCase = NULL;
    int *p_nNum_DP = NULL;

    scanf("%d", &nRound);
    p_nCase = (int *)malloc(sizeof(int)*nRound);
    for(int i = 0; i < nRound; i++)
    {
        scanf("%d", &p_nCase[i]);
        if(nMax < p_nCase[i])
        {
            nMax = p_nCase[i];
        }
    }
    p_nNum_DP = (int*)malloc(sizeof(int)*(nMax + 1));
    memset(p_nNum_DP, 0, sizeof(int)*(nMax + 1));

    p_nNum_DP[0] = 1;
    p_nNum_DP[1] = 1;

    for(int i = 2; i <= nMax; i++)
    {
        for(int j = 1; j <= i; j++)                 //<= 을 써서 0n0까지 포함함, <으로 할경우 +1 해주면됨
        {
            if((i - j) % 2 == 0)
            {
                p_nNum_DP[i] += p_nNum_DP[(i-j)/2];
            }
        }
        if(i % 2 == 0)
        {
            p_nNum_DP[i] += p_nNum_DP[i/2];
        }
    }
    for(int i = 0; i < nRound; i++)
    {
        printf("%d\n", p_nNum_DP[p_nCase[i]]);
    }
    free(p_nCase);
    free(p_nNum_DP);
    return 0;
}