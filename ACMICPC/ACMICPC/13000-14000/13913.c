#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node13913_
{
	int nData;
	struct Node13913_ *next;
}Node13913;
typedef struct Queue13913_
{
	int nSize;
	Node13913 *first;
	Node13913 *last;
}Queue13913;
int QueuePush13913(Queue13913 *queue, int nData)
{
	Node13913 *newNode = NULL;

	newNode = (Node13913*)malloc(sizeof(Node13913));
	memset(newNode, 0, sizeof(Node13913));
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

int QueuePop13913(Queue13913 *queue, int *nData)
{
	Node13913 *delNode = NULL;

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
int QueueIsEmpty13913(Queue13913 *queue)
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
int PrintRoute13913(int *nFrom, int nNow, int nBegin)
{
	if (nNow != nBegin)
	{
		PrintRoute13913(nFrom, nFrom[nNow], nBegin);
	}
	printf("%d ", nNow);
	return 0;
}
int Problem13913(void)
{
	int nBegin = 0;
	int nEnd = 0;
	int nMap[100001];
	int nFrom[100001];
	Queue13913 *queue = NULL;
	scanf("%d %d", &nBegin, &nEnd);
	memset(nMap, -1, sizeof(nMap));
	memset(nFrom, -1, sizeof(nFrom));

	queue = (Queue13913 *)malloc(sizeof(Queue13913));
	memset(queue, 0, sizeof(Queue13913));

	nMap[nBegin] = 0;
	nFrom[nBegin] = -1;
	QueuePush13913(queue, nBegin);

	while (QueueIsEmpty13913(queue) == 0)
	{
		int nTemp = 0;
		QueuePop13913(queue, &nTemp);
		if (0 <= nTemp + 1 && nTemp + 1 <= 100000)
		{
			if (nMap[nTemp + 1] == -1)
			{
				nMap[nTemp + 1] = nMap[nTemp] + 1;
				nFrom[nTemp + 1] = nTemp;
				QueuePush13913(queue, nTemp + 1);
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
				nFrom[nTemp - 1] = nTemp;
				QueuePush13913(queue, nTemp - 1);
			}
			if (nTemp - 1 == nEnd)
			{
				break;
			}
		}
		if (0 <= 2 * nTemp && 2 * nTemp <= 100000)
		{
			if (nMap[2 * nTemp] == -1)
			{
				nMap[2 * nTemp] = nMap[nTemp] + 1;
				nFrom[2 * nTemp] = nTemp;
				QueuePush13913(queue, 2 * nTemp);
			}
			if (2 * nTemp == nEnd)
			{
				break;
			}
		}
	}
	while (QueueIsEmpty13913(queue) == 0)
	{
		int nTemp = 0;
		QueuePop13913(queue, &nTemp);
	}

	printf("%d\n", nMap[nEnd]);
	PrintRoute13913(nFrom, nEnd, nBegin);
	printf("\n");
	return 0;
}
