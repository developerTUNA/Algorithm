#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int QuickSortSwap01920(int *p_nA, int *p_nB)
{
    int nTemp = 0;
    nTemp = *p_nA;
    *p_nA = *p_nB;
    *p_nB = nTemp;
    return 0;
}

int QuickSortPartion01920(int *p_nList, int nLeft, int nRight)
{
    int nPivot = 0;
    int nStore = 0;
    
    nPivot = (nLeft + nRight) / 2;
    nStore = nLeft;
    QuickSortSwap01920(&p_nList[nPivot], &p_nList[nRight]);
    for(int i = nLeft; i < nRight; i++)
    {
        if(p_nList[i] < p_nList[nRight])
        {
            QuickSortSwap01920(&p_nList[i], &p_nList[nStore]);
            nStore++;
        }
    }
    QuickSortSwap01920(&p_nList[nRight], &p_nList[nStore]);

    return nStore;
}

int QuickSort01920(int *p_nList, int nLeft, int nRight)
{
    int nPivot = 0;

    if(nLeft < nRight)
    {
        nPivot = QuickSortPartion01920(p_nList, nLeft, nRight);
        QuickSort01920(p_nList, nLeft, nPivot - 1);
        QuickSort01920(p_nList, nPivot + 1, nRight);
    }
    return 0;
}

int BinarySearch01920(int *p_nList, int nListSize, int nFindNum)
{
    int nLow = 0;
    int nHigh = nListSize;
    int nMid = 0;
    while(nLow <= nHigh)
    {
        nMid = (nLow + nHigh) / 2;
        if(p_nList[nMid] == nFindNum)
        {
            return 1;
        }
        else if(p_nList[nMid] < nFindNum)
        {
            nLow = nMid + 1;
        }
        else
        {
            nHigh = nMid - 1;
        }
    }
    return 0;
}
int Problem01920(void)
{
    int nInputNum = 0;
    int nCheckNum = 0;
    int *p_nInputList = NULL;
    int *p_nCheckList = NULL;
    int *p_nResultList = NULL;
    scanf("%d", &nInputNum);
    p_nInputList = (int*)malloc(sizeof(int)*nInputNum);
    memset(p_nInputList, 0, sizeof(int)*nInputNum);
    for(int i=0;i<nInputNum;i++)
    {
        scanf("%d", &p_nInputList[i]);
    }
    QuickSort01920(p_nInputList, 0, nInputNum-1);

    scanf("%d", &nCheckNum);
    p_nCheckList = (int*)malloc(sizeof(int)*nCheckNum);
    p_nResultList = (int *)malloc(sizeof(int)*nCheckNum);
    memset(p_nCheckList, 0, sizeof(int)*nCheckNum);
    memset(p_nResultList, 0, sizeof(int)*nCheckNum);
    for(int i = 0; i < nCheckNum; i++)
    {
        scanf("%d", &p_nCheckList[i]);
    }

    for(int i = 0; i < nCheckNum; i++)
    {
        p_nResultList[i] = BinarySearch01920(p_nInputList, nInputNum-1, p_nCheckList[i]);
    }

    for(int i = 0; i < nCheckNum; i++)
    {
        printf("%d\n", p_nResultList[i]);
    }
    
    free(p_nInputList);
    free(p_nCheckList);
    free(p_nResultList);
    return 0;
}