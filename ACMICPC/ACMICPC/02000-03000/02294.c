#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN02294(a,b)((a)<(b))?(a):(b)

int Swap02294(int *nA, int *nB)
{
    int nTemp = 0;
    nTemp = *nA;
    *nA = *nB;
    *nB = nTemp;
    return 0;
}
int QuickPartion02294(int *p_nCoinTypeValue, int nStart, int nEnd)
{
    int nMid = 0;
    int nPivot = 0;
    int nStore = 0;

    nStore = nStart;
    nMid = (nStart + nEnd) / 2;
    nPivot = p_nCoinTypeValue[nMid];
    Swap02294(&p_nCoinTypeValue[nMid], &p_nCoinTypeValue[nEnd]);

    for(int i = nStart; i < nEnd; i++)
    {
        if(p_nCoinTypeValue[i]<nPivot) //오름차순
        {
            Swap02294(&p_nCoinTypeValue[i], &p_nCoinTypeValue[nStore]);
            nStore++;
        }
    }
    Swap02294(&p_nCoinTypeValue[nEnd], &p_nCoinTypeValue[nStore]);
    return nStore;
}
int QuickSort02294(int *p_nCoinTypeValue, int nStart, int nEnd)
{
    int nPivot = 0;
    if(nStart < nEnd)
    {
        nPivot = QuickPartion02294(p_nCoinTypeValue, nStart, nEnd);
        QuickSort02294(p_nCoinTypeValue, nStart, nPivot-1);
        QuickSort02294(p_nCoinTypeValue, nPivot + 1, nEnd);
    }
    return 0;
}
int Problem02294(void)
{
    int nCoinTypeNum = 0;
    int nTarget = 0;
    int *p_nCoinTypeValue = NULL;
    int *p_nCountTable_DP = NULL;
    
    scanf("%d %d", &nCoinTypeNum, &nTarget);
    p_nCoinTypeValue = (int*)malloc(sizeof(int)*(nCoinTypeNum));
    memset(p_nCoinTypeValue, 0, sizeof(int)*(nCoinTypeNum));
    for(int i = 0; i<nCoinTypeNum; i++)
    {
        scanf("%d", &p_nCoinTypeValue[i]);
    }
    p_nCountTable_DP = (int *)malloc(sizeof(int)*(nTarget +1));
    memset(p_nCountTable_DP, -1, sizeof(int)*(nTarget +1));

    QuickSort02294(p_nCoinTypeValue, 0, nCoinTypeNum-1);

    p_nCountTable_DP[0] = 0;
    for(int i = 0; i < nCoinTypeNum; i++)
    {
        for(int j = p_nCoinTypeValue[i]; j <= nTarget; j++)
        {
            int nBase = j - p_nCoinTypeValue[i];
            if(p_nCountTable_DP[nBase] != -1)
            {
                if(p_nCountTable_DP[j] == -1)
                {
                    p_nCountTable_DP[j] = p_nCountTable_DP[nBase] + 1;
                }
                p_nCountTable_DP[j] = MIN02294 (p_nCountTable_DP[j], p_nCountTable_DP[nBase] + 1);
            }
        }
    }
    
    printf("%d\n", p_nCountTable_DP[nTarget]);

    free(p_nCoinTypeValue);
    free(p_nCountTable_DP);
    return 0;
}