#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct State14226_
{
	int nCount;
	int nPush;
	int nClipboard;
}State14226;

typedef struct Node14226_
{
	State14226 data;
	struct Node14226_ *next;
}Node14226;

typedef struct Queue14226_
{
	int nSize;
	Node14226 *head;
	Node14226 *tail;
}Queue14226;

int QueuePush14226(Queue14226 *queue, State14226 data)
{
	Node14226 *newNode = NULL;
	newNode = (Node14226*)malloc(sizeof(Node14226));
	memset(newNode, 0, sizeof(Node14226));

	newNode->data = data;
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

int QueuePop14226(Queue14226 *queue, State14226 *data)
{
	Node14226 *delNode = NULL;
	if (queue->nSize == 0)
	{
		return -1;
	}
	
	delNode = queue->head;
	if (queue->nSize == 1)
	{
		queue->tail = NULL;
	}
	queue->head = queue->head->next;
	*data = delNode->data;
	free(delNode);
	queue->nSize--;

	return 0;
}

int QueueisEmpty(Queue14226 *queue)
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
int Problem14226(void)
{
	int nEnd = 0;
	int a_nResult[1001] = { 0, };
	Queue14226 *Queue = NULL;
	State14226 StateGet;
	State14226 StateNext;

	scanf("%d", &nEnd);
	
	StateGet.nCount = 1;
	StateGet.nPush = 0;
	StateGet.nClipboard = 0;
	

	Queue = (Queue14226*)malloc(sizeof(Queue14226));
	memset(Queue, 0, sizeof(Queue14226));

	QueuePush14226(Queue, StateGet);
	int nCounter = 0;
	while (QueueisEmpty(Queue) == 0)
	{
		QueuePop14226(Queue, &StateGet);

		if (StateGet.nCount == nEnd)
		{
				break;
		}
		if (StateGet.nPush < a_nResult[StateGet.nCount] || a_nResult[StateGet.nCount] == 0)
		{
			a_nResult[StateGet.nCount] = StateGet.nPush;
		}
		if (0 < StateGet.nCount - 1)
		{
			StateNext.nCount = StateGet.nCount - 1;
			StateNext.nPush = StateGet.nPush + 1;
			StateNext.nClipboard = StateGet.nClipboard;
			QueuePush14226(Queue, StateNext);
			if (StateNext.nPush < a_nResult[StateNext.nCount] || a_nResult[StateNext.nCount] == 0)
			{
				a_nResult[StateNext.nCount] = StateNext.nPush;
			}
		}

		if (StateGet.nCount + StateGet.nClipboard <= 1000)
		{
			StateNext.nCount = StateGet.nCount + StateGet.nClipboard;
			StateNext.nPush = StateGet.nPush + 1;
			StateNext.nClipboard = StateGet.nClipboard;
			QueuePush14226(Queue, StateNext);
			if (StateNext.nPush < a_nResult[StateNext.nCount] || a_nResult[StateNext.nCount] == 0)
			{
				a_nResult[StateNext.nCount] = StateNext.nPush;
				
			}
		}

		if (StateGet.nCount <= 1000)
		{
			StateNext.nCount = StateGet.nCount;
			StateNext.nPush = StateGet.nPush + 1;
			StateNext.nClipboard = StateGet.nCount;
			QueuePush14226(Queue, StateNext);
			if (StateNext.nPush < a_nResult[StateNext.nCount] || a_nResult[StateNext.nCount] == 0)
			{
				a_nResult[StateNext.nCount] = StateNext.nPush;
			}
		}
	}
	while (QueueisEmpty(Queue) == 0)
	{
		State14226 temp;
		QueuePop14226(Queue, &temp);
	}
	free(Queue);
	printf("%d\n", a_nResult[nEnd]);
	//for(int i = 0; i<=1000;i++)
		//printf("%d %d\n",i, a_nResult[i]);
	return 0;
}