#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem02229(void)
{
    int nSize;
    int *pnNum = NULL;
    int *pnResult_DP = NULL;
    int nMax = 0;
    int nMin = 0;
    scanf("%d", &nSize);
    pnNum = (int*)malloc(sizeof(int)*(nSize + 1));
    pnResult_DP = (int*)malloc(sizeof(int)*(nSize + 1));
    memset(pnNum, 0, sizeof(int)*(nSize + 1));
    memset(pnResult_DP, 0, sizeof(int)*(nSize + 1));

    for(int i = 1; i <= nSize; i++)
    {
        scanf("%d", &pnNum[i]);
    }
    pnResult_DP[0] = 0;
    for(int i = 1; i <= nSize; i++)
    {
        nMax = pnNum[i];
        nMin = pnNum[i];
        for(int j = i; 1 <= j  ; j--)
        {
            if(nMax < pnNum[j])
            {
                nMax = pnNum[j];
            }
            if(pnNum[j] < nMin)
            {
                nMin = pnNum[j];
            }

            if(pnResult_DP[i] < pnResult_DP[j - 1] + (nMax - nMin))
            {
                pnResult_DP[i] = pnResult_DP[j - 1] + (nMax - nMin);
            }
        }
    }
    printf("%d\n", pnResult_DP[nSize]);
    free(pnNum);
    free(pnResult_DP);
    return 0;
}