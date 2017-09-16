#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node01525_
{
	int nData;
	struct Node01525_ *next;
}Node01525;

typedef struct Queue01525_
{
	int nSize;
	Node01525 *head;
	Node01525 *tail;
}Queue01525;

int QueuePush01525(Queue01525 *queue, int nData)
{
	Node01525 *newNode = NULL;
	newNode = (Node01525*)malloc(sizeof(Node01525));
	memset(newNode, 0, sizeof(Node01525));

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

int QueuePop01525(Queue01525 *queue, int *p_nData)
{
	Node01525 *delNode = NULL;
	if (queue->nSize == 0)
	{
		return -1;
	}

	if (queue->nSize == 0)
	{
		queue->tail = NULL;
	}
	delNode = queue->head;
	*p_nData = delNode->nData;
	queue->head = queue->head->next;
	free(delNode);
	queue->nSize--;
	return 0;
}

int GetPermutationOrder01525(int *p_nPermutation, int nSize, int *p_nOrder)
{
	int nOrder = 0;
	int *p_nPow = NULL;
	int *p_nCheck = NULL;

	p_nPow = (int*)malloc(sizeof(int)*nSize);
	memset(p_nPow, 0, sizeof(int)*nSize);
	p_nCheck = (int*)malloc(sizeof(int)*(nSize + 1));
	memset(p_nCheck, 0, sizeof(int)*(nSize + 1));

	p_nPow[nSize - 1] = 1;
	for (int i = nSize - 2, nPow = 1; 0 <= i; i--, nPow++)
	{
		p_nPow[i] = p_nPow[i + 1] * nPow;
	}
	nOrder = 1;
	for (int i = 0; i < nSize; i++)
	{
		int nUseCount = 0;
		for (int j = 1; j < p_nPermutation[i]; j++)
		{
			if (p_nCheck[j] != 1)
			{
				nOrder = nOrder + p_nPow[i];
			}
		}
		p_nCheck[p_nPermutation[i]] = 1;
	}

	free(p_nPow);
	free(p_nCheck);
	*p_nOrder = nOrder;

	return 0;
}

int SetPermutationOrder01525(int *p_nPermutation, int nSize, int nOrder)
{
	int *p_nPow = NULL;
	int *p_nCheck = NULL;

	p_nPow = (int*)malloc(sizeof(int)*nSize);
	memset(p_nPow, 0, sizeof(int)*nSize);
	p_nCheck = (int*)malloc(sizeof(int)*(nSize + 1));
	memset(p_nCheck, 0, sizeof(int)*(nSize + 1));

	p_nPow[nSize - 1] = 1;
	for (int i = nSize - 2, nPow = 1; 0 <= i; i--, nPow++)
	{
		p_nPow[i] = p_nPow[i + 1] * nPow;
	}

	for (int i = 0; i < nSize; i++)
	{
		int nBegin = 0;
		int nUseCount = 0;
		for (int j = 1; j <= nSize; j++)
		{
			if (p_nCheck[j] == 1)
			{
				continue;
			}
			if(p_nPow[i] < nOrder)
			{
				nOrder = nOrder - p_nPow[i];
			}
			else
			{
				p_nPermutation[i] = j;
				p_nCheck[j] = 1;
				break;
			}
		}
	}

	free(p_nPow);
	free(p_nCheck);
	return 0;
}

int QueueisEmpty01525(Queue01525 *queue)
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
int Dim1to2Int01525(int *p_nDim1, int *p_nDim2, int nRow, int nCol)
{
	int **pp_nDim2 = NULL;
	pp_nDim2 = (int**)malloc(sizeof(int*)*nRow);
	for (int i = 0; i < nRow; i++)
	{
		pp_nDim2[i] = (int*)&p_nDim2[i*nCol];
	}
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			pp_nDim2[i][j] = p_nDim1[i * nCol + j];
		}
	}
	free(pp_nDim2);
	return 0;
}

int Dim2to1Int01525(int *p_nDim1, int *p_nDim2, int nRow, int nCol)
{
	int **pp_nDim2 = NULL;
	pp_nDim2 = (int**)malloc(sizeof(int*)*nRow);
	for (int i = 0; i < nRow; i++)
	{
		pp_nDim2[i] = (int*)&p_nDim2[i*nCol];
	}

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			p_nDim1[i * nCol + j] = pp_nDim2[i][j];
		}
	}
	free(pp_nDim2);
	return 0;
}

int SwapInt01525(int *nA, int *nB)
{
	int nTemp = 0;
	nTemp = *nA;
	*nA = *nB;
	*nB = nTemp;
	return 0;
}
int Problem01525(void)
{
	int nOrder = 0;
	int aa_nPuzzle[3][3] = { 0, };
	int a_nPuzzle[9] = { 0, };
	int *p_nCheck = NULL;
	Queue01525 *queue = NULL;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &a_nPuzzle[i]);
		if (a_nPuzzle[i] == 0)
		{
			a_nPuzzle[i] = 9;
		}
	}
	p_nCheck = (int*)malloc(sizeof(int)*(1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 + 1));
	memset(p_nCheck, -1, sizeof(int)*(1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 + 1));
	queue = (Queue01525*)malloc(sizeof(Queue01525));
	memset(queue, 0, sizeof(Queue01525));

	GetPermutationOrder01525(a_nPuzzle, 9, &nOrder);
	QueuePush01525(queue, nOrder);
	p_nCheck[nOrder] = 0;
	while (QueueisEmpty01525(queue) == 0)
	{
		int nOrderGet = 0;
		int nOrderNew = 0;
		int nRow = 0;
		int nCol = 0;
		QueuePop01525(queue, &nOrderGet);
		SetPermutationOrder01525(a_nPuzzle, 9, nOrderGet);
		Dim1to2Int01525(a_nPuzzle, (int*)aa_nPuzzle, 3, 3);
		if (nOrderGet == 1)
		{
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (aa_nPuzzle[i][j] == 9)
				{
					nRow = i;
					nCol = j;
					i = 3;
					j = 3;
				}
			}
		}

		if (1 <= nRow)
		{
			SetPermutationOrder01525(a_nPuzzle, 9, nOrderGet);
			Dim1to2Int01525(a_nPuzzle, (int*)aa_nPuzzle, 3, 3);
			SwapInt01525(&aa_nPuzzle[nRow][nCol], &aa_nPuzzle[nRow - 1][nCol]);
			Dim2to1Int01525(a_nPuzzle, (int*)aa_nPuzzle, 3, 3);
			GetPermutationOrder01525(a_nPuzzle, 9, &nOrderNew);
			if (nOrderNew == 1)
			{
				p_nCheck[nOrderNew] = p_nCheck[nOrderGet] + 1;
				break;
			}
			if (p_nCheck[nOrderNew] == -1)
			{
				QueuePush01525(queue, nOrderNew);
				p_nCheck[nOrderNew] = p_nCheck[nOrderGet] + 1;
			}
		}

		if (nRow <= 1)
		{
			SetPermutationOrder01525(a_nPuzzle, 9, nOrderGet);
			Dim1to2Int01525(a_nPuzzle, (int*)aa_nPuzzle, 3, 3);
			SwapInt01525(&aa_nPuzzle[nRow][nCol], &aa_nPuzzle[nRow + 1][nCol]);
			Dim2to1Int01525(a_nPuzzle, (int*)aa_nPuzzle, 3, 3);
			GetPermutationOrder01525(a_nPuzzle, 9, &nOrderNew);
			if (nOrderNew == 1)
			{
				p_nCheck[nOrderNew] = p_nCheck[nOrderGet] + 1;
				break;
			}
			if (p_nCheck[nOrderNew] == -1)
			{
				QueuePush01525(queue, nOrderNew);
				p_nCheck[nOrderNew] = p_nCheck[nOrderGet] + 1;
			}
		}
		
		if (1 <= nCol)
		{
			SetPermutationOrder01525(a_nPuzzle, 9, nOrderGet);
			Dim1to2Int01525(a_nPuzzle, (int*)aa_nPuzzle, 3, 3);
			SwapInt01525(&aa_nPuzzle[nRow][nCol], &aa_nPuzzle[nRow][nCol-1]);
			Dim2to1Int01525(a_nPuzzle, (int*)aa_nPuzzle, 3, 3);
			GetPermutationOrder01525(a_nPuzzle, 9, &nOrderNew);
			if (nOrderNew == 1)
			{
				p_nCheck[nOrderNew] = p_nCheck[nOrderGet] + 1;
				break;
			}
			if (p_nCheck[nOrderNew] == -1)
			{
				QueuePush01525(queue, nOrderNew);
				p_nCheck[nOrderNew] = p_nCheck[nOrderGet] + 1;
			}
		}

		if (nCol <= 1)
		{
			SetPermutationOrder01525(a_nPuzzle, 9, nOrderGet);
			Dim1to2Int01525(a_nPuzzle, (int*)aa_nPuzzle, 3, 3);
			SwapInt01525(&aa_nPuzzle[nRow][nCol], &aa_nPuzzle[nRow][nCol+1]);
			Dim2to1Int01525(a_nPuzzle, (int*)aa_nPuzzle, 3, 3);
			GetPermutationOrder01525(a_nPuzzle, 9, &nOrderNew);
			if (nOrderNew == 1)
			{
				p_nCheck[nOrderNew] = p_nCheck[nOrderGet] + 1;
				break;
			}
			if (p_nCheck[nOrderNew] == -1)
			{
				QueuePush01525(queue, nOrderNew);
				p_nCheck[nOrderNew] = p_nCheck[nOrderGet] + 1;
			}
		}
	}
	while (QueueisEmpty01525(queue) == 0)
	{
		int nTemp = 0;
		QueuePop01525(queue, &nTemp);
	}

	printf("%d\n", p_nCheck[1]);
	free(p_nCheck);
	free(queue);
	return 0;
}