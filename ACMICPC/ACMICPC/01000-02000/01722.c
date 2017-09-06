#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Permutation_GetList01722(int nSize, long long lOrder, int *p_nList)
{
	int nFact = 0;
	int *p_nDigit = NULL;
	long long *p_lFact = NULL;
	p_lFact = (long long*)malloc(sizeof(long long)*nSize);
	memset(p_lFact, 0, sizeof(long long)*nSize);

	p_nDigit = (int*)malloc(sizeof(int)*(nSize + 1));
	memset(p_nDigit, 0, sizeof(int)*(nSize + 1));

	p_lFact[nSize - 1] = 1;
	nFact = 1;
	for (int i = nSize - 2; 0 <= i; i--)
	{
		p_lFact[i] = p_lFact[i + 1] * nFact;
		nFact++;
	}

	for (int i = 0; i < nSize; i++)
	{
		int nTemp = 1;

		for (int j = 1; j <= nSize; j++)
		{
			if (p_nDigit[j] == 1)
			{
				nTemp++;
				continue;
			}
			if (p_lFact[i] < lOrder)
			{
				lOrder -= p_lFact[i];
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

	free(p_lFact);
	free(p_nDigit);
	return 0;
}

int Permutation_GetOrder01722(int nSize, long long *nOrder, int *p_nList)
{
	int nFact = 0;
	long long nResult = 0;
	long long *p_lFact = NULL;
	int *p_nDigit = NULL;
	p_lFact = (long long*)malloc(sizeof(long long)*nSize);
	memset(p_lFact, 0, sizeof(long long)*nSize);

	p_nDigit = (int*)malloc(sizeof(int)*(nSize + 1));
	memset(p_nDigit, 0, sizeof(int)*(nSize + 1));

	p_lFact[nSize - 1] = 1;
	nFact = 1;
	for (int i = nSize - 2; 0 <= i; i--)
	{
		p_lFact[i] = p_lFact[i + 1] * nFact;
		nFact++;
	}

	for (int i = 0; i < nSize; i++)
	{
		int nTemp = 1;

		for (int j = 1; j <= nSize; j++)
		{
			if (p_nDigit[j] == 1)
			{
				nTemp++;
				continue;
			}
			if (nTemp < p_nList[i])
			{
				nResult += p_lFact[i];
				nTemp++;
			}
			else
			{
				break;
			}
		}
		p_nDigit[nTemp] = 1;
	}

	*nOrder = nResult + 1;
	free(p_lFact);
	free(p_nDigit);
	return 0;
}

int Problem01722(void)
{
	int nSize = 0;
	int nProblem = 0;
	long long lOrder = 0;
	int *p_nList = NULL;

	scanf("%d", &nSize);
	scanf("%d", &nProblem);
	p_nList = (int*)malloc(sizeof(int)*nSize);
	memset(p_nList, 0, sizeof(int)*nSize);

	if (nProblem == 1)
	{
		scanf("%lld", &lOrder);
		Permutation_GetList01722(nSize, lOrder, p_nList);

		for (int i = 0; i < nSize; i++)
		{
			printf("%d ", p_nList[i]);
		}
		printf("\n");
	}
	else if (nProblem == 2)
	{
		for (int i = 0; i < nSize; i++)
		{
			scanf("%d", &p_nList[i]);
		}
		Permutation_GetOrder01722(nSize, &lOrder, p_nList);
		printf("%lld\n", lOrder);
	}

	free(p_nList);
	return 0;
}