#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct State14226_
{
	int nCount;
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

int QueuePop14226(Queue14226 *queue, State14226 *p_data)
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
	*p_data = delNode->data;
	free(delNode);
	queue->nSize--;

	return 0;
}

int QueueisEmpty14226(Queue14226 *queue)
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
	int nResult = 0;
	int **pp_nMap = NULL;
	State14226 State;
	Queue14226 *queue = NULL;
	
	scanf("%d", &nEnd);
	pp_nMap = (int**)malloc(sizeof(int*) * 1001);
	memset(pp_nMap, 0, sizeof(int*) * 1001);
	for (int i = 0; i < 1001; i++)
	{
		pp_nMap[i] = (int*)malloc(sizeof(int) * 1001);
		memset(pp_nMap[i], -1, sizeof(int) * 1001);
	}
	queue = (Queue14226*)malloc(sizeof(Queue14226));
	memset(queue, 0, sizeof(Queue14226));

	pp_nMap[1][0] = 0;
	State.nClipboard = 0;
	State.nCount = 1;
	QueuePush14226(queue, State);
	while (QueueisEmpty14226(queue) == 0)
	{
		State14226 StateGet = { 0, };
		State14226 StatePush = { 0, };
		QueuePop14226(queue, &StateGet);

		if (pp_nMap[StateGet.nCount][StateGet.nCount] == -1)
		{
			StatePush.nCount = StateGet.nCount;
			StatePush.nClipboard = StateGet.nCount;
			QueuePush14226(queue, StatePush);
			pp_nMap[StatePush.nCount][StatePush.nClipboard] = pp_nMap[StateGet.nCount][StateGet.nClipboard] + 1;
		}

		if (StateGet.nCount + StateGet.nClipboard <= nEnd &&
			pp_nMap[StateGet.nCount + StateGet.nClipboard][StateGet.nClipboard] == -1)
		{
			StatePush.nCount = StateGet.nCount + StateGet.nClipboard;
			StatePush.nClipboard = StateGet.nClipboard;
			QueuePush14226(queue, StatePush);
			pp_nMap[StatePush.nCount][StatePush.nClipboard] = pp_nMap[StateGet.nCount][StateGet.nClipboard] + 1;
		}
		if (1 <= StateGet.nCount &&
			pp_nMap[StateGet.nCount - 1][StateGet.nClipboard] == -1)
		{
			StatePush.nCount = StateGet.nCount - 1;
			StatePush.nClipboard = StateGet.nClipboard;
			QueuePush14226(queue, StatePush);
			pp_nMap[StatePush.nCount][StatePush.nClipboard] = pp_nMap[StateGet.nCount][StateGet.nClipboard] + 1;
		}
	}

	nResult = 1001;
	for (int i = 0; i < 1001; i++)
	{
		if (pp_nMap[nEnd][i] < nResult &&
			pp_nMap[nEnd][i] != -1)
		{
			nResult = pp_nMap[nEnd][i];
		}
	}
	for (int i = 0; i < 1001; i++)
	{
		free(pp_nMap[i]);
	}
	free(pp_nMap);
	free(queue);
	printf("%d\n", nResult);
	return 0;
}