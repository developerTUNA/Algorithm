#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct p_edgeList11724_
{
	int from;
	int to;
}p_edgeList11724;

int QuickSortCmp11724(const void *key1, const void *key2)
{
	p_edgeList11724 Edge1 = *(p_edgeList11724*)key1;
	p_edgeList11724 Edge2 = *(p_edgeList11724*)key2;

	if (Edge2.from < Edge1.from)
	{
		return 1;
	}
	else if (Edge2.from == Edge1.from)
	{
		if (Edge2.to < Edge1.to)
		{
			return 1;
		}
	}

	return 0;
}

int Problem11724(void)
{
	int nNode = 0;
	int nEdge = 0;
	int nGraph = 0;
	int *p_nNodeCheck = NULL;
	int *p_nEdgeCount = NULL;
	p_edgeList11724 *p_edgeList = NULL;

	scanf("%d %d", &nNode, &nEdge);
	p_nNodeCheck = malloc(sizeof(int)*(nNode+1));
	memset(p_nNodeCheck, 0, sizeof(int)*(nNode+1));
	p_nEdgeCount = malloc(sizeof(int)*(nNode + 1));
	memset(p_nEdgeCount, 0, sizeof(int)*(nNode + 1));
	p_edgeList = malloc(sizeof(p_edgeList11724)*(nEdge*2));
	memset(p_edgeList, 0, sizeof(p_edgeList11724)*(nEdge*2));

	for (int i = 0; i < nEdge; i++)
	{
		scanf("%d %d", &p_edgeList[i].from, &p_edgeList[i].to);
		p_edgeList[i + nEdge].from = p_edgeList[i].to;
		p_edgeList[i + nEdge].to = p_edgeList[i].from;
	}

	qsort(p_edgeList, nEdge * 2, sizeof(p_edgeList11724), QuickSortCmp11724);

	for (int i = 0; i < nEdge * 2; i++)
	{
		p_nEdgeCount[p_edgeList[i].from]++;
	}

	for (int i = 1; i <= nNode; i++)
	{
		p_nEdgeCount[i] = p_nEdgeCount[i - 1] + p_nEdgeCount[i];
	}

	for (int i = 1; i <= nNode; i++)
	{
		if (p_nNodeCheck[i] == 0)
		{
			nGraph++;
			p_nNodeCheck[i] = nGraph;

			int nStackTop = 0;
			int nNow = i;
			int *p_nStack = NULL;
			p_nStack = malloc(sizeof(int)*(nNode));
			memset(p_nStack, 0, sizeof(int)*(nNode));

			p_nStack[nStackTop] = nNow;
			while (0 <= nStackTop)
			{
				int nNext = 0;
				for (int j = p_nEdgeCount[nNow - 1]; j < p_nEdgeCount[nNow]; j++)
				{
					if (p_nNodeCheck[p_edgeList[j].to] == 1)
					{
						continue;
					}
					else
					{
						nNext = p_edgeList[j].to;
						break;
					}
				}
				if (nNext == 0)
				{
					p_nStack[nStackTop] = 0;
					nStackTop--;
					if (0 <= nStackTop)
					{
						nNow = p_nStack[nStackTop];
					}
					continue;
				}
				else
				{
					nStackTop++;
					p_nStack[nStackTop] = nNext;
					p_nNodeCheck[nNext] = 1;
					nNow = nNext;
				}
			}
			free(p_nStack);
		}
		else
		{
			continue;
		}
	}

	printf("%d\n", nGraph);

	free(p_edgeList);
	free(p_nNodeCheck);
	free(p_nEdgeCount);
	return 0;
}
