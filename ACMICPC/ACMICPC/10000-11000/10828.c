#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node10828
{
    int nNum;
    struct _Node10828 *pNodeNext;
}Node10828;

typedef struct _Stack10828
{
    int nSize;
    Node10828 *pNodeHead;
}Stack10828;

int StackPush10828(Stack10828 *Stack, int nNumPush)
{
    Node10828 *NodeNew = NULL;
    NodeNew = (Node10828*)malloc(sizeof(Node10828));
    NodeNew->nNum = nNumPush;
    NodeNew->pNodeNext = Stack->pNodeHead;
    
    Stack->nSize++;
    Stack->pNodeHead = NodeNew;
    return 0;
}

int StackPop10828(Stack10828 *Stack)
{
    int nPopNum = 0;
    Node10828 *NodePop = NULL;

    if(Stack->nSize == 0)
    {
        return -1;
    }
    NodePop = Stack->pNodeHead;
    nPopNum = NodePop->nNum;
    Stack->pNodeHead = Stack->pNodeHead->pNodeNext;
    Stack->nSize--;
    free(NodePop);
    return nPopNum;
}

int StackSize10828(Stack10828 *Stack)
{
    return Stack->nSize;
}

int StackEmpty10828(Stack10828 *Stack)
{
    if(Stack->nSize == 0)
    {
        return 1;
    }
    return 0;
}

int StackTop10828(Stack10828 *Stack)
{
    if(Stack->nSize == 0)
    {
        return -1;
    }
    return Stack->pNodeHead->nNum;
}

int Probrem10828(void)
{
    char szOperand[10] = {0,};
    int nCount = 0;
    int nNum = 0;
    Stack10828 Stack;
    
    Stack.nSize = 0;
    Stack.pNodeHead = NULL;
    scanf("%d", &nCount);

    for(int i = 0; i < nCount; i++)
    {
        memset(szOperand, 0, sizeof(szOperand));
        scanf("%s", szOperand);
        if(strcmp(szOperand, "push")==0)
        {
            nNum = 0;
            scanf("%d", &nNum);
            StackPush10828(&Stack, nNum);
        }
        else if(strcmp(szOperand, "pop") == 0)
        {
            nNum = StackPop10828(&Stack);
            printf("%d\n", nNum);
        }
        else if(strcmp(szOperand, "size") == 0)
        {
            nNum = StackSize10828(&Stack);
            printf("%d\n", nNum);
        }
        else if(strcmp(szOperand, "empty") == 0)
        {
            nNum = StackEmpty10828(&Stack);
            printf("%d\n", nNum);
        }
        else if(strcmp(szOperand, "top") == 0)
        {
            nNum = StackTop10828(&Stack);
            printf("%d\n", nNum);
        }
    }
    return 0;
}