#include <stdio.h>
#include <stdlib.h>


struct SingleLinkedListNode
{
    int data;
    struct SingleLinkedListNode *next;
};

int SingleLinkedListLength(struct SingleLinkedListNode*);
int SingleLinkedListInsert(struct SingleLinkedListNode **, int , int );
int SingleLinkedListDelete(struct SingleLinkedListNode **, int);
int SingleLinkedListDeleteAll(struct SingleLinkedListNode **);
int SingleLinkedListPrint(struct SingleLinkedListNode *);
int SingleLinkedListGet(struct SingleLinkedListNode *, int, int *);