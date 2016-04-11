#include "Problem.h"
#include "LinkedList.h"

/*
*연결리스트의 끝에서 n번째 노드를 찾아보자
*Hash Table 기법 사용 -> 배열 사용함
*/

struct TableNode
{
    int position;
    struct SingleLinkedListNode *addr;
};

int Problem3_3(void)
{
    struct SingleLinkedListNode *head = NULL;
    struct TableNode **table = NULL;
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
    
    MakeDataTable(head, &table);
    GetBackNDataTableGet(head, table, position, &data);
    printf("%d\n", data);
    SingleLinkedListDeleteAll(&head);
    return 0;
}


int MakeDataTable(struct SingleLinkedListNode *head, struct TableNode ***table)
{
    struct SingleLinkedListNode *currentNode = NULL;
    int listSize = 0;

    currentNode = head;
    listSize = SingleLinkedListLength(currentNode);
    (*table) = (struct TableNode**)malloc(sizeof(struct TableNode*)*listSize);

    for(int i = 0; i < listSize; i++)
    {
        (*table)[i] = (struct TableNode*)malloc(sizeof(struct TableNode));
        ((*table)[i])->addr = currentNode;
        ((*table)[i])->position = i;
        currentNode = currentNode->next;
    }
    return 0;
}

int GetBackNDataTableGet(struct SingleLinkedListNode *head, struct TableNode **table, int position, int *data)
{
    int listSize = 0;
    listSize = SingleLinkedListLength(head);
    struct SingleLinkedListNode *currentNode = NULL;
    currentNode = (table[listSize - position])->addr;
    *data = currentNode->data;
    return 0;
}