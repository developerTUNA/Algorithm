#include "LinkedList.h"

/*
 * SingleLinkedListLength : ��ũ�� ����Ʈ�� ���� ��ȯ
 * �ð����⵵ : O(n) ���̰� n�� ����Ʈ�� ��ĵ
 * �������⵵ : O(1) ���� ���� ����, ��� ���� ��
 */
int SingleLinkedListLength(struct SingleLinkedListNode *head)
{
    struct SingleLinkedListNode *currentNode = NULL;
    currentNode = head;
    int count = 0;
    while(currentNode != NULL)                                                                          //NULL�� ���ö�����
    {
        count++;                                                                                    //count �� ����
        currentNode = currentNode->next;                                                                    //���� ���� �̵�
    }
    return count;
};

/*
 * SingleLinkedListInsert : ��ũ�� ����Ʈ�� ��� ����
 * �ð����⵵ : O(n) ���̰� n�� ����Ʈ, ���� �ڿ� �����ϴ� ���
 * �������⵵ : O(1) struct SingleLinkedListNode 1�� ����
 */
int SingleLinkedListInsert(struct SingleLinkedListNode **head, int data, int position)
{
    int count = 1;
    struct SingleLinkedListNode *newNode = NULL;                                                    //�����Ϸ��� ���
    struct SingleLinkedListNode *prevNode = NULL;                                                   //Ž���ϴ� �ִ� ����� ���� ���
    struct SingleLinkedListNode *nextNode = NULL;                                                    //Ž���ϰ� �ִ� ���

    newNode = (struct SingleLinkedListNode *)malloc(sizeof(struct SingleLinkedListNode));           //���� Ȯ��
    if(!newNode)                                                                                    //���� Ȯ�� �˻�
    {
        printf("Memory Error\n");
        return 1;
    }
    newNode->data = data;                                                                           //�̰����� �ʱ�ȭ
    newNode->next = NULL;


    if(*head == NULL)
    {
        *head = newNode;
        return 0;
    }
    if(position == 1)                                                                               //�� �� ����
    {
        newNode->next = *head;
        *head = newNode;
        return 0;
    }

    nextNode = *head;
    while((nextNode != NULL) && (count < position))                                              //�����Ϸ��� ��ġ���� �̵�
    {
        count++;
        prevNode = nextNode;
        nextNode = nextNode->next;
    }
    if(nextNode == NULL)                                                                         //�� �ڱ��� Ž���Ѱ�� (�ǵ� ����)
    {
        if(count == position)                                                                   //������ ��ġ�� �´��� Ȯ��
        {
            newNode->next = NULL;
            prevNode->next = newNode;
        }
        else                                                                                    //����Ʈ�� 2���ε�, 4��° ���Խ� ����
        {
            printf("List Size Exceed\n");
            return 1;
        }
    }
    else                                                                                        //�߰��� ����
    {
        prevNode->next = newNode;
        newNode->next = nextNode;
    }
    return 0;
}

/*
 * DeleteNodeLinkedList : ��ũ�� ����Ʈ�� ��� ����
 * �ð����⵵ : O(n) ���̰� n�� ����Ʈ, ���� �ڸ� ���� �ϴ� ���
 * �������⵵ : O(1) struct SingleLinkedListNode 1�� ����
 */
int SingleLinkedListDelete(struct SingleLinkedListNode **head, int position)
{
    int count = 1;
    struct SingleLinkedListNode *deleteNode = NULL;                                                    //Ž���ϰ� �ִ� ���
    struct SingleLinkedListNode *prevNode = NULL;                                                   //Ž���ϰ� �ִ� ����� ���� ���

    if(*head == NULL)                                                                               //�� ����Ʈ�� ���
    {
        printf("List is Empty\n");
        return 1;
    }

    deleteNode = *head;
    if(position == 1)                                                                               //�� �տ��� ����
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
    while((deleteNode != NULL) && (count < position))                                              //�����Ϸ��� ��ġ���� �̵�
    {
        count++;
        prevNode = deleteNode;
        deleteNode = deleteNode->next;
    }
    if(deleteNode == NULL)                                                                         //�����Ϸ��� ��ġ�� ����Ʈ ũ�⺸�� ŭ
    {
        printf("List Size Exceed\n");
        return 1;
    }
    else                                                                                        //�׿��� ��� ������
    {
        prevNode->next = deleteNode->next;
        free(deleteNode);
    }
    return 0;
}

/*
 * SingleLinkedListDeleteAll : ��ũ�� ����Ʈ�� ����
 * �ð����⵵ : O(n) ���̰� n�� ����Ʈ�� ���� ��
 * �������⵵ : O(1) ���� ���� ����, ��� ���� ��
 */
int SingleLinkedListDeleteAll(struct SingleLinkedListNode **head)
{
    struct SingleLinkedListNode *deleteNode = NULL;                                                 //�����Ϸ��� ���
    struct SingleLinkedListNode *nextNode = NULL;                                                   //�����Ϸ��� ����� ���� ���

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