#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct EdgeList13023_
{
	int from;
	int to;
} EdgeList13023;

int QsortCompare13023(const void *key1, const void *key2)
{
	EdgeList13023 Edge1 = *(EdgeList13023*)key1;
	EdgeList13023 Edge2 = *(EdgeList13023*)key2;

	if (Edge1.from < Edge2.from)
	{
		return -1;
	}
	else if (Edge1.from == Edge2.from)
	{
		if (Edge1.to < Edge2.to)
		{
			return -1;
		}
		else if (Edge1.to == Edge2.to)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}

int isFriend(int nA, int nB, EdgeList13023 *EdgeList, int *p_nEdgeCount)
{
	int nStart = 0;
	int nEnd = 0;



	nStart = (nA == 0) ? 0 : p_nEdgeCount[nA - 1];
	nEnd = p_nEdgeCount[nA] - 1;

	for (int i = nStart; i <= nEnd; i++)
	{
		if (EdgeList[i].to == nB)
		{
			return 1;
		}
	}
	return 0;
}

int Problem13023(void)
{
	int nPeople = 0;
	int nConnection = 0;
	int *p_nEdgeCount = NULL;
	EdgeList13023 *EdgeList = NULL;

	scanf("%d %d", &nPeople, &nConnection);
	p_nEdgeCount = malloc(sizeof(int)*nPeople);
	memset(p_nEdgeCount, 0, sizeof(int)*nPeople);
	EdgeList = malloc(sizeof(EdgeList13023)*nConnection * 2);
	memset(EdgeList, 0, sizeof(EdgeList13023)*nConnection * 2);

	for (int i = 0; i < nConnection; i++)
	{
		scanf("%d %d", &EdgeList[i].from, &EdgeList[i].to);
		EdgeList[i + nConnection].from = EdgeList[i].to;
		EdgeList[i + nConnection].to = EdgeList[i].from;
	}

	qsort(EdgeList, nConnection * 2, sizeof(EdgeList13023), QsortCompare13023);
	for (int i = 0; i < nConnection * 2; i++)
	{
		p_nEdgeCount[EdgeList[i].from]++;
	}
	for (int i = 1; i < nPeople; i++)
	{
		p_nEdgeCount[i] = p_nEdgeCount[i - 1] + p_nEdgeCount[i];
	}

	for (int i = 0; i < nConnection * 2; i++)
	{
		for (int j = 0; j < nConnection * 2; j++)
		{
			int nA = EdgeList[i].from;
			int nB = EdgeList[i].to;
			int nC = EdgeList[j].from;
			int nD = EdgeList[j].to;

			if (nA == nB || nA == nC || nA == nD || nB == nC || nB == nD || nC == nD)
			{
				continue;
			}

			if (isFriend(nB, nC, EdgeList, p_nEdgeCount) == 0)
			{
				continue;
			}


			for (int k = (nD == 0) ? 0 : p_nEdgeCount[nD - 1]; k <= p_nEdgeCount[nD] - 1; k++)
			{
				int nE = EdgeList[k].to;
				if (nE == nA || nE == nB || nE == nC || nE == nD)
				{
					continue;
				}
				else
				{
					printf("1\n");
					free(p_nEdgeCount);
					free(EdgeList);
					return 0;
				}

			}
		}
	}

	printf("0\n");
	free(p_nEdgeCount);
	free(EdgeList);

	return 0;
}
