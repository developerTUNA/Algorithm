#include "LinkedList.h"

/*
 * SingleLinkedListLength : 링크드 리스트의 길이 반환
 * 시간복잡도 : O(n) 길이가 n인 리스트를 스캔
 * 공간복잡도 : O(1) 동적 선언 없음, 상수 선언만 함
 */
int SingleLinkedListLength(struct SingleLinkedListNode *head)
{
    struct SingleLinkedListNode *currentNode = NULL;
    currentNode = head;
    int count = 0;
    while(currentNode != NULL)                                                                          //NULL이 나올때까지
    {
        count++;                                                                                    //count 값 증가
        currentNode = currentNode->next;                                                                    //다음 노드로 이동
    }
    return count;
};

/*
 * SingleLinkedListInsert : 링크드 리스트에 노드 삽입
 * 시간복잡도 : O(n) 길이가 n인 리스트, 가장 뒤에 삽입하는 경우
 * 공간복잡도 : O(1) struct SingleLinkedListNode 1개 선언
 */
int SingleLinkedListInsert(struct SingleLinkedListNode **head, int data, int position)
{
    int count = 1;
    struct SingleLinkedListNode *newNode = NULL;                                                    //삽입하려는 노드
    struct SingleLinkedListNode *prevNode = NULL;                                                   //탐색하는 있는 노드의 이전 노드
    struct SingleLinkedListNode *nextNode = NULL;                                                    //탐색하고 있는 노드

    newNode = (struct SingleLinkedListNode *)malloc(sizeof(struct SingleLinkedListNode));           //공간 확보
    if(!newNode)                                                                                    //공간 확보 검사
    {
        printf("Memory Error\n");
        return 1;
    }
    newNode->data = data;                                                                           //이것저것 초기화
    newNode->next = NULL;


    if(*head == NULL)
    {
        *head = newNode;
        return 0;
    }
    if(position == 1)                                                                               //맨 앞 삽입
    {
        newNode->next = *head;
        *head = newNode;
        return 0;
    }

    nextNode = *head;
    while((nextNode != NULL) && (count < position))                                              //삽입하려는 위치까지 이동
    {
        count++;
        prevNode = nextNode;
        nextNode = nextNode->next;
    }
    if(nextNode == NULL)                                                                         //맨 뒤까지 탐색한경우 (맨뒤 삽입)
    {
        if(count == position)                                                                   //지정한 위치가 맞는지 확인
        {
            newNode->next = NULL;
            prevNode->next = newNode;
        }
        else                                                                                    //리스트는 2개인데, 4번째 삽입시 에러
        {
            printf("List Size Exceed\n");
            return 1;
        }
    }
    else                                                                                        //중간에 삽입
    {
        prevNode->next = newNode;
        newNode->next = nextNode;
    }
    return 0;
}

/*
 * DeleteNodeLinkedList : 링크드 리스트에 노드 삭제
 * 시간복잡도 : O(n) 길이가 n인 리스트, 가장 뒤를 삭제 하는 경우
 * 공간복잡도 : O(1) struct SingleLinkedListNode 1개 선언
 */
int SingleLinkedListDelete(struct SingleLinkedListNode **head, int position)
{
    int count = 1;
    struct SingleLinkedListNode *deleteNode = NULL;                                                    //탐색하고 있는 노드
    struct SingleLinkedListNode *prevNode = NULL;                                                   //탐색하고 있는 노드의 이전 노드

    if(*head == NULL)                                                                               //빈 리스트인 경우
    {
        printf("List is Empty\n");
        return 1;
    }

    deleteNode = *head;
    if(position == 1)                                                                               //맨 앞에서 삭제
    {
        if((*head)->next == NULL)
        {
            free(*head);
            *head = NULL;
            return 0;
        }
        *head = (*head)->next;
        free(deleteNode);
        return 0;
    }
    while((deleteNode != NULL) && (count < position))                                              //삭제하려는 위치까지 이동
    {
        count++;
        prevNode = deleteNode;
        deleteNode = deleteNode->next;
    }
    if(deleteNode == NULL)                                                                         //삭제하려는 위치가 리스트 크기보다 큼
    {
        printf("List Size Exceed\n");
        return 1;
    }
    else                                                                                        //그외의 경우 삭제함
    {
        prevNode->next = deleteNode->next;
        free(deleteNode);
    }
    return 0;
}

/*
 * SingleLinkedListDeleteAll : 링크드 리스트를 삭제
 * 시간복잡도 : O(n) 길이가 n인 리스트를 삭제 함
 * 공간복잡도 : O(1) 동적 선언 없음, 상수 선언만 함
 */
int SingleLinkedListDeleteAll(struct SingleLinkedListNode **head)
{
    struct SingleLinkedListNode *deleteNode = NULL;                                                 //삭제하려는 노드
    struct SingleLinkedListNode *nextNode = NULL;                                                   //삭제하려는 노드의 다음 노드

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

int SingleLinkedListPrint(struct SingleLinkedListNode *head)
{
    struct SingleLinkedListNode *currentNode = NULL;
    if(head == NULL)
    {
        printf("List is Empty\n");
        return 1;
    }
    currentNode = head;
    while(currentNode != NULL)
    {
        printf("%d\n", currentNode->data);
        currentNode = currentNode->next;
    }
    return 0;
}

int SingleLinkedListGet(struct SingleLinkedListNode *head, int position, int *retData)
{
    int count = 1;
    struct SingleLinkedListNode *currentNode = NULL;
    currentNode = head;

    while((currentNode != NULL) && (count < position))
    {
        count++;
        currentNode = currentNode->next;
    }
    if(currentNode == NULL || count != position)
    {
        printf("List Size Exceed\n");
        return 1;
    }
    *retData = currentNode->data;
    return 0;
}