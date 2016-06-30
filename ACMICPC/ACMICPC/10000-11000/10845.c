#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node10845
{
    int nNum;
    struct _Node10845 *pNodeNext;
}Node10845;

typedef struct _Queue10845
{
    int nSize;
    Node10845 *pNodeHead;
}Queue10845;


int QueueInitialize10845(Queue10845 *Queue)
{

}

int QueuePush10845(Queue10845 *Queue, int nNumPush)
{
    Node10845 *NodeNew = NULL;
    NodeNew = (Node10845*)malloc(sizeof(Node10845));
    NodeNew->nNum = nNumPush;
    NodeNew->pNodeNext = Queue->pNodeHead;

    Queue->nSize++;
    Queue->pNodeHead = NodeNew;
    return 0;
}

int QueuePop10845(Queue10845 *Queue)
{
    int nPopNum = 0;
    Node10845 *NodeTemp = NULL;
    Node10845 *NodePop = NULL;

    if(Queue->nSize == 0)
    {
        return -1;
    }
    NodeTemp = Queue->pNodeHead;
    NodePop = NodeTemp->pNodeNext;
    while(NodeTemp->pNodeNext != NULL)
    {
        NodeTemp = NodeTemp->pNodeNext;
        NodePop = NodePop->pNodeNext;
    }
    nPopNum = NodePop->nNum;
    NodeTemp->pNodeNext = NULL;
    free(NodePop);
    Queue->nSize--;
    return nPopNum;
}

int QueueSize10845(Queue10845 *Queue)
{
    return Queue->nSize;
}

int QueueEmpty10845(Queue10845 *Queue)
{
    if(Queue->nSize == 0)
    {
        return 1;
    }
    return 0;
}

int QueueTop10845(Queue10845 *Queue)
{
    if(Queue->nSize == 0)
    {
        return -1;
    }
    return Queue->pNodeHead->nNum;
}




int Problem10845(void)
{
    char szOperand[10] = {0,};
    int nCount = 0;
    int nNum = 0;
    Queue10845 Queue;

    Queue.nSize = 0;
    Queue.pNodeHead = NULL;
    scanf("%d", &nCount);

    for(int i = 0; i < nCount; i++)
    {
        memset(szOperand, 0, sizeof(szOperand));
        scanf("%s", szOperand);
        if(strcmp(szOperand, "push") == 0)
        {
            nNum = 0;
            scanf("%d", &nNum);
            QueuePush10845(&Queue, nNum);
        }
        else if(strcmp(szOperand, "pop") == 0)
        {
            nNum = QueuePop10845(&Queue);
            printf("%d\n", nNum);
        }
        else if(strcmp(szOperand, "size") == 0)
        {
            nNum = QueueSize10845(&Queue);
            printf("%d\n", nNum);
        }
        else if(strcmp(szOperand, "empty") == 0)
        {
            nNum = QueueEmpty10845(&Queue);
            printf("%d\n", nNum);
        }
        else if(strcmp(szOperand, "top") == 0)
        {
            nNum = QueueTop10845(&Queue);
            printf("%d\n", nNum);
        }
    }
    return 0;
}