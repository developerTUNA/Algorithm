#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node01697_
{
	int nData;
	struct Node01697_ *next;
}Node01697;
typedef struct Queue01697_
{
	int nSize;
	Node01697 *first;
	Node01697 *last;
}Queue01697;
int QueuePush01697(Queue01697 *queue,int nData)
{
	Node01697 *newNode = NULL;
	
	newNode = (Node01697*)malloc(sizeof(Node01697));
	memset(newNode, 0, sizeof(Node01697));
	newNode->nData = nData;
	newNode->next = NULL;
	
	if (queue->nSize == 0)
	{
		queue->first = newNode;
		queue->last = newNode;
	}
	else
	{
		queue->last->next = newNode;
		queue->last = newNode;
	}
	
	queue->nSize++;
	return 0;
}

int QueuePop01697(Queue01697 *queue, int *nData)
{
	Node01697 *delNode = NULL;
	
	if (queue->nSize == 0)
	{
		return -1;
	}
	else if (queue->nSize == 1)
	{
		queue->last = NULL;
	}
	delNode = queue->first;
	queue->first = queue->first->next;
	*nData = delNode->nData;
	free(delNode);
	
	queue->nSize--;
	return 0;
}
int QueueIsEmpty01697(Queue01697 *queue)
{
	if (0 < queue->nSize)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int Problem01697(void)
{
	int nBegin = 0;
	int nEnd = 0;
	int nMap[100001];
	Queue01697 *queue = NULL;
	scanf("%d %d", &nBegin, &nEnd);
	memset(nMap, -1, sizeof(nMap));

	queue = (Queue01697 *)malloc(sizeof(Queue01697));
	memset(queue, 0, sizeof(Queue01697));

	nMap[nBegin] = 0;
	QueuePush01697(queue, nBegin);

	while (QueueIsEmpty01697(queue)==0)
	{
		int nTemp = 0;
		QueuePop01697(queue, &nTemp);
		if(0<=nTemp+1 && nTemp+1<=100000)
		{
			if(nMap[nTemp + 1] == -1)
			{
				nMap[nTemp + 1] = nMap[nTemp] + 1;
				QueuePush01697(queue, nTemp + 1);
			}
			if (nTemp + 1 == nEnd)
			{
				break;
			}
		}

		if (0 <= nTemp - 1 && nTemp - 1 <= 100000)
		{
			if (nMap[nTemp - 1] == -1)
			{
				nMap[nTemp - 1] = nMap[nTemp] + 1;
				QueuePush01697(queue, nTemp - 1);
			}
			if (nTemp - 1 == nEnd)
			{
				break;
			}
		}

		if (0 <= 2*nTemp && 2 * nTemp <= 100000)
		{
			if (nMap[2 * nTemp] == -1)
			{
				nMap[2 * nTemp] = nMap[nTemp] + 1;
				QueuePush01697(queue, 2*nTemp);
			}
			if (2*nTemp == nEnd)
			{
				break;
			}
		}
	}
	while (QueueIsEmpty01697(queue) == 0)
	{
		int nTemp = 0;
		QueuePop01697(queue, &nTemp);
	}

	printf("%d\n", nMap[nEnd]);

	return 0;
}