#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SwapInt10819(int *nA, int *nB)
{
	int nTemp = 0;
	nTemp = *nA;
	*nA = *nB;
	*nB = nTemp;
	return 0;
}

int Permutation_Next10819(int nSize, int *p_nList)
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

	SwapInt10819(&p_nList[nSwap1 - 1], &p_nList[nSwap2]);

	nSwap2 = nSize - 1;
	while (nSwap1 < nSwap2)
	{
		SwapInt10819(&p_nList[nSwap1], &p_nList[nSwap2]);
		nSwap1++;
		nSwap2--;
	}
	return 0;
}

int Problem10819(void)
{
	int nSize = 0;
	int nMax = 0;
	int nTemp = 0;
	int *p_nPermutation = NULL;
	int *p_nList = NULL;

	scanf("%d", &nSize);
	p_nList = (int *)malloc(sizeof(int)*(nSize));
	memset(p_nList, 0, sizeof(int)*(nSize));

	p_nPermutation = (int *)malloc(sizeof(int)*(nSize));
	memset(p_nPermutation, 0, sizeof(int)*(nSize));
	for (int i = 0; i < nSize; i++)
	{
		scanf("%d", &p_nList[i]);
		p_nPermutation[i] = i;
	}
	nTemp = 0;
	for (int i = 0; i < nSize - 1; i++)
	{
		int nTemp2 = p_nList[p_nPermutation[i]] - p_nList[p_nPermutation[i + 1]];
		if (nTemp2 < 0)
		{
			nTemp2 = -1 * nTemp2;
		}
		nTemp = nTemp + nTemp2;
	}
	nMax = nTemp;
	while (Permutation_Next10819(nSize, p_nPermutation) == 0)
	{
		nTemp = 0;
		for (int i = 0; i < nSize - 1; i++)
		{
			int nTemp2 = p_nList[p_nPermutation[i]] - p_nList[p_nPermutation[i + 1]];
			if (nTemp2 < 0)
			{
				nTemp2 = -1 * nTemp2;
			}
			nTemp = nTemp + nTemp2;
		}
		if (nMax < nTemp)
		{
			nMax = nTemp;
		}
	}
	printf("%d\n", nMax);
	free(p_nList);
	free(p_nPermutation);
	return 0;
}