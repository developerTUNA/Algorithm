#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01720(void)
{
    int nTile_Num = 0;
    int nResult = 0;
    int *p_nTile_DP = NULL;

    scanf("%d", &nTile_Num);
    p_nTile_DP = (int*)malloc(sizeof(int)*(nTile_Num + 1));
    memset(p_nTile_DP, 0, sizeof(int)*(nTile_Num + 1));

    p_nTile_DP[0] = 1;
    p_nTile_DP[1] = 1;
    for(int i = 2; i <= nTile_Num; i++)
    {
        p_nTile_DP[i] = p_nTile_DP[i - 1] + 2 * p_nTile_DP[i - 2];
    }
    if(nTile_Num%2==1)
    {
        nResult = (p_nTile_DP[nTile_Num] +  p_nTile_DP[(nTile_Num - 1) / 2] ) / 2;
    }
    else
    {
        nResult = (p_nTile_DP[nTile_Num] + p_nTile_DP[(nTile_Num) / 2] + 2 * p_nTile_DP[(nTile_Num - 2) / 2]) / 2;
    }

    printf("%d\n", nResult);
    free(p_nTile_DP);
    return 0;
}