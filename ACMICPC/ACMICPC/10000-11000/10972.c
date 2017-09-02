#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SwapInt10972(int *nA, int *nB)
{
	int nTemp = 0;
	nTemp = *nA;
	*nA = *nB;
	*nB = nTemp;

	return 0;
}

int Permutation_Next10972(int nSize, int *p_nList)
{
	int nFirst = 0;
	int nLast = 0;
	
	for (int i = nSize-1; 1<=i; i--)
	{
		if (p_nList[i - 1] < p_nList[i])
		{
			nFirst = i;
			break;
		}
	}
	if (nFirst == 0)
	{
		return -1;
	}

	for (int i = nSize - 1; nFirst - 1 <= i; i--)
	{
		if (p_nList[nFirst - 1] < p_nList[i])
		{
			nLast = i;
			break;
		}
	}

	SwapInt10972(&p_nList[nFirst-1], &p_nList[nLast]);
	
	for (int i = 0; i < (nSize - nFirst) / 2; i++)
	{
		SwapInt10972(&p_nList[i+nFirst], &p_nList[nSize-1-i]);
	}
	return 0;
}

int Problem10972(void)
{
	int nSize = 0;
	int *p_nList = NULL;

	scanf("%d", &nSize);
	p_nList = (int*)malloc(sizeof(int)*nSize);
	memset(p_nList, 0, sizeof(int)*nSize);

	for (int i = 0; i < nSize; i++)
	{
		scanf("%d", &p_nList[i]);
	}
	
	if (Permutation_Next10972(nSize, p_nList) == -1)
	{
		printf("-1\n");
	}
	else
	{
		for (int i = 0; i < nSize; i++)
		{
			printf("%d ", p_nList[i]);
		}
	}

	free(p_nList);
	return 0;
}