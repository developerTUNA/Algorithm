#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SwapInt10971(int *nA, int *nB)
{
	int nTemp = 0;
	nTemp = *nA;
	*nA = *nB;
	*nB = nTemp;
	return 0;
}

int Permutation_Next10971(int nSize, int *p_nList)
{
	int nSwap1 = 0;
	int nSwap2 = 0;

	for (int i = nSize - 1; 0 < i; i--)
	{
		if (p_nList[i - 1] < p_nList[i])
		{
			nSwap1 = i;
			break;
		}
	}
	if (nSwap1 == 0)
	{
		return -1;
	}

	for (int i = nSize - 1; nSwap1 <= i; i--)
	{
		if (p_nList[nSwap1 - 1] < p_nList[i])
		{
			nSwap2 = i;
			break;
		}
	}

	SwapInt10971(&p_nList[nSwap1 - 1], &p_nList[nSwap2]);

	nSwap2 = nSize - 1;
	while (nSwap1 < nSwap2)
	{
		SwapInt10971(&p_nList[nSwap1], &p_nList[nSwap2]);
		nSwap1++;
		nSwap2--;
	}
	return 0;
}

int nRoutePrise10971(int nSize, int *p_nRoute, int **pp_nPrice)
{
	int nStart = 0;
	int nEnd = 0;
	int nPrice = 0;
	for (int i = 0; i < nSize - 1; i++)
	{
		nStart = p_nRoute[i];
		nEnd = p_nRoute[i + 1];
		if (0 < pp_nPrice[nStart][nEnd])
		{
			nPrice = nPrice + pp_nPrice[nStart][nEnd];
		}
		else
		{
			return -1;
		}
	}
	if (0 < pp_nPrice[p_nRoute[nSize - 1]][p_nRoute[0]])
	{
		nPrice = nPrice + pp_nPrice[p_nRoute[nSize - 1]][p_nRoute[0]];
	}
	else
	{
		return -1;
	}
	return nPrice;
}

int Problem10971(void)
{
	int nSize = 0;
	int nPrice_Get = 0;
	int nPrice_Min = 0;

	int *p_nPermutation = NULL;
	int **pp_nPrice = NULL;

	scanf("%d", &nSize);
	pp_nPrice = (int**)malloc(sizeof(int*)*(nSize));
	for (int i = 0; i < nSize; i++)
	{
		pp_nPrice[i] = (int*)malloc(sizeof(int)*(nSize));
		memset(pp_nPrice[i], 0, sizeof(int)*(nSize));
	}
	p_nPermutation = (int*)malloc(sizeof(int)*(nSize));
	for (int i = 0; i < nSize; i++)
	{
		p_nPermutation[i] = i;
	}

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			scanf("%d", &pp_nPrice[i][j]);
		}
	}

	nPrice_Min = 1000000 * nSize;

	do
	{
		nPrice_Get = nRoutePrise10971(nSize, p_nPermutation, pp_nPrice);
		if (nPrice_Get < nPrice_Min && nPrice_Get != -1)
		{
			nPrice_Min = nPrice_Get;
		}

	} while (Permutation_Next10971(nSize, p_nPermutation) == 0);

	printf("%d\n", nPrice_Min);

	for (int i = 0; i < nSize; i++)
	{
		free(pp_nPrice[i]);
	}
	free(pp_nPrice);
	free(p_nPermutation);
	return 0;
}