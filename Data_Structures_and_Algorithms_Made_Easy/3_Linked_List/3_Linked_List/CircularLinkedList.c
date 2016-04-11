#include <stdio.h>
#include <stdlib.h>

struct CircularLinkedListNode
{
    int data;
    struct CircularLinkedListNode *next;
};

int CircularLinkedListLength(struct CircularLinkedListNode *head)
{
    struct CircularLinkedListNode *now = head;
    int count = 0;
    do
    {
        count++;
        now = now->next;
    } while(now != head);
    return count;
}

int CircularLinkedListInsert(struct CircularLinkedListNode **head, int data, int position)
{
    int count = 1;
    struct CircularLinkedListNode *newNode = NULL;
    struct CircularLinkedListNode *prevNode = NULL;
    struct CircularLinkedListNode *nextNode = NULL;

    newNode = (struct CircularLinkedListNode *)malloc(sizeof(struct CircularLinkedListNode));
    if(!newNode)
    {
        printf("Memory Error\n");
        return 1;
    }
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
        return 0;
    }

    if(position == 1)
    {
        prevNode = *head;
        while(prevNode->next != *head)
        {
            prevNode = prevNode->next;
        }
        prevNode->next = newNode;
        newNode->next = *head;
        *head = newNode;
        return 0;
    }

    nextNode = *head;
    do
    {
        count++;
        prevNode = nextNode;
        nextNode = nextNode->next;
    } while((nextNode != *head) && (count < position));

    if(nextNode == *head)
    {
        if(count == position)
        {
            newNode->next = *head;
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
    }

    return 0;
}

int CircularLinkedListDelete(struct CircularLinkedListNode **head, int position)
{
    int count = 1;
    struct CircularLinkedListNode *deleteNode = NULL;
    struct CircularLinkedListNode *prevNode = NULL;

    if(*head == NULL)                                                                               //빈 리스트인 경우
    {
        printf("List is Empty\n");
        return 1;
    }

    deleteNode = *head;
    if(position == 1)
    {
        if((*head)->next == *head)
        {
            free(*head);
            *head = NULL;
            return 0;
        }
        
        prevNode = *head;
        while(prevNode->next != *head)
        {
            prevNode = prevNode->next;
        }
        prevNode->next = deleteNode->next;
        *head = (*head)->next;
        free(deleteNode);
        return 0;
    }

    do
    {
        count++;
        prevNode = deleteNode;
        deleteNode = deleteNode->next;
    } while((deleteNode != *head) && (count < position));
    if(deleteNode == *head)
    {
        printf("List Size Exceed\n");
        return 1;
    }
    else
    {
        prevNode->next = deleteNode->next;
        free(deleteNode);
    }
    return 0;
}

int CircularLinkedListPrint(struct CircularLinkedListNode *head)
{
    struct CircularLinkedListNode *current = NULL;
    if(head == NULL)
    {
        printf("List is Empty\n");
        return 0;
    }
    current = head;
    do
    {
        printf("%d\n", current->data);
        current = current->next;
    } while(current != head);
    return 0;
}