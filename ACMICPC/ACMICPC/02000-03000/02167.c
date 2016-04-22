#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Problem02167(void)
{
	int nN = 0, nM = 0;
	int nRound = 0;
	int **p2_nNum = NULL;
	int nStartRow = 0, nStartCol = 0, nEndRow = 0, nEndCol = 0;
	int nSum = 0;
	scanf("%d %d", &nN, &nM);
	p2_nNum = (int **) malloc(sizeof(int*)*nN);
	for (int i = 0; i < nN; i++)
	{
		p2_nNum[i] = (int*)malloc(sizeof(int)*nM);
	}
	for (int i = 0; i < nN; i++)
	{
		for (int j = 0; j < nM; j++)
		{
			scanf("%d", &p2_nNum[i][j]);
		}
	}
	scanf("%d", &nRound);
	for (int i = 0; i < nRound; i++)
	{
		nSum = 0;
		scanf("%d %d %d %d", &nStartRow, &nStartCol, &nEndRow, &nEndCol);
		for (int j = nStartRow - 1; j < nEndRow ; j++)
		{
			for (int k = nStartCol - 1; k < nEndCol ; k++)
			{
				nSum += p2_nNum[j][k];
			}
		}
		printf("%d\n", nSum);
	}
	return 0;
}