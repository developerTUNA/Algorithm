#include <stdlib.h>
#include "graphalgo.h"
#include "../../DataStructure/Graph/graph.h"
#include "../../DataStructure/List/list.h"

int MST(Graph *graph, const MSTVertex *start, List *span, int(*match)(const void *key1, const void *key2))
{
	AdjList *adjlist = NULL;
	MSTVertex *vertex_mst = NULL;
	MSTVertex *vertex_adj = NULL;
	ListElmt *element = NULL;
	ListElmt *member = NULL;
	int nMin = 0;
	int nFound = 0;
	int nCount = 0;
	
	for (element = ListHead(&GraphAdjLists(graph)); element != NULL; element = ListNext(element))
	{
		vertex_mst = ((AdjList*)ListData(element))->vertex;

		if (match(vertex_mst, start))
		{
			vertex_mst->color = white;
			vertex_mst->nKey = 0;
			vertex_mst->parent = NULL;
			nFound = 1;
		}
		else
		{
			vertex_mst->color = white;
			vertex_mst->nKey = INT_MAX;
			vertex_mst->parent = NULL;
		}
	}
	if (!nFound)
	{
		return -1;
	}

	while (nCount < GraphVcount(graph))
	{
		nMin = INT_MAX;
		for (element = ListHead(&GraphAdjLists(graph)); element != NULL; element = ListNext(element))
		{
			vertex_mst = ((AdjList*)ListData(element))->vertex;
			if (vertex_mst->color == white && vertex_mst->nKey < nMin)
			{
				nMin = vertex_mst->nKey;
				adjlist = ListData(element);
			}
		}
		((MSTVertex*)adjlist->vertex)->color = black;

		for (member = ListHead(&adjlist->Adjacent); member != NULL; member = ListNext(member))
		{
			vertex_adj = ListData(member);

			for (element = ListHead(&GraphAdjLists(graph)); element != NULL; element = ListNext(element))
			{
				vertex_mst = ((AdjList*)ListData(element))->vertex;
				if (match(vertex_mst, vertex_adj))
				{
					if (vertex_mst->color == white && vertex_adj->nWeight < vertex_mst->nKey)
					{
						vertex_mst->nKey = vertex_adj->nWeight;
						vertex_mst->parent = adjlist->vertex;
					}
					break;
				}
			}
		}
		nCount++;
	}

	ListInit(span, NULL);
	for (element = ListHead(&GraphAdjLists(graph)); element != NULL; element = ListNext(element))
	{
		vertex_mst = ((AdjList*)ListData(element))->vertex;
		if (vertex_mst->color == black)
		{
			if (ListInsert_Next(span, ListTail(span), vertex_mst) != 0)
			{
				ListDestory(span);
				return -1;
			}
		}
	}
	return 0;
}