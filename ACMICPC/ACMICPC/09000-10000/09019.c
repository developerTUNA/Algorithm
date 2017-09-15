#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node09019_
{
	int nData;
	struct Node09019_ *next;
}Node09019;

typedef struct Queue09019_
{
	Node09019 *head;
	Node09019 *tail;
	int nSize;
}Queue09019;

int QueuePush09019(Queue09019 *queue, int nData)
{
	Node09019 *newNode = NULL;
	newNode = (Node09019*)malloc(sizeof(Node09019));
	memset(newNode, 0, sizeof(Node09019));
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

int QueuePop09019(Queue09019 *queue, int *p_nData)
{
	Node09019 *delNode = NULL;

	if (queue->nSize == 0)
	{
		return -1;
	}

	delNode = queue->head;
	*p_nData = delNode->nData;

	if (queue->nSize == 1)
	{
		queue->head = NULL;
		queue->tail = NULL;
	}
	else
	{
		queue->head = queue->head->next;
	}
	free(delNode);
	queue->nSize--;

	return 0;
}

int InttoDigit09019(int nNum, int *p_nDigit, int nDigit)
{
	for (int i = nDigit-1; 0 <=i ;i--)
	{
		p_nDigit[i] = nNum % 10;
		nNum = nNum / 10;
	}
	return 0;
}

int	DigittoInt09019(int *p_nDigit, int *nNum, int nDigit)
{
	*nNum = 0;
	for (int i = 0; i<nDigit ; i++)
	{
		*nNum *= 10;
		*nNum += p_nDigit[i];
	}
	return 0;
}

int DigitShiftLeft09019(int *p_nDigit, int nDigit)
{
	int nSave = 0;
	nSave = p_nDigit[0];
	for (int i = 1; i < nDigit; i++)
	{
		p_nDigit[i - 1] = p_nDigit[i];
	}
	p_nDigit[nDigit - 1] = nSave;
	return 0;
}

int DigitShiftRight09019(int *p_nDigit, int nDigit)
{
	int nSave = 0;
	nSave = p_nDigit[nDigit - 1];
	for (int i = nDigit - 2; 0 <= i; i--)
	{
		p_nDigit[i + 1] = p_nDigit[i];
	}
	p_nDigit[0] = nSave;
	return 0;
}

int QueueisEmpty09019(Queue09019 *queue)
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

int PrintRoute09019(int nNow, int nBegin, char *a_cMap, int *a_nMap)
{
	if (nNow != nBegin)
	{
		PrintRoute09019(a_nMap[nNow], nBegin, a_cMap, a_nMap);
		printf("%c", a_cMap[nNow]);
	}
	return 0;
}
int Problem09019(void)
{
	int nRound = 0;
	int nBegin = 0;
	int nEnd = 0;
	int a_nMap[10000] = { 0, };
	char a_cMap[10000] = { 0, };
	Queue09019 *queue = NULL;
	queue = (Queue09019*)malloc(sizeof(Queue09019));
	memset(queue, 0, sizeof(Queue09019));

	scanf("%d", &nRound);
	for(int i = 0; i<nRound; i++)
	{
		memset(queue, 0, sizeof(Queue09019));
		memset(a_nMap, -1, sizeof(a_nMap));
		memset(a_cMap, 0, sizeof(a_cMap));
		scanf("%d %d", &nBegin, &nEnd);
		QueuePush09019(queue, nBegin);
		a_nMap[nBegin] = 0;
		while (QueueisEmpty09019(queue) == 0)
		{
			int nGet = 0;
			int nCheck = 0;
			int a_nGet[4] = { 0, };
			QueuePop09019(queue, &nGet);

			nCheck = (2 * nGet) % 10000;
			if (a_nMap[nCheck] == -1)
			{
				a_cMap[nCheck] = 'D';
				a_nMap[nCheck] = nGet;
				if (nCheck == nEnd)
				{
					break;
				}
				QueuePush09019(queue, nCheck);
			}
			nCheck = nGet - 1;
			if (nCheck == -1)
			{
				nCheck = 9999;
			}
			if (a_nMap[nCheck] == -1)
			{
				a_cMap[nCheck] = 'S';
				a_nMap[nCheck] = nGet;
				if (nCheck == nEnd)
				{
					break;
				}
				QueuePush09019(queue, nCheck);
			}
			InttoDigit09019(nGet, a_nGet, 4);
			DigitShiftLeft09019(a_nGet, 4);
			DigittoInt09019(a_nGet, &nCheck, 4);
			if (a_nMap[nCheck] == -1)
			{
				a_cMap[nCheck] = 'L';
				a_nMap[nCheck] = nGet;
				if (nCheck == nEnd)
				{
					break;
				}
				QueuePush09019(queue, nCheck);
			}
			InttoDigit09019(nGet, a_nGet, 4);
			DigitShiftRight09019(a_nGet, 4);
			DigittoInt09019(a_nGet, &nCheck, 4);
			if (a_nMap[nCheck] == -1)
			{
				a_cMap[nCheck] = 'R';
				a_nMap[nCheck] = nGet;
				if (nCheck == nEnd)
				{
					break;
				}
				QueuePush09019(queue, nCheck);
			}
		}
		while (QueueisEmpty09019(queue) == 0)
		{
			int nGet = 0;
			QueuePop09019(queue, &nGet);
		}
		PrintRoute09019(nEnd, nBegin, a_cMap, a_nMap);
		printf("\n");
	}
	return 0;
}