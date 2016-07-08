#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Edge02606
{
    int nFrom;
    int nTo;
}Edge02606;

int QuickSortSwap02606(Edge02606 *pEdgeA, Edge02606 *pEdgeB)
{
    Edge02606 Edge_Temp = {0,0};

    Edge_Temp.nFrom = pEdgeA->nFrom;
    Edge_Temp.nTo = pEdgeA->nTo;
    pEdgeA->nFrom = pEdgeB->nFrom;
    pEdgeA->nTo = pEdgeB->nTo;
    pEdgeB->nFrom = Edge_Temp.nFrom;
    pEdgeB->nTo = Edge_Temp.nTo;

    return 0;
}

int QuickSortPartion02606(Edge02606 *pEdge, int nLeft, int nRight)
{
    int nPivot = 0;
    int nStore = 0;
    
    nPivot = (nLeft + nRight) / 2;
    QuickSortSwap02606(&pEdge[nPivot], &pEdge[nRight]);
    nStore = nLeft;

    for(int i = nLeft; i < nRight; i++)
    {
        if(pEdge[i].nFrom < pEdge[nRight].nFrom)
        {
            QuickSortSwap02606(&pEdge[i], &pEdge[nStore]);
            nStore++;
        }
        else if(pEdge[i].nFrom == pEdge[nRight].nFrom && pEdge[i].nTo < pEdge[nRight].nTo)
        {
            QuickSortSwap02606(&pEdge[i], &pEdge[nStore]);
            nStore++;
        }
    }
    QuickSortSwap02606(&pEdge[nStore], &pEdge[nRight]);
    return nStore;
}

int QuickSort02606(Edge02606 *pEdge, int nLeft, int nRight)
{
    int nPartion = 0;
    if(nLeft < nRight)
    {
        nPartion = QuickSortPartion02606(pEdge,nLeft,nRight);
        QuickSort02606(pEdge, nLeft, nPartion-1);
        QuickSort02606(pEdge, nPartion + 1, nRight);
    }

    return 0;
}

typedef struct _Node02606
{
    struct _Node02606 *pNodeNext;
    int nData;
}Node02606;

typedef struct _Queue02606
{
    Node02606 *pNodeHead;
    Node02606 *pNodeTail;
    int nSize;
}Queue02606;

int QueueInitialize02606(Queue02606 *Queue)
{
    Queue->pNodeHead = NULL;
    Queue->pNodeTail = NULL;
    Queue->nSize = 0;
}

int QueueFianlize02606(Queue02606 *Queue)
{
    Node02606 *pNodeNext = NULL;
    Node02606 *pNodeFree = NULL;
    if(Queue->pNodeHead == NULL)
    {
        return 0;
    }
    pNodeNext = Queue->pNodeHead;
    while(pNodeNext != NULL)
    {
        pNodeFree = pNodeNext;
        pNodeNext = pNodeNext->pNodeNext;
        free(pNodeFree);
    }
    Queue->pNodeHead = NULL;
    Queue->pNodeTail = NULL;
    Queue->nSize = 0;
}
int QueueEmpty02606(Queue02606 *Queue)
{
    if(Queue->nSize)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int QueuePush02606(Queue02606 *Queue, int nData)
{
    Node02606 *NodeNew = NULL;
    NodeNew = (Node02606*)malloc(sizeof(Node02606));
    NodeNew->nData = nData;
    NodeNew->pNodeNext = NULL;
    if(Queue->pNodeTail == NULL)
    {
        Queue->pNodeHead = NodeNew;
        Queue->pNodeTail = NodeNew;
    }
    else
    {
        Queue->pNodeTail->pNodeNext = NodeNew;
        Queue->pNodeTail = NodeNew;
    }
    Queue->nSize++;
    return 0;
}

int QueuePop02606(Queue02606 *Queue, int *nData)
{
    Node02606 *NodePop = NULL;
    if(Queue->pNodeHead == NULL)
    {
        return 1;
    }

    *nData = Queue->pNodeHead->nData;
    NodePop = Queue->pNodeHead;
    if(Queue->pNodeHead == Queue->pNodeTail)
    {
        Queue->pNodeHead = NULL;
        Queue->pNodeTail = NULL;
    }
    else
    {
        Queue->pNodeHead = Queue->pNodeHead->pNodeNext;
    }
    Queue->nSize--;
    free(NodePop);
    return 0;
}

int GraphBFS02606(Edge02606 *pEdge, int *p_nEdgeCount, int *p_nVirusCheck, int nComputerNum, int nNetworkNum)
{
    Queue02606 *Queue = NULL;
    int nVirusNum = 0;
    QueueInitialize02606(Queue);
    QueuePush02606(Queue, 1);

    QueueFianlize02606(Queue);
}

int Problem02606(void)
{
    int nComputerNum = 0;
    int nNetworkNum = 0;
    int nVirusNum = 0;
    int nFrom = 0;
    int nTo = 0;
    int *p_nVirusCheck = NULL;
    int *p_nEdgeCount = NULL;
    Edge02606 *pEdge = NULL;
    
    scanf("%d", &nComputerNum);
    scanf("%d", &nNetworkNum);
    p_nVirusCheck = (int*)malloc(sizeof(int)*(nComputerNum + 1));
    p_nEdgeCount = (int*)malloc(sizeof(int)*(nNetworkNum + 1));
    pEdge = (Edge02606*)malloc(sizeof(Edge02606)*(nNetworkNum));
    memset(p_nVirusCheck, 0, sizeof(int)*(nComputerNum + 1));
    memset(p_nEdgeCount, 0, sizeof(int)*(nNetworkNum + 1));
    memset(pEdge, 0, sizeof(Edge02606)*(nNetworkNum));

    for(int i = 0; i < nNetworkNum; i++)
    {
        scanf("%d %d", &nFrom, &nTo);
        p_nEdgeCount[nFrom] ++;
        pEdge[i].nFrom = nFrom;
        pEdge[i].nTo = nTo;
    }
    for(int i = 1; i <= nNetworkNum; i++)
    {
        p_nEdgeCount[i] = p_nEdgeCount[i - 1] + p_nEdgeCount[i];
    }
    QuickSort02606(pEdge, 0, nNetworkNum - 1);




    free(p_nVirusCheck);
    free(p_nEdgeCount);
    free(pEdge);
    
    return 0;
}
