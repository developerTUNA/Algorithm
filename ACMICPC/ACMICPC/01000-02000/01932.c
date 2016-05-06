#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem01932(void)
{
	int nSize = 0;
	int nMax = 0;
	int **pp_nNum = NULL;
	int **pp_nNum_DP = NULL;
	
	scanf("%d", &nSize);
	pp_nNum = (int **)malloc(sizeof(int*)*nSize);
	pp_nNum_DP = (int **)malloc(sizeof(int*)*nSize);
	for (int i = 0; i < nSize;i++)
	{
		pp_nNum[i] = (int *)malloc(sizeof(int)*nSize);
		memset(pp_nNum[i], 0, sizeof(int)*nSize);
		pp_nNum_DP[i] = (int *)malloc(sizeof(int)*nSize);
		memset(pp_nNum_DP[i], 0, sizeof(int)*nSize);
	}
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &pp_nNum[i][j]);
		}
	}

	pp_nNum_DP[0][0] = pp_nNum[0][0];
	for (int i = 1; i < nSize; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (pp_nNum_DP[i][j] < pp_nNum_DP[i-1][j] + pp_nNum[i][j])
			{
				pp_nNum_DP[i][j] = pp_nNum_DP[i - 1][j] + pp_nNum[i][j];
			}
			if (pp_nNum_DP[i][j] < pp_nNum_DP[i - 1][j - 1] + pp_nNum[i][j] && 0 <= j - 1)
			{
				pp_nNum_DP[i][j] = pp_nNum_DP[i - 1][j - 1] + pp_nNum[i][j];
			}
		}
	}

	for (int i = 1; i < nSize; i++)
	{
		if (nMax < pp_nNum_DP[nSize - 1][i])
		{
			nMax = pp_nNum_DP[nSize - 1][i];
		}
	}
	printf("%d\n", nMax);
	for (int i = 0; i < nSize; i++)
	{
		free(pp_nNum[i]);
	}
	free(pp_nNum);
	return 0;
}