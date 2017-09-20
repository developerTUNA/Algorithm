#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node05014_
{
	int nData;
	struct Node05014_ *next;
}Node05014;

typedef struct Queue05014_
{
	int nSize;
	Node05014 *head;
	Node05014 *tail;
}Queue05014;

int QueuePush05014(Queue05014 *queue, int nData)
{
	Node05014 *newNode = NULL;
	newNode = (Node05014*)malloc(sizeof(Node05014));
	newNode->nData = nData;
	newNode->next = NULL;

	if (queue->nSize == 0)
	{
		queue->head = newNode;
		queue->tail = newNode;
	}
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}

	queue->nSize++;
	return 0;
}

int QueuePop05014(Queue05014 *queue, int *p_nData)
{
	Node05014 *delNode = NULL;

	if (queue->nSize == 0)
	{
		return -1;
	}

	if (queue->nSize == 1)
	{
		queue->tail = NULL;
	}
	delNode = queue->head;
	queue->head = queue->head->next;
	*p_nData = delNode->nData;
	free(delNode);
	queue->nSize--;

	return 0;
}

int QueueisEmpty05014(Queue05014 *queue)
{
	if (queue->nSize == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Problem05014(void)
{
	int nFloor = 0;
	int nBegin = 0;
	int nEnd = 0;
	int nUp = 0;
	int nDown = 0;
	int *p_nFloor = NULL;
	Queue05014 *queue = NULL;

	scanf("%d %d %d %d %d", &nFloor, &nBegin, &nEnd, &nUp, &nDown);
	p_nFloor = (int*)malloc(sizeof(int)*(nFloor + 1));
	memset(p_nFloor, -1, sizeof(int)*(nFloor + 1));
	queue = (Queue05014*)malloc(sizeof(Queue05014));
	memset(queue, 0, sizeof(Queue05014));
	p_nFloor[nBegin] = 0;
	QueuePush05014(queue, nBegin);

	while (QueueisEmpty05014(queue) == 0)
	{
		int nPush = 0;
		int nPop = 0;

		QueuePop05014(queue, &nPop);

		if (nPop == nEnd)
		{
			while (QueueisEmpty05014(queue) == 0)
			{
				QueuePop05014(queue, &nPop);
			}
			break;
		}

		if (nPop + nUp <= nFloor)
		{
			nPush = nPop + nUp;
			if(p_nFloor[nPush] == -1)
			{
				QueuePush05014(queue, nPush);
				p_nFloor[nPush] = p_nFloor[nPop] + 1;
			}
		}

		if (1 <= nPop - nDown)
		{
			nPush = nPop - nDown;
			if (p_nFloor[nPush] == -1)
			{
				QueuePush05014(queue, nPush);
				p_nFloor[nPush] = p_nFloor[nPop] + 1;
			}
		}
	}

	if (p_nFloor[nEnd] == -1)
	{
		printf("use the stairs\n");
	}
	else
	{
		printf("%d\n", p_nFloor[nEnd]);
	}

	free(p_nFloor);
	free(queue);
	return 0;
}