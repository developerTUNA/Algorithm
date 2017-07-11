#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct EdgeList01260_
{
	int from;
	int to;
} EdgeList01260;

int QsortCompare01260(const void *key1, const void *key2)
{
	EdgeList01260 Edge1 = *(EdgeList01260*)key1;
	EdgeList01260 Edge2 = *(EdgeList01260*)key2;

	if (Edge2.from < Edge1.from)
	{
		return 1;
	}
	else if (Edge1.from == Edge2.from)
	{
		if (Edge2.to < Edge1.to)
		{
			return 1;
		}
		else if (Edge2.to == Edge1.to)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}

int DFS01260(EdgeList01260 *p_edgeList, int *p_nEdgeCount, int nNode, int nEdge, int nStart)
{
	int *p_nCheck = NULL;
	int *p_nStack = NULL;
	int nStackDeep = 0;
	int nNow = 0;
	
	p_nCheck = malloc(sizeof(int)*(nNode+1));
	memset(p_nCheck, 0, sizeof(int)*(nNode+1));
	p_nStack = malloc(sizeof(int)*(nNode));
	memset(p_nStack, 0, sizeof(int)*(nNode));

	nStackDeep = 0;
	p_nStack[0] = nStart;
	p_nCheck[nStart] = 1;
	printf("%d ", nStart);
	nNow = nStart;

	while (0 <= nStackDeep)
	{
		int nNext = 0;
		for (int i = p_nEdgeCount[nNow-1]; i < p_nEdgeCount[nNow]; i++)
		{
			if (p_nCheck[p_edgeList[i].to] == 1)
			{
				continue;
			}
			else
			{
				nNext = p_edgeList[i].to;
				break;
			}
		}
		if (nNext == 0)
		{
			p_nStack[nStackDeep] = 0;
			nStackDeep--;
			if (0 <= nStackDeep)
			{
				nNow = p_nStack[nStackDeep];
			}
			continue;
		}
		else
		{
			printf("%d ", nNext);
			nStackDeep++;
			p_nStack[nStackDeep] = nNext;
			p_nCheck[nNext] = 1;
			nNow = nNext;
		}
	}

	free(p_nCheck);
	free(p_nStack);
	return 0;
}

typedef struct LinkedList01260_
{
	int nData;
	struct LinkedList01260_ *next;
}LinkedList01260;

int BFS01260(EdgeList01260 *p_degeList, int *p_nEdgeCount, int nNode, int nEdge, int nStart)
{
	int *p_nCheck = NULL;
	LinkedList01260 *queueHead = NULL;
	LinkedList01260 *queueTail = NULL;
	LinkedList01260 *queueTail_Before = NULL;
	int nQueueSize = 0;
	int nNow = 0;

	p_nCheck = malloc(sizeof(int)*(nNode + 1));
	memset(p_nCheck, 0, sizeof(int)*(nNode + 1));
	queueHead = malloc(sizeof(LinkedList01260));
	memset(queueHead, 0, sizeof(LinkedList01260));

	queueHead->nData = nStart;
	queueHead->next = NULL;
	nQueueSize = 1;
	nNow = nStart;
	p_nCheck[nNow] = 1;
	queueTail = queueHead;
	printf("%d ", nStart);

	while (queueHead != NULL)
	{
		LinkedList01260 *removeList = NULL;
		removeList = queueHead;
		nNow = queueHead->nData;
		queueHead = queueHead->next;
		free(removeList);
		if (queueHead == NULL)
		{
			queueTail = NULL;
		}

		for (int i = p_nEdgeCount[nNow - 1]; i < p_nEdgeCount[nNow]; i++)
		{
			int nEnqueData = p_degeList[i].to;
			if (p_nCheck[nEnqueData] == 1)
			{
				continue;
			}
			else
			{
				p_nCheck[nEnqueData] = 1;
				printf("%d ", nEnqueData);
				LinkedList01260 *addList = NULL;
				addList = malloc(sizeof(LinkedList01260));
				addList->nData = nEnqueData;
				addList->next = NULL;
				if (queueHead == NULL)
				{
					queueHead = addList;
					queueTail = addList;
				}
				else
				{
					queueTail->next = addList;
					queueTail = addList;
				}
			}
		}
	}

	return 0;
}

int Problem01260(void)
{
	int nNode = 0;
	int nEdge = 0;
	int nStart = 0;
	EdgeList01260 *p_edgeList = NULL;
	int *p_nEdgeCount = NULL;

	scanf("%d %d %d", &nNode, &nEdge, &nStart);

	p_edgeList = malloc(sizeof(EdgeList01260)*(nEdge * 2));
	memset(p_edgeList, 0, sizeof(EdgeList01260)*(nEdge * 2));
	p_nEdgeCount = malloc(sizeof(int)*(nNode+1));
	memset(p_nEdgeCount, 0, sizeof(int)*(nNode+1));

	for (int i = 0; i < nEdge; i++)
	{
		scanf("%d %d", &p_edgeList[i].from, &p_edgeList[i].to);
		p_edgeList[i + nEdge].from = p_edgeList[i].to;
		p_edgeList[i + nEdge].to = p_edgeList[i].from;
	}
	
	qsort(p_edgeList, nEdge * 2, sizeof(EdgeList01260), QsortCompare01260);

	for (int i = 0; i < nEdge*2; i++)
	{
		p_nEdgeCount[p_edgeList[i].from]++;
	}
	for (int i = 1; i <= nNode; i++)
	{
		p_nEdgeCount[i] = p_nEdgeCount[i - 1] + p_nEdgeCount[i];
	}

	//DFS
	DFS01260(p_edgeList, p_nEdgeCount, nNode, nEdge, nStart);
	printf("\n");
	BFS01260(p_edgeList, p_nEdgeCount, nNode, nEdge, nStart);

	free(p_edgeList);
	free(p_nEdgeCount);
	return 0;
}