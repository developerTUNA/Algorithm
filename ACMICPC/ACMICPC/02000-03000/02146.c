#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct RowCol02146_
{
	int nRow;
	int nCol;
}RowCol02146;

typedef struct Node02146_
{
	RowCol02146 data;
	struct Node02146_ *next;
}Node02146;

typedef struct Queue02146_
{
	int nSize;
	Node02146 *first;
	Node02146 *last;
}Queue02146;

typedef struct Stack02146_
{
	int nSize;
	Node02146 *top;
}Stack02146;

int StackPush02146(Stack02146 *stack, int nRow, int nCol)
{
	Node02146 *newNode = NULL;
	RowCol02146 data;

	newNode = (Node02146*)malloc(sizeof(Node02146));
	memset(newNode, 0, sizeof(Node02146));
	data.nRow = nRow;
	data.nCol = nCol;
	newNode->data = data;
	if (stack->nSize == 0)
	{
		newNode->next = NULL;
	}
	else
	{
		newNode->next = stack->top;
	}
	stack->top = newNode;
	stack->nSize++;

	return 0;
}

int StackPop02146(Stack02146 *stack, int *nRow, int *nCol)
{
	Node02146 *delNode = NULL;

	delNode = stack->top;
	*nRow = delNode->data.nRow;
	*nCol = delNode->data.nCol;

	stack->top = stack->top->next;
	stack->nSize--;
	free(delNode);

	return 0;
}

int QueuePush02146(Queue02146 *queue, int nRow, int nCol)
{
	Node02146 *newNode = NULL;
	newNode = (Node02146*)malloc(sizeof(Node02146));
	newNode->data.nRow = nRow;
	newNode->data.nCol = nCol;
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
int QueuePop02146(Queue02146 *queue, int *nRow, int *nCol)
{
	Node02146 *delNode = NULL;

	if (queue->nSize == 0)
	{
		return -1;
	}

	delNode = queue->first;
	*nRow = delNode->data.nRow;
	*nCol = delNode->data.nCol;

	queue->first = queue->first->next;
	if (queue->nSize == 1)
	{
		queue->last = NULL;
	}
	queue->nSize--;

	free(delNode);
	return 0;
}
int GroupMake02146(int nSize, int **pp_nMap_Org, int **pp_nMap_Group)
{
	int nCount = 0;
	int a_nMoveRow[4] = { 0,0,1,-1 };
	int a_nMoveCol[4] = { 1,-1,0,0 };
	Stack02146 *stack = NULL;
	stack = (Stack02146*)malloc(sizeof(Stack02146));
	memset(stack, 0, sizeof(Stack02146));
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			if (pp_nMap_Org[i][j] == 0 ||
				pp_nMap_Group[i][j] != 0)
			{
				continue;
			}
			int nNowRow = i;
			int nNowCol = j;
			nCount++;
			pp_nMap_Group[nNowRow][nNowCol] = nCount;
			StackPush02146(stack, nNowRow, nNowCol);
			while (0<stack->nSize)
			{
				StackPop02146(stack, &nNowRow, &nNowCol);
				for (int k = 0; k < nSize; k++)
				{
					int nCheckRow = nNowRow + a_nMoveRow[k];
					int nCheckCol = nNowCol + a_nMoveCol[k];

					if (nCheckRow < 0 || nSize <= nCheckRow ||
						nCheckCol < 0 || nSize <= nCheckCol)
					{
						continue;
					}
					if (pp_nMap_Org[nCheckRow][nCheckCol] == 0 ||
						pp_nMap_Group[nCheckRow][nCheckCol] != 0)
					{
						continue;
					}
					pp_nMap_Group[nCheckRow][nCheckCol] = nCount;
					StackPush02146(stack, nCheckRow, nCheckCol);
				}

			}
		}
	}
	free(stack);
	return nCount;
}
int GroupCalc02146(int nSize, int nGroupCount, int **pp_nMap_Group, int **pp_nMap_Bridge)
{
	int nResult = 0;
	int a_nMoveRow[4] = { 0,0,1,-1 };
	int a_nMoveCol[4] = { 1,-1,0,0 };
	Queue02146 *queue = NULL;
	queue = (Queue02146*)malloc(sizeof(Queue02146));
	memset(queue, 0, sizeof(Queue02146));

	nResult = nSize*nSize + 1;
	for (int i = 0; i < nGroupCount; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			memset(pp_nMap_Bridge[j], 0, sizeof(int)*nSize);
		}
		for (int j = 0; j < nSize; j++)
		{
			for (int k = 0; k < nSize; k++)
			{
				if (pp_nMap_Group[j][k] == i + 1)
				{
					QueuePush02146(queue, j, k);
					pp_nMap_Bridge[j][k] = 1;
				}
			}
		}
		int nBridge = 0;
		while (0 < queue->nSize)
		{
			int nGetRow = 0;
			int nGetCol = 0;

			QueuePop02146(queue, &nGetRow, &nGetCol);
			for (int j = 0; j < 4; j++)
			{
				int nCheckRow = nGetRow + a_nMoveRow[j];
				int nCheckCol = nGetCol + a_nMoveCol[j];
				if (nCheckRow < 0 || nSize <= nCheckRow ||
					nCheckCol < 0 || nSize <= nCheckCol)
				{
					continue;
				}
				if (pp_nMap_Bridge[nCheckRow][nCheckCol] == 0 &&
					pp_nMap_Group[nCheckRow][nCheckCol] == 0)//||
															 //pp_nMap_Bridge[nGetRow][nGetCol] + 1 < pp_nMap_Bridge[nCheckRow][nCheckCol])
				{
					pp_nMap_Bridge[nCheckRow][nCheckCol] = pp_nMap_Bridge[nGetRow][nGetCol] + 1;
					QueuePush02146(queue, nCheckRow, nCheckCol);
				}

				if (pp_nMap_Group[nCheckRow][nCheckCol] != i + 1 &&
					pp_nMap_Group[nCheckRow][nCheckCol] != 0)
				{
					nBridge = pp_nMap_Bridge[nGetRow][nGetCol];
					if (nBridge < nResult)
					{
						nResult = nBridge;
					}
				}
			}
		}
	}
	free(queue);
	return nResult;
}
int Problem02416(void)
{
	int nSize = 0;
	int nGroupCount = 0;
	int nBridge = 0;
	int **pp_nMap_Org = NULL;
	int **pp_nMap_Group = NULL;
	int **pp_nMap_Bridge = NULL;

	scanf("%d", &nSize);
	pp_nMap_Org = (int**)malloc(sizeof(int*)*nSize);
	pp_nMap_Group = (int**)malloc(sizeof(int*)*nSize);
	pp_nMap_Bridge = (int**)malloc(sizeof(int*)*nSize);
	for (int i = 0; i < nSize; i++)
	{
		pp_nMap_Org[i] = (int*)malloc(sizeof(int)*nSize);
		pp_nMap_Group[i] = (int*)malloc(sizeof(int)*nSize);
		pp_nMap_Bridge[i] = (int*)malloc(sizeof(int)*nSize);
		memset(pp_nMap_Org[i], 0, sizeof(int)*nSize);
		memset(pp_nMap_Group[i], 0, sizeof(int)*nSize);
		memset(pp_nMap_Bridge[i], 0, sizeof(int)*nSize);
	}

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			scanf("%d", &pp_nMap_Org[i][j]);
		}
	}

	nGroupCount = GroupMake02146(nSize, pp_nMap_Org, pp_nMap_Group);
	nBridge = GroupCalc02146(nSize, nGroupCount, pp_nMap_Group, pp_nMap_Bridge);
	printf("%d\n", nBridge - 1);

	for (int i = 0; i < nSize; i++)
	{
		free(pp_nMap_Org[i]);
		free(pp_nMap_Group[i]);
		free(pp_nMap_Bridge[i]);
	}
	free(pp_nMap_Org);
	free(pp_nMap_Group);
	free(pp_nMap_Bridge);
	return 0;
}