#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct RowCol07576_
{
	int nRow;
	int nCol;
}RowCol07576;

typedef struct Node07576_
{
	RowCol07576 data;
	struct Node07576_ *next;
}Node07576;

typedef struct Queue07576_
{
	int nSize;
	Node07576 *firstNode;
	Node07576 *lastNode;
}Queue07576;

int QueuePush07576(Queue07576 *queue, int nRow, int nCol)
{
	RowCol07576 data;
	Node07576 *newNode = NULL;
	data.nRow = nRow;
	data.nCol = nCol;
	
	newNode = (Node07576*)malloc(sizeof(Node07576));
	newNode->data = data;
	newNode->next = NULL;

	if (queue->nSize == 0)
	{
		queue->firstNode = newNode;
		queue->lastNode = newNode;
		queue->nSize++;
	}
	else
	{
		queue->lastNode->next = newNode;
		queue->lastNode = newNode;
		queue->nSize++;
	}
	return 0;
}

int QueuePop07576(Queue07576 *queue, int *nRow, int *nCol)
{
	Node07576 *delNode = NULL;
	if(queue->nSize==0)
	{
		return -1;
	}
	
	*nRow = queue->firstNode->data.nRow;
	*nCol = queue->firstNode->data.nCol;

	delNode = queue->firstNode;
	queue->firstNode = queue->firstNode->next;
	if (queue->nSize == 1)
	{
		queue->lastNode = NULL;
	}
	queue->nSize--;

	free(delNode);
	return 0;
}

int Problem07576(void)
{
	int nRow = 0;
	int nCol = 0;
	int nGetRow = 0;
	int nGetCol = 0;
	int nResult = 0;
	int a_nMoveRow[4] = { 1,-1,0,0 };
	int a_nMoveCol[4] = { 0,0,1,-1 };
	int **pp_nBox = NULL;
	Queue07576 *queue;

	scanf("%d %d", &nCol, &nRow);
	pp_nBox = (int**)malloc(sizeof(int*)*nRow);
	for (int i = 0; i < nRow; i++)
	{
		pp_nBox[i] = (int*)malloc(sizeof(int)*nCol);
		memset(pp_nBox[i], 0, sizeof(int)*nCol);
	}
	queue = (Queue07576*)malloc(sizeof(Queue07576));
	memset(queue, 0, sizeof(Queue07576));

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			scanf("%d", &pp_nBox[i][j]);

			if (pp_nBox[i][j] == 1)
			{
				QueuePush07576(queue, i, j);
			}
		}
	}

	while (queue->nSize != 0)
	{

		QueuePop07576(queue, &nGetRow, &nGetCol);

		for (int i = 0; i < 4; i++)
		{
			int nCheckRow = nGetRow + a_nMoveRow[i];
			int nCheckCol = nGetCol + a_nMoveCol[i];

			if (nCheckRow < 0 || nRow <= nCheckRow||
				nCheckCol < 0 || nCol <= nCheckCol)
			{
				continue;
			}
			if (pp_nBox[nCheckRow][nCheckCol] != 0)
			{
				continue;
			}
			
			pp_nBox[nCheckRow][nCheckCol] = pp_nBox[nGetRow][nGetCol]+1;
			QueuePush07576(queue, nCheckRow, nCheckCol);
			if (nResult < pp_nBox[nCheckRow][nCheckCol])
			{
				nResult = pp_nBox[nCheckRow][nCheckCol];
			}
		}
	}

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			if (pp_nBox[i][j] == 0)
			{
				nResult = 0;
			}
		}
	}
	printf("%d\n", nResult-1);

	free(queue);
	return 0;
}