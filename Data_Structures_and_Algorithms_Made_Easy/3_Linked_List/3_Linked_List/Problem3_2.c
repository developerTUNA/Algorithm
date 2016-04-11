#include "Problem.h"
#include "LinkedList.h"

/*
 *연결리스트의 끝에서 n번째 노드를 찾아보자
 *brute force 기법 사용
 */

int Problem3_2(void)
{
    struct SingleLinkedListNode *head = NULL;
    int data = 0;
    int position = 5;
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

    GetBackNDataBruteForce(&head, position, &data);
    printf("%d\n", data);
    SingleLinkedListDeleteAll(&head);
    return 0;
}
int GetBackNDataBruteForce(struct SingleLinkedListNode **head, int position, int *resData)
{
    struct SingleLinkedListNode **currentNode;
    currentNode = head;
    while(SingleLinkedListLength(*currentNode) != position)
    {
        *currentNode = (*currentNode)->next;
    }
    (*resData) = (*currentNode)->data;
    return 0;
}