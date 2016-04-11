#include <stdio.h>
#include <stdlib.h>

struct DoubleLinkedListNode
{
    int data;
    struct DoubleLinkedListNode *next;
    struct DoubleLinkedListNode *prev;
};


int DoubleLinkedListLength(struct DoubleLinkedListNode *head)
{
    struct DoubleLinkedListNode *current = NULL;
    current = head;
    int count = 0;
    while(current != NULL)                                                                          //NULL이 나올때까지
    {
        count++;                                                                                    //count 값 증가
        current = current->next;                                                                    //다음 노드로 이동
    }
    return count;
}


int DoubleLinkedListInsert(struct DoubleLinkedListNode **head, int data, int position)
{
    int count = 1;
    struct DoubleLinkedListNode *newNode = NULL;
    struct DoubleLinkedListNode *prevNode = NULL;
    struct DoubleLinkedListNode *nextNode = NULL;

    newNode = (struct DoubleLinkedListNode *)malloc(sizeof(struct DoubleLinkedListNode));
    if(!newNode)
    {
        printf("Memory Error\n");
        return 1;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        return 0;
    }

    if(position == 1)
    {
        newNode->prev = NULL;
        newNode->next = *head;
        *head = newNode;
        return 0;
    }

    nextNode = *head;
    while((nextNode != NULL) && (count < position))
    {
        count++;
        prevNode = nextNode;
        nextNode = nextNode->next;
    }
    if(nextNode == NULL)
    {
        if(count == position)
        {
        newNode->next = NULL;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        }
        else
        {
            printf("List Size Exceed\n");
            return 1;
        }
    }
    else
    {
        prevNode->next = newNode;
        newNode->next = nextNode;
        newNode->prev = prevNode;
        nextNode->prev = newNode;
    }
    return 0;
}

int DoubleLinkedListDelete(struct DoubleLinkedListNode **head, int position)
{
    int count = 1;
    struct DoubleLinkedListNode *deleteNode = NULL;
    struct DoubleLinkedListNode *prevNode = NULL;

    if(*head == NULL)
    {
        printf("List is Empty.\n");
        return 1;
    }

    deleteNode = *head;
    if(position == 1)
    {
        if((*head)->next == NULL)
        {
            free(*head);
            *head = NULL;
            return 0;
        }
        *head = (*head)->next;
        free(deleteNode);
        (*head)->prev = NULL;
        return 0;
    }
    while((deleteNode != NULL) && (count < position))
    {
        count++;
        prevNode = deleteNode;
        deleteNode = deleteNode->next;
    }
    if(deleteNode == NULL)
    {
            printf("List Size Exceed\n");
            return 1;
    }
    else
    {
        if(deleteNode->next != NULL)
        {
            deleteNode->next->prev = prevNode;
        }
        prevNode->next = deleteNode->next;
        free(deleteNode);
    }
    return 0;
}

int DoubleLinkedListDeleteAll(struct DoubleLinkedListNode **head)
{
    struct DoubleLinkedListNode *deleteNode = NULL;                                                 //삭제하려는 노드
    struct DoubleLinkedListNode *nextNode = NULL;                                                   //삭제하려는 노드의 다음 노드

    deleteNode = *head;
    while(deleteNode)
    {
        nextNode = deleteNode->next;
        free(deleteNode);
        deleteNode = nextNode;
    }
    *head = NULL;
    return 0;
}

int DoubleLinkedListPrint(struct DoubleLinkedListPrint *head)
{
    struct DoubleLinkedListNode *current = NULL;
    if(head == NULL)
    {
        printf("List is Empty\n");
        return 1;
    }

    current = head;
    while(current!=NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    return 0;
}