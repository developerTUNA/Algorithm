#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node01158
{
    int nNum;
    struct _Node01158 *pNodeNext;
}Node01158;

typedef struct _Queue01158
{
    int nSize;
    Node01158 *pNodeHead;
    Node01158 *pNodeTail;
}Queue01158;


int QueueInitialize01158(Queue01158 *Queue)
{
    Queue->pNodeHead = NULL;
    Queue->pNodeTail = NULL;
    Queue->nSize = 0;
    return 0;
}
int QueueFinalize01158(Queue01158 *Queue)
{
    Node01158 *NodeNext = NULL;
    Node01158 *NodeFree = NULL;
    
    if(QueueEmpty01158(Queue) == 1)
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
int QueueEmpty01158(Queue01158 *Queue)
{
    return Queue->nSize;
}
int QueuePush01158(Queue01158 *Queue, int nNumPush)
{
    Node01158 *NodeNew = NULL;
    NodeNew = (Node01158*)malloc(sizeof(Node01158));
    NodeNew->nNum = nNumPush;
    NodeNew->pNodeNext = NULL;

    if(QueueEmpty01158(Queue) == 0)
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

int QueuePop01158(Queue01158 *Queue, int *nPopNum)
{
    Node01158 *NodeTemp = NULL;
    Node01158 *NodePop = NULL;
    if(QueueEmpty01158(Queue) == 0)
    {
        return -1;
    }
    
    NodePop = Queue->pNodeHead;
    *nPopNum = NodePop->nNum;
    Queue->pNodeHead = Queue->pNodeHead->pNodeNext;
    
    free(NodePop);
    Queue->nSize--;
    
    return 0;
}


int Problem01158(void)
{
    int nPeople = 0;
    int nJump = 0;
    int nTemp = 0;
    Queue01158 Queue;

    QueueInitialize01158(&Queue);
    scanf("%d %d", &nPeople, &nJump);
    for(int i = 1; i <= nPeople; i++)
    {
        QueuePush01158(&Queue, i);
    }
    printf("<");
    for(int i = 0; i < nPeople; i++)
    {
        for(int j = 1; j < nJump; j++)
        {
            QueuePop01158(&Queue, &nTemp);
            QueuePush01158(&Queue, nTemp);
        }
        QueuePop01158(&Queue, &nTemp);
        printf("%d", nTemp);
        if(i != nPeople-1)
        {
            printf(", ");
        }
    }
    printf(">");
    QueueFinalize01158(&Queue);
    return 0;
}
