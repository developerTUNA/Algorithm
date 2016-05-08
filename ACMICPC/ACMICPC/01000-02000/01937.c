#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int HeapCompare01937(int nA, int nB)
{
    if(nA > nB)
    {
        return 1;
    }
    else if(nA == nB)
    {
        return 0;
    }
    else if(nA < nB)
    {
        return -1;
    }
}

typedef struct _HeapNode01937
{
    int nOrder;
    void *p_Data;
}HeapNode01937;

typedef struct _Heap01937
{
    int nDataNum;
    int nTotalSize;
    int nBlockSize;
    int (*pfunc_Compare)(int,int);
    HeapNode01937 *pstr_HeapArr;
}Heap01937;



int HeapInitialize01937(Heap01937 *pstr_HeapHead, void(*pfunc_Compare)(int, int) ,int nSize)
{
    pstr_HeapHead->pstr_HeapArr = (HeapNode01937*)malloc(sizeof(HeapNode01937)*nSize);
    if(pstr_HeapHead->pstr_HeapArr == NULL)
    {
        return 1;
    }
    memset(pstr_HeapHead->pstr_HeapArr, 0, sizeof(HeapNode01937)*nSize);
    pstr_HeapHead->nDataNum = 0;
    pstr_HeapHead->nTotalSize = nSize;
    pstr_HeapHead->nBlockSize = nSize;
    pstr_HeapHead->pfunc_Compare = pfunc_Compare;
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
int HeapSize01937(Heap01937 *pstr_HeapHead)
{
    return pstr_HeapHead->nDataNum;
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
        pstr_HeapHead->pfunc_Compare(4, 5);
        return nChildLeftIDX;
    }
    else if(0 < pstr_HeapHead->pfunc_Compare
                                            (pstr_HeapHead->pstr_HeapArr[nChildRightIDX].nOrder ,
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
int HeapInsert01309(Heap01937 *pstr_HeapHead, void *p_Data, int nOrder)
{
    int nIdx = 0;
    int nParentIDX = 0;
    HeapNode01937 strHeapNodeInsert = {0, NULL};
    nIdx = pstr_HeapHead->nDataNum + 1;
    strHeapNodeInsert.p_Data = p_Data;
    strHeapNodeInsert.nOrder = nOrder;

    while(nIdx != 1)
    {
        nParentIDX = HeapGetParentIDX(nIdx);
        if(0 < pstr_HeapHead->pfunc_Compare
                                           (nOrder ,
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

void* HeapDelete(Heap01937 *pstr_HeapHead)
{
    int nParentIdx = 0;
    int nChildIdx = 0;
    void *p_ReturnData = NULL;
    HeapNode01937 strHeapNodeLast = {0, NULL};

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
    return p_ReturnData;
}
int Problem01937(void)
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

    int *p_test;


    Heap01937 strHeap;
    HeapInitialize01937(&strHeap, HeapCompare01937, 1024);
    p_test = malloc(sizeof(int) * 2);
    p_test[0] = 1;
    p_test[1] = 2;
    HeapInsert01309(&strHeap, p_test, 4);
    
    p_test = malloc(sizeof(int) * 2);
    p_test[0] = 3;
    p_test[1] = 4;
    HeapInsert01309(&strHeap, p_test, 5);
    
    p_test = malloc(sizeof(int) * 2);
    p_test[0] = 5;
    p_test[1] = 6;
    HeapInsert01309(&strHeap, p_test, 6);
    
    p_test = malloc(sizeof(int) * 2);
    p_test[0] = 7;
    p_test[1] = 8;
    HeapInsert01309(&strHeap, p_test, 1);
    
    p_test = malloc(sizeof(int) * 2);
    p_test[0] = 9;
    p_test[1] = 10;
    HeapInsert01309(&strHeap, p_test, 2);
    
    p_test = malloc(sizeof(int) * 2);
    p_test[0] = 11;
    p_test[1] = 12;
    HeapInsert01309(&strHeap, p_test, 3);

    p_test = HeapDelete(&strHeap);
    p_test = HeapDelete(&strHeap);
    p_test = HeapDelete(&strHeap);
    p_test = HeapDelete(&strHeap);
    p_test = HeapDelete(&strHeap);
    p_test = HeapDelete(&strHeap);
    return 0;
}