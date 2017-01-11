#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _QueueNode03055
{
	int nRow;
	int nCol;
	struct _QueueNode03055 *Next;
}typedef QueueNode03055;

int QueuePush03055(QueueNode03055 *QueueHead, int nRow, int nCol)
{
	QueueNode03055 *QueueNodeNew = NULL;
	QueueNodeNew = malloc(sizeof(QueueNode03055));
	QueueNodeNew->nRow = nRow;
	QueueNodeNew->nCol = nCol;
	QueueNodeNew->Next = QueueHead;

	return QueueNodeNew;
}

int QueuePop03055(QueueNode03055 *QueueHead, int *nRow, int *nCol)
{
	QueueNode03055 *QueueNext = NULL;
	QueueNode03055 *QueueLast = NULL;
	if (QueueHead == NULL)
	{
		return -1;
	}
	QueueNext = QueueHead;
	QueueLast = QueueHead;
	while (QueueLast->Next != NULL)
	{
		QueueNext = QueueNext->Next;
		QueueLast = QueueNext->Next;
	}
	*nRow = QueueLast->nRow;
	*nCol = QueueLast->nCol;
	QueueNext->Next = NULL;
	free(QueueLast);
	return 0;
}
int BFS03055(char **pp_chMap, int nRow, int nCol)
{
	int arr_nMoveRow[4] = { 1,-1,0,0 };
	int arr_nMoveCol[4] = { 0,0,1,-1 };
	int nRowRet = 0;
	int nColRet = 0;
	QueueNode03055 *QueueHead = NULL;
	for (int i = 1; i <= nRow; i++)
	{
		for (int j = 1; j <= nCol; j++)
		{
			if (pp_chMap[i][j] == -2)
			{
				QueuePush03055(QueueHead, i, j);
			}
		}
	}
	
	while (QueuePop03055(QueueHead, &nRowRet, &nColRet) != -1)
	{
		int nTemp = 0;
		nTemp = pp_chMap[nRowRet][nColRet];
		for (int i = 0; i < 4; i++)
		{
			if (pp_chMap[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]]==0)
			{
				pp_chMap[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]] = nTemp + 1;
				QueuePush03055(QueueHead, nRowRet + arr_nMoveRow[i], nColRet + arr_nMoveCol[i]);
			}
		}
	}
	return 0;
}

int Problem03055(void)
{
	int nRow = 0;
	int nCol = 0;
	char **pp_chMap = NULL;

	scanf("%d %d", &nRow, &nCol);
	pp_chMap = malloc(sizeof(char*)*(nRow + 2));
	for (int i = 0; i < nRow + 2; i++)
	{
		pp_chMap[i] = malloc(sizeof(char)*(nCol + 2));
		memset(pp_chMap[i], -1, sizeof(char)*(nCol + 2));
	}

	for (int i = 1; i <= nRow; i++)
	{
		for (int j = 1; j <= nCol; j++)
		{
			scanf("%c", &pp_chMap[i][j]);
			if (pp_chMap[i][j] == 'D')
			{
				pp_chMap[i][j] = -3;
			}
			else if (pp_chMap[i][j] == '*')
			{
				pp_chMap[i][j] = -2;
			}
			else if (pp_chMap[i][j] == 'X')
			{
				pp_chMap[i][j] = -1;
			}
			else if (pp_chMap[i][j] == '.')
			{
				pp_chMap[i][j] = 0;
			}
		}
	}
	
	BFS03055(pp_chMap, nRow, nCol);

	for (int i = 0; i < nRow + 2; i++)
	{
		free(pp_chMap[i]);
	}
	free(pp_chMap);
	return 0;
}