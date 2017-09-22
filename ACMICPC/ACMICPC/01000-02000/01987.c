#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GO_01987(int **pp_nBoard, int a_nCheck[26], int nRowSize, int nColSize, int nRowNow, int nColNow)
{
	int nResult = 0;
	int nResult_Inner = 0;
	int nFlag = 0;
	int a_nRowMove[4] = { 1,-1,0,0 };
	int a_nColMove[4] = { 0,0,1,-1 };
	
	for (int i = 0; i < 4; i++)
	{
		int nRowGo = a_nRowMove[i] + nRowNow;
		int nColGo = a_nColMove[i] + nColNow;
		if (0 <= nRowGo && nRowGo < nRowSize &&
			0 <= nColGo && nColGo < nColSize &&
			a_nCheck[pp_nBoard[nRowGo][nColGo]] == 0)
		{
			nFlag = 1;
			a_nCheck[pp_nBoard[nRowGo][nColGo]] = 1;
			nResult_Inner = GO_01987(pp_nBoard, a_nCheck, nRowSize, nColSize, nRowGo, nColGo);
			if (nResult < nResult_Inner)
			{
				nResult = nResult_Inner;
			}
			a_nCheck[pp_nBoard[nRowGo][nColGo]] = 0;
		}
	}
	if (nFlag == 0)
	{
		for (int i = 0; i < 26; i++)
		{
			if (a_nCheck[i] == 1)
			{
				nResult++;
			}
		}
	}
	return nResult;
}

int Problem01987(void)
{
	int nRow = 0;
	int nCol = 0;
	int nResult = 0;
	int **pp_nBoard = NULL;
	int a_nCheck[26] = { 0, };

	scanf("%d %d", &nRow, &nCol);
	pp_nBoard = (int**)malloc(sizeof(int*)*(nRow));
	for (int i = 0; i < nRow; i++)
	{
		pp_nBoard[i] = (int*)malloc(sizeof(int)*(nCol));
		memset(pp_nBoard[i], 0, sizeof(int)*(nCol));
	}

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			char cTemp = 0;
			scanf(" %c", &cTemp);
			pp_nBoard[i][j] = cTemp - 'A';
		}
	}
	
	a_nCheck[pp_nBoard[0][0]] = 1;
	nResult = GO_01987(pp_nBoard, a_nCheck, nRow, nCol, 0, 0);

	printf("%d\n", nResult);
	for (int i = 0; i < nRow; i++)
	{
		free(pp_nBoard[i]);
	}
	free(pp_nBoard);
	return 0;
}