#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int OrderType;

typedef struct _HeapNode
{
    int nOrder;
    void *p_Data;
}HeapNode;

typedef struct _Heap
{
    int nDataNum;
    int nTotalSize;
    int nBlockSize;
    int(*pfunc_Compare)(OrderType, OrderType);
    HeapNode *pstr_HeapArr;
}Heap;

int HeapCompare(OrderType nA, OrderType nB)
{
    if(nA > nB)
    {
        return 1;
    }
    else if(nA == nB)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}


int HeapInitialize(Heap *pstr_HeapHead, int(*pfunc_Compare)(OrderType, OrderType), int nBlockSize)
{
    pstr_HeapHead->pstr_HeapArr = (HeapNode*)malloc(sizeof(HeapNode)*nBlockSize);
    if(pstr_HeapHead->pstr_HeapArr == NULL)
    {
        return 1;
    }
    memset(pstr_HeapHead->pstr_HeapArr, 0, sizeof(HeapNode)*nBlockSize);
    pstr_HeapHead->nDataNum = 0;
    pstr_HeapHead->nTotalSize = nBlockSize;
    pstr_HeapHead->nBlockSize = nBlockSize;
    pstr_HeapHead->pfunc_Compare = pfunc_Compare;
    return 0;
}
int HeapFinalize(Heap *pstr_HeapHead, int nSize)
{
    if(pstr_HeapHead->pstr_HeapArr == NULL)
    {
        return 1;
    }
    free(pstr_HeapHead->pstr_HeapArr);
    return 0;
}
int HeapGetParentIDX(int nIdx)
{
    return nIdx / 2;
}
int HeapGetChildLeftIDX(int nIdx)
{
    return nIdx * 2;
}
int HeapGetChildRightIDX(int nIdx)
{
    return nIdx * 2 + 1;
}
int HeapGetHighOrderChild(Heap *pstr_HeapHead, int nIdx)
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
    else if(0 < pstr_HeapHead->pfunc_Compare
    (pstr_HeapHead->pstr_HeapArr[nChildRightIDX].nOrder,
     pstr_HeapHead->pstr_HeapArr[nChildLeftIDX].nOrder)
            )
    {
        return nChildRightIDX;
    }
    else
    {
        return nChildLeftIDX;
    }
}
int HeapInsert(Heap *pstr_HeapHead, void *p_Data, OrderType nOrder)
{
    int nIdx = 0;
    int nParentIDX = 0;
    HeapNode strHeapNodeInsert = {0, NULL};

    if(pstr_HeapHead->nTotalSize == (pstr_HeapHead->nDataNum + 1))
    {
        int nBlockNum = 0;
        nBlockNum = pstr_HeapHead->nTotalSize / pstr_HeapHead->nBlockSize;
        pstr_HeapHead->nTotalSize = (nBlockNum + 1)*pstr_HeapHead->nBlockSize;
        realloc(pstr_HeapHead->pstr_HeapArr, sizeof(HeapNode)*pstr_HeapHead->nTotalSize);
    }

    nIdx = pstr_HeapHead->nDataNum + 1;
    strHeapNodeInsert.p_Data = p_Data;
    strHeapNodeInsert.nOrder = nOrder;

    while(nIdx != 1)
    {
        nParentIDX = HeapGetParentIDX(nIdx);
        if(0 < pstr_HeapHead->pfunc_Compare
        (nOrder,
         pstr_HeapHead->pstr_HeapArr[nParentIDX].nOrder)
           )
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

void* HeapDelete(Heap *pstr_HeapHead)
{
    int nParentIdx = 0;
    int nChildIdx = 0;
    void *p_ReturnData = NULL;
    HeapNode strHeapNodeLast = {0, NULL};

    p_ReturnData = pstr_HeapHead->pstr_HeapArr[1].p_Data;
    strHeapNodeLast = pstr_HeapHead->pstr_HeapArr[pstr_HeapHead->nDataNum];
    nParentIdx = 1;

    while(nChildIdx = HeapGetHighOrderChild(pstr_HeapHead, nParentIdx))
    {
        if(0 <= pstr_HeapHead->pfunc_Compare
        (strHeapNodeLast.nOrder,
         pstr_HeapHead->pstr_HeapArr[nChildIdx].nOrder)
           )
        {
            break;
        }
        pstr_HeapHead->pstr_HeapArr[nParentIdx] = pstr_HeapHead->pstr_HeapArr[nChildIdx];
        nParentIdx = nChildIdx;
    }
    pstr_HeapHead->pstr_HeapArr[nParentIdx] = strHeapNodeLast;
    pstr_HeapHead->nDataNum -= 1;

    if((pstr_HeapHead->nDataNum + 1) < (pstr_HeapHead->nTotalSize - pstr_HeapHead->nBlockSize))
    {
        int nBlockNum = 0;
        nBlockNum = pstr_HeapHead->nTotalSize / pstr_HeapHead->nBlockSize;
        pstr_HeapHead->nTotalSize = (nBlockNum - 1)*pstr_HeapHead->nBlockSize;
        realloc(pstr_HeapHead->pstr_HeapArr, sizeof(HeapNode)*pstr_HeapHead->nTotalSize);
    }

    return p_ReturnData;
}