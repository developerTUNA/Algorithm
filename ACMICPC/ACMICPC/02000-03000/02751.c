#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int QuickSortSwap02751(int *nA, int *nB)
{
    int nTemp = 0;
    nTemp = *nA;
    *nA = *nB;
    *nB = nTemp;
    return 0;
}
int QuickSortPartion02751(int nLeft, int nRight, int *p_nList)
{
    int nPivot = 0;
    int nStore = 0;

    nPivot = (nLeft + nRight) / 2;
    nStore = nLeft;
    QuickSortSwap02751(&p_nList[nPivot], &p_nList[nRight]);

    for (int i = nLeft; i < nRight; i++)
    {
        if (p_nList[i]<p_nList[nRight])
        {
            QuickSortSwap02751(&p_nList[i], &p_nList[nStore]);
            nStore++;
        }
    }
    QuickSortSwap02751(&p_nList[nStore], &p_nList[nRight]);
    return nStore;
} 
    
int QuickSort02751(int nLeft, int nRight, int *p_nList)
{
    int nPivot = 0;
    if (nLeft < nRight)
    {
        nPivot = QuickSortPartion02751(nLeft, nRight, p_nList);
        QuickSort02751(nLeft, nPivot - 1, p_nList);
        QuickSort02751(nPivot + 1, nRight, p_nList);
    }
    return 0;
}

int Problem02751(void)
{
    int nSize = 0;
    int *p_nNum = NULL;

    scanf("%d", &nSize);

    p_nNum = malloc(sizeof(int)*nSize);
    for (int i = 0; i < nSize; i++)
    {
        scanf("%d", &p_nNum[i]);
    }

    QuickSort02751(0, nSize - 1, p_nNum);
    for (int i = 0; i < nSize; i++)
    {
        printf("%d\n", p_nNum[i]);
    }
    free(p_nNum);
    return 0;
}