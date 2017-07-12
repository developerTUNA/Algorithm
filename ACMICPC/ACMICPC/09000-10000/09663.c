#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Check09663(int nRow, int nCol, int nQueen, int **pp_nQueen)
{
	for (int i = 0; i < nRow; i++)
	{
		if (pp_nQueen[i][nCol] == 1)
		{
			return 0;
		}
	}
	for (int nX = nRow-1, nY = nCol-1; 0 <= nX && 0 <= nY; nX--, nY--)
	{
		if (pp_nQueen[nX][nY] == 1)
		{
			return 0;
		}
	}
	for (int nX = nRow - 1, nY = nCol + 1; 0 <= nX && nY < nQueen; nX--, nY++)
	{
		if (pp_nQueen[nX][nY] == 1)
		{
			return 0;
		}
	}
	return 1;
}
int GO_09663(int nRow, int nQueen, int ** pp_nQueen, int *nResult)
{
	if (nRow == nQueen)
	{
		(*nResult)++;
		return 0;
	}

	for (int nCol = 0; nCol < nQueen; nCol++)
	{
		pp_nQueen[nRow][nCol] = 1;
		if (Check09663(nRow, nCol, nQueen, pp_nQueen) == 1)
		{
			GO_09663(nRow + 1, nQueen, pp_nQueen, nResult);
		}
		pp_nQueen[nRow][nCol] = 0;
	}
	return 0;
}

int Problem09663(void)
{
	int nResult = 0;
	int nQueen = 0;
	int **pp_nQueen = NULL;

	scanf("%d", &nQueen);
	pp_nQueen = malloc(sizeof(int*)*(nQueen));
	memset(pp_nQueen, 0, sizeof(int*)*(nQueen));
	for (int i = 0; i < nQueen; i++)
	{
		pp_nQueen[i] = malloc(sizeof(int)*(nQueen));
		memset(pp_nQueen[i], 0, sizeof(int)*(nQueen));
	}

	GO_09663(0, nQueen, pp_nQueen, &nResult);

	printf("%d\n", nResult);

	for (int i = 0; i < nQueen; i++)
	{
		free(pp_nQueen[i]);
	}
	free(pp_nQueen);

	return 0;
}