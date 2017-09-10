#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SwapInt06603(int *nA, int *nB)
{
	int nTemp = 0;
	nTemp = *nA;
	*nA = *nB;
	*nB = nTemp;
	return 0;
}

int Permutation_Next06603(int nSize, int *p_nList)
{
	int nSwap1 = 0;
	int nSwap2 = 0;

	for (int i = nSize-1; 0<i; i--)
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

	for (int i = nSize - 1; nSwap1 - 1 <= i; i--)
	{
		if (p_nList[nSwap1 - 1] < p_nList[i])
		{
			nSwap2 = i;
			break;
		}
	}

	SwapInt06603(&p_nList[nSwap1 - 1], &p_nList[nSwap2]);

	nSwap2 = nSize - 1;
	while (nSwap1 < nSwap2)
	{
		SwapInt06603(&p_nList[nSwap1], &p_nList[nSwap2]);
		nSwap1++;
		nSwap2--;
	}
	return 0;
}

int Problem06603(void)
{
	int nSize = 0;
	int *p_nList = 0;
	int *p_nSelect = 0;

	while(1)
	{
		scanf("%d", &nSize);
		if (nSize == 0)
		{
			break;
		}
		p_nList = (int*)malloc(sizeof(int)*nSize);
		memset(p_nList, 0, sizeof(int)*nSize);
		p_nSelect = (int*)malloc(sizeof(int)*nSize);
		memset(p_nSelect, 0, sizeof(int)*nSize);

		for (int i = 0; i < nSize; i++)
		{
			scanf("%d", &p_nList[i]);
		}

		for (int i = 6; i < nSize; i++)
		{
			p_nSelect[i] = 1;
		}

		do
		{
			for (int i = 0; i < nSize; i++)
			{
				if(p_nSelect[i]==0)
				{
					printf("%d ", p_nList[i]);
				}
			}
			printf("\n");
		} while (Permutation_Next06603(nSize, p_nSelect)==0);
		printf("\n");
		free(p_nList);
		free(p_nSelect);
	}
	return 0;
}