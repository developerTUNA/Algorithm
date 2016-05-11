#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int OrderType01937;

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
    int(*pfunc_Compare)(OrderType01937, OrderType01937);
    HeapNode01937 *pstr_HeapArr;
}Heap01937;

int HeapCompare01937(OrderType01937 nA, OrderType01937 nB)
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


int HeapInitialize(Heap01937 *pstr_HeapHead, int(*pfunc_Compare)(OrderType01937, OrderType01937), int nBlockSize)
{
    pstr_HeapHead->pstr_HeapArr = (HeapNode01937*)malloc(sizeof(HeapNode01937)*nBlockSize);
    if(pstr_HeapHead->pstr_HeapArr == NULL)
    {
        return 1;
    }
    memset(pstr_HeapHead->pstr_HeapArr, 0, sizeof(HeapNode01937)*nBlockSize);
    pstr_HeapHead->nDataNum = 0;
    pstr_HeapHead->nTotalSize = nBlockSize;
    pstr_HeapHead->nBlockSize = nBlockSize;
    pstr_HeapHead->pfunc_Compare = pfunc_Compare;
    return 0;
}
int HeapFinalize(Heap01937 *pstr_HeapHead, int nSize)
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
int HeapInsert(Heap01937 *pstr_HeapHead, void *p_Data, OrderType01937 nOrder)
{
    int nIdx = 0;
    int nParentIDX = 0;
    HeapNode01937 strHeapNodeInsert = {0, NULL};

    if(pstr_HeapHead->nTotalSize == (pstr_HeapHead->nDataNum + 1))
    {
        int nBlockNum = 0;
        nBlockNum = pstr_HeapHead->nTotalSize / pstr_HeapHead->nBlockSize;
        pstr_HeapHead->nTotalSize = (nBlockNum + 1)*pstr_HeapHead->nBlockSize;
        realloc(pstr_HeapHead->pstr_HeapArr, sizeof(HeapNode01937)*pstr_HeapHead->nTotalSize);
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

    if((pstr_HeapHead->nDataNum + 1) < (pstr_HeapHead->nTotalSize - pstr_HeapHead->nBlockSize))
    {
        int nBlockNum = 0;
        nBlockNum = pstr_HeapHead->nTotalSize / pstr_HeapHead->nBlockSize;
        pstr_HeapHead->nTotalSize = (nBlockNum - 1)*pstr_HeapHead->nBlockSize;
        realloc(pstr_HeapHead->pstr_HeapArr, sizeof(HeapNode01937)*pstr_HeapHead->nTotalSize);
    }

    return p_ReturnData;
}

int Problem01937(void)
{
    int nSize = 0;
	int *p_nRowCol = NULL;
    int **pp_nForest = NULL;
	Heap01937 OrderHeap;
    
	scanf("%d", &nSize);
    pp_nForest = (int **)malloc(sizeof(int*)*nSize);
    for(int i = 0; i < nSize; i++)
    {
        pp_nForest[i] = (int*)malloc(sizeof(int)*nSize);
        memset(pp_nForest[i], 0, sizeof(int)*nSize);
    }

	HeapInitialize(&OrderHeap, HeapCompare01937, nSize*nSize + 1);
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			scanf("%d", &pp_nForest[i][j]);
			p_nRowCol = malloc(sizeof(int) * 2);
			p_nRowCol[0] = i;
			p_nRowCol[1] = j;
			HeapInsert(&OrderHeap, p_nRowCol, pp_nForest[i][j]);
		}
	}
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			p_nRowCol = HeapDelete(&OrderHeap);
			printf("%d : (%d, %d)\n", pp_nForest[i][j], p_nRowCol[0], p_nRowCol[1]);
		}
	}
    
    return 0;
}
