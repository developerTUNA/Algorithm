#include "Problem.h"
#include "LinkedList.h"

/*
 *주어진 연결리스트가 NULL로 끝나는지 아니면 사이클을 이루는지 검사하라
 * Floyd Algo
 */

int Problem3_9(void)
{
    struct SingleLinkedListNode *head = NULL;
    int resCycle = 0;
    SingleLinkedListInsert(&head, 1, 1);
    SingleLinkedListInsert(&head, 2, 1);
    SingleLinkedListInsert(&head, 4, 1);
    SingleLinkedListInsert(&head, 8, 1);
    SingleLinkedListInsert(&head, 16, 1);
    SingleLinkedListInsert(&head, 32, 1);
    SingleLinkedListInsert(&head, 64, 1);
    SingleLinkedListInsert(&head, 128, 1);
    SingleLinkedListInsert(&head, 256, 1);
    SingleLinkedListInsert(&head, 512, 1);
    SingleLinkedListInsert(&head, 1024, 1);
    SingleLinkedListInsert(&head, 2048, 1);
    SingleLinkedListInsert(&head, 4096, 1);
    SingleLinkedListInsert(&head, 8192, 1);
    SingleLinkedListInsert(&head, 16384, 1);
    SingleLinkedListInsert(&head, 32768, 1);
    SingleLinkedListInsert(&head, 65536, 1);
    //MakeCycle_3_9(&head, 4);
    Floyd(&head, &resCycle);
    if(resCycle)
    {
        printf("Cycle List\n");
    }
    else
    {
        printf("Non Cycle List\n");
    }
    return 0;
}
int MakeCycle_3_9(struct SingleLinkedListNode **head, int linkPosition)
{
    struct SingleLinkedListNode *linkNode = NULL;
    struct SingleLinkedListNode *tailNode = NULL;

    tailNode = *head;
    while(tailNode->next != NULL)
    {
        tailNode = tailNode->next;
    }

    linkNode = *head;
    for(int i = 1; i < linkPosition; i++)
    {
        if(linkNode == tailNode)
        {
            break;
        }
        linkNode = linkNode->next;
    }
    tailNode->next = linkNode;
    return 0;
}

int Floyd(struct SingleLinkedListNode **head, int *retCycle)
{
    struct SingleLinkedListNode *slowCurrent = NULL;
    struct SingleLinkedListNode *fastCurrent = NULL;
    slowCurrent = *head;
    fastCurrent = *head;

    while(slowCurrent && fastCurrent)
    {
        fastCurrent = fastCurrent->next;
        if(slowCurrent == fastCurrent)
        {
            *retCycle = 1;
            break;
        }
        else if(fastCurrent == NULL)
        {
            *retCycle = 0;
            break;
        }
        fastCurrent = fastCurrent->next;
        if(slowCurrent == fastCurrent)
        {
            *retCycle = 1;
            break;
        }
        else if(fastCurrent == NULL)
        {
            *retCycle = 0;
            break;
        }
        slowCurrent = slowCurrent->next;
    }
    return 0;
}