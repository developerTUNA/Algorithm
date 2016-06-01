#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node10866
{
    int nNum;
    struct _Node10866 *pNodeNext;
    struct _Node10866 *pNodePrev;
}Node10866;

typedef struct _Deque10866
{
    int nSize;
    Node10866 *pNodeHead;
    Node10866 *pNodeTail;
}Deque10866;


int DequeSize10866(Deque10866 *Deque)
{
    return Deque->nSize;
}

int DequeEmpty10866(Deque10866 *Deque)
{
    if(0 == Deque->nSize)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DequeInitialize10866(Deque10866 *Deque)
{
    Deque->pNodeHead = NULL;
    Deque->pNodeTail = NULL;
    Deque->nSize = 0;
    return 0;
}

int DequeFinalize10866(Deque10866 *Deque)
{
    Node10866 *pNodeNext;
    Node10866 *pNodeFree;

    if(DequeEmpty10866(Deque) == 1)
    {
        return 0;
    }

    pNodeNext = Deque->pNodeHead;
    while(pNodeNext != NULL)
    {
        pNodeFree = pNodeNext;
        pNodeNext = pNodeNext->pNodeNext;
        free(pNodeFree);
    }
    return 0;
}

int DequePushHead10866(Deque10866 *Deque, int nNum)
{
    Node10866 *pNodeNew = NULL;
    pNodeNew = (Node10866*)malloc(sizeof(Node10866));

    pNodeNew->nNum = nNum;
    pNodeNew->pNodePrev = NULL;
    pNodeNew->pNodeNext = Deque->pNodeHead;
    Deque->pNodeHead = pNodeNew;
    Deque->nSize += 1;
    return 0;
}

int DequePushTail10866(Deque10866 *Deque, int nNum)
{
    Node10866 *pNodeNew = NULL;
    pNodeNew = (Node10866*)malloc(sizeof(Node10866));

    pNodeNew->nNum = nNum;
    pNodeNew->pNodePrev = Deque->pNodeTail;
    pNodeNew->pNodeNext = NULL;
    Deque->pNodeTail = pNodeNew;
    Deque->nSize += 1;
    return 0;
}

int DequePopHead10866(Deque10866 *Deque, int *nNum)
{
    Node10866 *pNodePop = NULL;
    pNodePop = Deque->pNodeHead;

    if(DequeEmpty10866(Deque))
    {
        return 1;
    }

    *nNum = pNodePop->nNum;

    Deque->pNodeHead = pNodePop->pNodeNext;
    if(Deque->pNodeHead != NULL)
    {
        Deque->pNodeHead->pNodePrev = NULL;
    }
    free(pNodePop);
    Deque->nSize -= 1;
    return 0;
}

int DequePopTail10866(Deque10866 *Deque, int *nNum)
{
    Node10866 *pNodePop = NULL;
    pNodePop = Deque->pNodeTail;

    if(DequeEmpty10866(Deque))
    {
        return 1;
    }

    *nNum = pNodePop->nNum;
    Deque->pNodeTail = pNodePop->pNodePrev;
    if(Deque->pNodeTail != NULL)
    {
        Deque->pNodeTail->pNodeNext = NULL;
    }
    free(pNodePop);
    Deque->nSize -= 1;
    return 0;
}

int DequeHead10866(Deque10866 *Deque, int *nNum)
{
    if(DequeEmpty10866(Deque))
    {
        return 1;
    }
    *nNum = Deque->pNodeHead->nNum;
    return 0;
}

int DequeTail10866(Deque10866 *Deque, int *nNum)
{
    if(DequeEmpty10866(Deque))
    {
        return 1;
    }
    *nNum = Deque->pNodeTail->nNum;
    return 0;
}

int Problem10866(void)
{
    char czOperand[20] = {0,};
    int nCount = 0;
    int nNum = 0;
    Deque10866 Deque;

    DequeInitialize10866(&Deque);

    scanf("%d", &nCount);
    for(int i = 0; i < nCount; i++)
    {
        memset(czOperand, 0, sizeof(czOperand));
        nNum = 0;
        scanf("%s", czOperand);

        if(strcmp(czOperand, "push_front") == 0)
        {
            scanf("%d", &nNum);
            DequePushHead10866(&Deque, nNum);
        }
        else if(strcmp(czOperand, "push_back") == 0)
        {
            scanf("%d", &nNum);
            DequePushTail10866(&Deque, nNum);
        }
        else if(strcmp(czOperand, "pop_front") == 0)
        {
            if(DequePopHead10866(&Deque, &nNum))
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", nNum);
            }
        }
        else if(strcmp(czOperand, "pop_back") == 0)
        {
            if(DequePopTail10866(&Deque, &nNum))
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", nNum);
            }
        }
        else if(strcmp(czOperand, "size") == 0)
        {
            nNum = DequeSize10866(&Deque);
            printf("%d\n", nNum);
        }
        else if(strcmp(czOperand, "empty") == 0)
        {
            nNum = DequeEmpty10866(&Deque);
            printf("%d\n", nNum);
        }
        else if(strcmp(czOperand, "front") == 0)
        {
            if(DequeHead10866(&Deque, &nNum))
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", nNum);
            }
        }
        else if(strcmp(czOperand, "back") == 0)
        {
            if(DequeTail10866(&Deque, &nNum))
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", nNum);
            }
        }
    }

    DequeFinalize10866(&Deque);
    return 0;
}