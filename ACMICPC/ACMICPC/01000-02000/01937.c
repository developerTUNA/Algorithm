#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _HeapNode01937
{
    int nOrder;
    void *p_Data;
}HeapNode01937;

typedef struct _Heap01937
{
    int nDataNum;
    HeapNode01937 *pstr_HeapArr;
}Heap01937;

int HeapInitialize01937(Heap01937 *pstr_HeapHead, int nSize)
{
    pstr_HeapHead->pstr_HeapArr = (HeapNode01937*)malloc(sizeof(HeapNode01937)*nSize);
    if(pstr_HeapHead->pstr_HeapArr == NULL)
    {
        return 1;
    }
    memset(pstr_HeapHead->pstr_HeapArr, 0, sizeof(HeapNode01937)*nSize);
    pstr_HeapHead->nDataNum = 0;
    return 0;
}
int HeapFinalize01937(Heap01937 *pstr_HeapHead, int nSize)
{
    if(pstr_HeapHead->pstr_HeapArr == NULL)
    {
        return 1;
    }
    free(pstr_HeapHead->pstr_HeapArr);
    return 0;
}
int HeapEmpty01937(Heap01937 *pstr_HeapHead)
{
    if(pstr_HeapHead->nDataNum == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int HeapGetParentIDX(int nIdx)
{
    return nIdx/2;
}
int HeapGetChildLeftIDX(int nIdx)
{
    return nIdx * 2;
}
int HeapGetChildRightIDX(int nIdx)
{
    return nIdx * 2 + 1;
}
int HeapGetHighOrderChild(Heap01937 *pstr_HeapHead, int nIdx)
{
    int nHeapData = pstr_HeapHead->nDataNum;
    int nChildLeftIDX = HeapGetChildLeftIDX(nIdx);
    int nChildRightIDX = HeapGetChildRightIDX(nIdx);
    
    if(nHeapData < nChildLeftIDX)
    {
        return 0;
    }
    else if(nHeapData == nChildLeftIDX)
    {
        return nChildLeftIDX;
    }
    else if(pstr_HeapHead->pstr_HeapArr[nChildRightIDX].nOrder
            < pstr_HeapHead->pstr_HeapArr[nChildLeftIDX].nOrder)
    {
        return nChildRightIDX;
    }
    else
    {
        return nChildLeftIDX;
    }
}
int HeapInsert01309(Heap01937 *pstr_HeapHead, int nData, int nOrder)
{
    int nIdx = 0;
    int nParentIDX = 0;
    HeapNode01937 strHeapNodeInsert = {0,0};
    nIdx = pstr_HeapHead->nDataNum + 1;
    strHeapNodeInsert.nData = nData;
    strHeapNodeInsert.nOrder = nOrder;

    while(nIdx != 1)
    {
        nParentIDX = HeapGetParentIDX(nIdx);
        if(nOrder < pstr_HeapHead->pstr_HeapArr[nParentIDX].nOrder)
        {
            pstr_HeapHead->pstr_HeapArr[nIdx] = pstr_HeapHead->pstr_HeapArr[nParentIDX];
            nIdx = HeapGetParentIDX(nIdx);
        }
        else
        {
            break;
        }
    }
    pstr_HeapHead->pstr_HeapArr[nIdx] = strHeapNodeInsert;
    pstr_HeapHead->nDataNum += 1;
    return 0;
}

int HeapDelete(Heap01937 *pstr_HeapHead)
{

}
int Problem01309(void)
{
    int nSize = 0;
    int **pp_nForest = NULL;
    int *p_nHeap = NULL;
    scanf("%d", &nSize);
    pp_nForest = (int **)malloc(sizeof(int*)*nSize);
    for(int i = 0; i < nSize; i++)
    {
        pp_nForest[i] = (int*)malloc(sizeof(int)*nSize);
        memset(pp_nForest[i], 0, sizeof(int)*nSize);
    }

    return 0;
}