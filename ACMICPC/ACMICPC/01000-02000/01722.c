#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Permutation_GetList01722(int nSize, int nOrder, int *p_nList)
{
	int nFact = 0;
	int *p_nFact = NULL;
	int *p_nDigit = NULL;
	p_nFact = (int*)malloc(sizeof(int)*nSize);
	memset(p_nFact, 0, sizeof(int)*nSize);

	p_nDigit = (int*)malloc(sizeof(int)*(nSize + 1));
	memset(p_nDigit, 0, sizeof(int)*(nSize + 1));

	p_nFact[nSize - 1] = 1;
	nFact = 1;
	for (int i = nSize - 2; 0 <= i; i--)
	{
		p_nFact[i] = p_nFact[i + 1] * nFact;
		nFact++;
	}

	for (int i = 0; i < nSize; i++)
	{
		int nTemp = 1;

		for (int j = 1; j < nSize; j++)
		{
			if (p_nDigit[j] == 1)
			{
				nTemp++;
				continue;
			}
			if (p_nFact[i] < nOrder)
			{
				nOrder -= p_nFact[i];
				nTemp++;
			}
			else
			{
				break;
			}
		}
		p_nDigit[nTemp] = 1;
		p_nList[i] = nTemp;
	}

	free(p_nFact);
	free(p_nDigit);
	return 0;
}

int Permutation_GetOrder01722(int nSize, int *nOrder, int *p_nList)
{

}


int Problem01722(void)
{
	int nSize = 0;
	int nProblem = 0;
	int *p_nList = NULL;

	scanf("%d", &nSize);
	scanf("%d", &nProblem);
	p_nList = (int*)malloc(sizeof(int)*nSize);
	memset(p_nList, 0, sizeof(int)*nSize);

	if (nProblem == 1)
	{
		int nOrder = 0;
		scanf("%d", &nOrder);
		Permutation_GetList01722(nSize, nOrder, p_nList);
	}
	else if (nProblem == 2)
	{

	}

	free(p_nList);
	return 0;
}