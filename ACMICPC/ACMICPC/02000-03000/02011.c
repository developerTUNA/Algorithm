#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02011(void)
{
    char cInput = 0;
    int nString_Len = 1;
    int a_nString[5001] = {0,};
    int nString_DP[5001] = {0,};
    while(scanf("%c",&cInput) == 1)
    {
        a_nString[nString_Len] = atoi(&cInput);
        nString_Len++;
    }
    nString_DP[0] = 1;
    for(int i = 1; i < nString_Len; i++)
    {
        if(1 <= a_nString[i] && a_nString[i] <= 9)
        {
            nString_DP[i] = nString_DP[i] + nString_DP[i-1];
        }
        if(1 == a_nString[i-1])
        {
            nString_DP[i] = nString_DP[i] + nString_DP[i-2];
        }
        if(2 == a_nString[i-1] && 0 <= a_nString[i] && a_nString[i] <= 6)
        {
            nString_DP[i] = nString_DP[i] + nString_DP[i - 2];
        }
        nString_DP[i] %= 1000000;
    }

    printf("%d\n", nString_DP[nString_Len-1]);
    return 0;
}