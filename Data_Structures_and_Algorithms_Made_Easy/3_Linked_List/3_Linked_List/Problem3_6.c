#include "Problem.h"
#include "LinkedList.h"
/*
 *주어진 연결리스트가 NULL로 끝나는지 아니면 사이클을 이루는지 검사하라
 *Brute force
 */
int Problem3_6(void)
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
    MakeCycle_3_6(&head, 7);
    IsCycle(&head, &resCycle);
    if(resCycle)
    {
        printf("List is Cycle\n");
    }
    else
    {
        printf("List is Non Cycle\n");
    }
    return 0;
}
int MakeCycle_3_6(struct SingleLinkedListNode **head, int linkPosition)
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

int IsCycle(struct SingleLinkedListNode **head, int *retCycle)
{
    struct SingleLinkedListNode *currentNode = NULL;
    int flag = 2;
    int count = 1;
    void **addrArray=NULL;
    currentNode = *head;
    
    while(flag && currentNode != NULL)
    {
        count++;
        flag = 2;
        addrArray = realloc(addrArray, count*sizeof(struct SingleLinkedListNode*));
        addrArray[count-1] = currentNode;
        for(int i = 0; i < count; i++)
        {
            if(addrArray[i] == currentNode)
            {
                flag--;
            }
        }
        currentNode = currentNode->next;
    }

    if(flag == 0)
    {
        *retCycle = 1;
    }
    else
    {
        *retCycle = 0;
    }
    return 0;
}