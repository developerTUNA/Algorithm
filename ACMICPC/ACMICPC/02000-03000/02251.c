#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct State02251_
{
	int nA;
	int nB;
	int nC;
}State02251;

typedef struct Node02251_
{
	State02251 data;
	struct Node02251_ *next;
}Node02251;

typedef struct Queue02251_
{
	int nSize;
	Node02251 *head;
	Node02251 *tail;
}Queue02251;

int QueuePush02251(Queue02251 *queue, State02251 data)
{
	Node02251 *newNode = NULL;
	newNode = (Node02251*)malloc(sizeof(Node02251));
	memset(newNode, 0, sizeof(Node02251));

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

int QueuePop02251(Queue02251 *queue, State02251 *p_data)
{
	Node02251 *delNode = NULL;
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

int QueueisEmpty02251(Queue02251 *queue)
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

int Problem02251(void)
{
	int nA = 0;
	int nB = 0;
	int nC = 0;
	int nTotal = 0;
	int aa_nBottle[201][201] = { 0, };
	int a_nPrint[201] = { 0, };
	Queue02251 *queue = NULL;
	State02251 statePush;
	State02251 statePop;
	
	scanf("%d %d %d", &nA, &nB, &nC);
	nTotal = nC;
	
	queue = (Queue02251 *)malloc(sizeof(Queue02251));
	memset(queue, 0, sizeof(Queue02251));

	memset(aa_nBottle, -1, sizeof(aa_nBottle));

	statePush.nA = 0;
	statePush.nB = 0;
	statePush.nC = nC;
	QueuePush02251(queue, statePush);
	aa_nBottle[0][0] = nC;

	while (QueueisEmpty02251(queue) == 0)
	{
		QueuePop02251(queue, &statePop);
		if (statePop.nA != 0)
		{
			statePush = statePop;
			statePush.nB = statePop.nB + statePop.nA;
			if (nB < statePush.nB)
			{
				statePush.nA = statePush.nB - nB;
				statePush.nB = nB;
			}
			else
			{
				statePush.nA = 0;
			}
			if (aa_nBottle[statePush.nA][statePush.nB] == -1)
			{
				aa_nBottle[statePush.nA][statePush.nB] = statePush.nC;
				QueuePush02251(queue, statePush);
			}

			statePush = statePop;
			statePush.nC = statePop.nC + statePop.nA;
			if (nC < statePush.nC)
			{
				statePush.nA = statePush.nC - nC;
				statePush.nC = nC;
			}
			else
			{
				statePush.nA = 0;
			}
			if (aa_nBottle[statePush.nA][statePush.nB] == -1)
			{
				aa_nBottle[statePush.nA][statePush.nB] = statePush.nC;
				QueuePush02251(queue, statePush);
			}
		}

		if (statePop.nB != 0)
		{
			statePush = statePop;
			statePush.nA = statePop.nA + statePop.nB;
			if (nA < statePush.nA)
			{
				statePush.nB = statePush.nA - nA;
				statePush.nA = nA;
			}
			else
			{
				statePush.nB = 0;
			}
			if (aa_nBottle[statePush.nA][statePush.nB] == -1)
			{
				aa_nBottle[statePush.nA][statePush.nB] = statePush.nC;
				QueuePush02251(queue, statePush);
			}

			statePush = statePop;
			statePush.nC = statePop.nC + statePop.nB;
			if (nC < statePush.nC)
			{
				statePush.nB = statePush.nC - nC;
				statePush.nC = nC;
			}
			else
			{
				statePush.nB = 0;
			}
			if (aa_nBottle[statePush.nA][statePush.nB] == -1)
			{
				aa_nBottle[statePush.nA][statePush.nB] = statePush.nC;
				QueuePush02251(queue, statePush);
			}
		}

		if (statePop.nC != 0)
		{
			statePush = statePop;
			statePush.nA = statePop.nA + statePop.nC;
			if (nA < statePush.nA)
			{
				statePush.nC = statePush.nA - nA;
				statePush.nA = nA;
			}
			else
			{
				statePush.nC = 0;
			}
			if (aa_nBottle[statePush.nA][statePush.nB] == -1)
			{
				aa_nBottle[statePush.nA][statePush.nB] = statePush.nC;
				QueuePush02251(queue, statePush);
			}

			statePush = statePop;
			statePush.nB = statePop.nB + statePop.nC;
			if (nB < statePush.nB)
			{
				statePush.nC = statePush.nB - nB;
				statePush.nB = nB;
			}
			else
			{
				statePush.nC = 0;
			}
			if (aa_nBottle[statePush.nA][statePush.nB] == -1)
			{
				aa_nBottle[statePush.nA][statePush.nB] = statePush.nC;
				QueuePush02251(queue, statePush);
			}
		}
	}

	for (int i = 0; i <= nB; i++)
	{
		if (aa_nBottle[0][i] != -1)
		{
			a_nPrint[aa_nBottle[0][i]] = 1;
		}
	}
	for (int i = 0; i < 201; i++)
	{
		if (a_nPrint[i] == 1)
		{
			printf("%d ", i);
		}
	}
	free(queue);
	return 0;
}