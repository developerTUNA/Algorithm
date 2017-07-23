#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct EdgeList01707_
{
	int nFrom;
	int nTo;
}EdgeList01707;

int EdgeListCmp01707(const void *cv_key1, const void *cv_key2)
{
	EdgeList01707 key1 = *(EdgeList01707*)cv_key1;
	EdgeList01707 key2 = *(EdgeList01707*)cv_key2;

	if (key1.nFrom < key2.nFrom)
	{
		return -1;
	}
	else if (key1.nFrom == key2.nFrom)
	{
		if (key1.nTo < key2.nTo)
		{
			return -1;
		}
		else if (key1.nTo == key2.nTo)
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

int DFSColor01707(int nEdge, int nVertex, int *p_nEdgeList_cnt, EdgeList01707 *p_edgeList)
{
	int nResult = 1;
	int nNow = 0;
	int nStackTop = 0;
	int *p_nCheck = NULL;
	int *p_nStack = NULL;
	int *p_nVertexColor = NULL;

	p_nCheck = (int *)malloc(sizeof(int)*(nVertex+1));
	memset(p_nCheck, 0, sizeof(int)*(nVertex+1));
	p_nStack = (int *)malloc(sizeof(int)*(nVertex + 1));
	memset(p_nStack, 0, sizeof(int)*(nVertex + 1));
	p_nVertexColor = (int *)malloc(sizeof(int)*(nVertex + 1));
	memset(p_nVertexColor, 0, sizeof(int)*(nVertex + 1));
	
	
	for (int i = 1; i <= nVertex; i++)
	{
		if (p_nCheck[i] != 0)
		{
			continue;
		}
		nNow = i;
		nStackTop = 0;
		p_nStack[nStackTop] = nNow;
		p_nCheck[nNow] = 1;
		while(0<= nStackTop)
		{

			int nNext = 0;
			for (int j = p_nEdgeList_cnt[nNow - 1]; j < p_nEdgeList_cnt[nNow]; j++)
			{
				if (p_nCheck[p_edgeList[j].nTo] == p_nCheck[nNow])
				{
					nResult = 0;
					break;
				}
				else if (p_nCheck[p_edgeList[j].nTo] == 0)
				{
					nNext = p_edgeList[j].nTo;
					break;
				}
			}
			if (nResult == 0)
			{
				break;
			}
			if (nNext == 0)
			{
				p_nStack[nStackTop] = 0;
				nStackTop--;
				if(0<=nStackTop)
				{
					nNow = p_nStack[nStackTop];
				}
			}
			else
			{
				nStackTop++;
				p_nStack[nStackTop] = nNext;
				p_nCheck[nNext] = 3 - p_nCheck[nNow];
				nNow = nNext;
			}
		}

		if (nResult == 0)
		{
			break;
		}
	}
	return nResult;
}

int Problem01707(void)
{
	int nTestCase = 0;
	int nVertex = 0;
	int nEdge = 0;
	int *p_nEdgeList_cnt = NULL;
	EdgeList01707 *p_edgeList = NULL;

	scanf("%d", &nTestCase);
	for (int i = 0; i < nTestCase; i++)
	{
		scanf("%d %d", &nVertex, &nEdge);
		p_edgeList = (EdgeList01707 *)malloc(sizeof(EdgeList01707)*(nEdge*2));
		memset(p_edgeList, 0, (sizeof(EdgeList01707)*(nEdge*2)));
		for (int j = 0; j < nEdge; j++)
		{
			scanf("%d %d", &p_edgeList[j].nFrom, &p_edgeList[j].nTo);
			p_edgeList[j + nEdge].nFrom = p_edgeList[j].nTo;
			p_edgeList[j + nEdge].nTo = p_edgeList[j].nFrom;
		}
		qsort(p_edgeList, nEdge*2, sizeof(EdgeList01707), EdgeListCmp01707);

		p_nEdgeList_cnt = (int *)malloc(sizeof(int)*(nVertex + 1));
		memset(p_nEdgeList_cnt, 0, sizeof(int)*(nVertex + 1));

		for (int j = 0; j < nEdge*2; j++)
		{
			p_nEdgeList_cnt[p_edgeList[j].nFrom]++;
		}
		for (int j = 1; j <= nVertex; j++)
		{
			p_nEdgeList_cnt[j] = p_nEdgeList_cnt[j - 1] + p_nEdgeList_cnt[j];
		}

		if (DFSColor01707(nEdge, nVertex, p_nEdgeList_cnt, p_edgeList) == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		free(p_edgeList);
		free(p_nEdgeList_cnt);
	}
	return 0;
}