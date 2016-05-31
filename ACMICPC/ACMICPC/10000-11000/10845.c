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
    Node10845 *pNodeTail;
}Queue10845;

int QueueEmpty10845(Queue10845 *Queue)
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
int QueueSize10845(Queue10845 *Queue)
{
    return Queue->nSize;
}

int QueueInitialize10845(Queue10845 *Queue)
{
    Queue->pNodeHead = NULL;
    Queue->pNodeTail = NULL;
    Queue->nSize = 0;
    return 0;
}
int QueueFinalize10845(Queue10845 *Queue)
{
    Node10845 *NodeNext = NULL;
    Node10845 *NodeFree = NULL;

    if(QueueEmpty10845(Queue) == 1)
    {
        return 0;
    }

    NodeNext = Queue->pNodeHead;
    while(NodeNext != NULL)
    {
        NodeFree = NodeNext;
        NodeNext = NodeNext->pNodeNext;
        free(NodeFree);
    }

    return 0;
}

int QueuePush10845(Queue10845 *Queue, int nNumPush)
{
    Node10845 *NodeNew = NULL;
    NodeNew = (Node10845*)malloc(sizeof(Node10845));
    NodeNew->nNum = nNumPush;
    NodeNew->pNodeNext = NULL;

    if(QueueEmpty10845(Queue))
    {
        Queue->pNodeHead = NodeNew;
        Queue->pNodeTail = NodeNew;
    }
    else
    {
        Queue->pNodeTail->pNodeNext = NodeNew;
        Queue->pNodeTail = NodeNew;
    }
    Queue->nSize += 1;
    return 0;
}

int QueuePop10845(Queue10845 *Queue, int *nPopNum)
{
    Node10845 *NodeTemp = NULL;
    Node10845 *NodePop = NULL;
    if(QueueEmpty10845(Queue))
    {
        return -1;
    }

    NodePop = Queue->pNodeHead;
    *nPopNum = NodePop->nNum;
    Queue->pNodeHead = Queue->pNodeHead->pNodeNext;

    free(NodePop);
    Queue->nSize-=1;

    return 0;
}

int QueueFront10845(Queue10845 *Queue, int *nResult)
{
    if(QueueEmpty10845(Queue))
    {
        return 1;
    }
    *nResult = Queue->pNodeHead->nNum;
    return 0;
}

int QueueBack10845(Queue10845 *Queue, int *nResult)
{
    if(QueueEmpty10845(Queue))
    {
        return 1;
    }
    *nResult = Queue->pNodeTail->nNum;
    return 0;
}

int Problem10845(void)
{
    char szOperand[10] = {0,};
    int nCount = 0;
    int nNum = 0;
    Queue10845 Queue;

    QueueInitialize10845(&Queue);
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
            if (QueuePop10845(&Queue, &nNum)== 0)
            {
                printf("%d\n", nNum);
            }
            else
            {
                printf("-1\n");
            }
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
        else if(strcmp(szOperand, "front") == 0)
        {
            if (QueueFront10845(&Queue, &nNum))
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", nNum);
            }
        }
        else if(strcmp(szOperand, "back") == 0)
        {
            if(QueueBack10845(&Queue, &nNum))
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", nNum);
            }
        }
    }
    QueueFinalize10845(&Queue);
    return 0;
}
