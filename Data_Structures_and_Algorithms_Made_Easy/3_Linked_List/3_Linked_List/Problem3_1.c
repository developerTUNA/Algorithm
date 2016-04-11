#include "Problem.h"
#include "LinkedList.h"

/*
 *연결리스트를 사용해서 스택을 구현하라
 */
int Problem3_1(void)
{
    struct SingleLinkedListNode *head;
    head = NULL;
    int data = 0;
    StackPush(&head, 1);
    StackPush(&head, 2);
    StackPush(&head, 3);

    StackPop(&head, &data);
    printf("%d\n", data);
    StackPop(&head, &data);
    printf("%d\n", data);
    StackDelete(&head);
    return 0;
}

int StackPush(struct SingleLinkedListNode **head, int data)
{
    SingleLinkedListInsert(head, data, 1);
}
int StackPop(struct SingleLinkedListNode **head, int *retData)
{
    SingleLinkedListGet(*head, 1, retData);
    SingleLinkedListDelete(head, 1);
}
int StackDelete(struct SingleLinkedListNode **head)
{
    SingleLinkedListDeleteAll(head);
}