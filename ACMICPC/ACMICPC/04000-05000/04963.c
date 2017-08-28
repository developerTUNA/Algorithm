#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Check04963(int **pp_nMap, int **pp_nMap_Color, int nRow, int nCol, int nRowNow, int nColNow, int nCount)
{
	int nRowGo[8] = { 1,-1,0,0,1,1,-1,-1 };
	int nColGo[8] = { 0,0,1,-1,1,-1,1,-1 };

	pp_nMap_Color[nRowNow][nColNow] = nCount;

	for (int i = 0; i < 8; i++)
	{
		int nRow_Check = nRowGo[i] + nRowNow;
		int nCol_Check = nColGo[i] + nColNow;
		if (0 <= nRow_Check && nRow_Check < nRow &&
			0 <= nCol_Check && nCol_Check < nCol)
		{
			if (pp_nMap[nRow_Check][nCol_Check] == 1 &&
				pp_nMap_Color[nRow_Check][nCol_Check] == 0)
			{
				Check04963(pp_nMap, pp_nMap_Color, nRow, nCol, nRow_Check, nCol_Check, nCount);
			}
		}
	}
	return 0;
}
int Problem04963(void)
{
	int nRow = 0;
	int nCol = 0;
	int nCount = 0;
	int **pp_nMap = NULL;
	int **pp_nMap_Color = NULL;

	nRow = 1;
	nCol = 1;
	while (1)
	{
		scanf("%d %d", &nCol, &nRow);
		if (nCol == 0 && nRow == 0)
		{
			break;
		}
		pp_nMap = (int**)malloc(sizeof(int*)*nRow);
		pp_nMap_Color = (int**)malloc(sizeof(int*)*nRow);
		for (int i = 0; i < nRow; i++)
		{
			pp_nMap[i] = (int*)malloc(sizeof(int)*nCol);
			pp_nMap_Color[i] = (int*)malloc(sizeof(int)*nCol);
			memset(pp_nMap[i], 0, sizeof(int)*nCol);
			memset(pp_nMap_Color[i], 0, sizeof(int)*nCol);
		}
		
		for (int i = 0; i < nRow; i++)
		{
			for (int j = 0; j < nCol; j++)
			{
				scanf("%d", &pp_nMap[i][j]);
			}
		}
		nCount = 0;
		for (int i = 0; i < nRow; i++)
		{
			for (int j = 0; j < nCol; j++)
			{
				if (pp_nMap[i][j] == 1 && pp_nMap_Color[i][j] == 0)
				{
					nCount++;
					Check04963(pp_nMap, pp_nMap_Color, nRow, nCol, i, j, nCount);
				}
			}
		}

		printf("%d\n", nCount);
		for (int i = 0; i < nRow; i++)
		{
			free(pp_nMap[i]);
			free(pp_nMap_Color[i]);
		}
		free(pp_nMap);
		free(pp_nMap_Color);
	}
	return 0;
}