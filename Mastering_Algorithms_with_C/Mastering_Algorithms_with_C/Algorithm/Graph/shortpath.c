#include <stdlib.h>
#include "graphalgo.h"
#include "../../DataStructure/Graph/graph.h"
#include "../../DataStructure/List/list.h"
#include "../../DataStructure/Sets/set.h"

static void relax(PathVertex *vertex1, PathVertex *vertex2, int nWeight)
{
	if (vertex1->nDestance + nWeight < vertex2->nDestance)
	{
		vertex2->nDestance = vertex1->nDestance + nWeight;
		vertex2->parent = vertex1;
	}
	return;
}

int ShortPath_Dijkstra(Graph *graph, const PathVertex *start, List *path, int(*match)(const void *key1, const void *key2))
{
	AdjList *adjlist = NULL;
	PathVertex *vertex_path = NULL;
	PathVertex *vertex_adj = NULL;
	ListElmt *element = NULL;
	ListElmt *member = NULL;
	int nMin = 0;
	int nFound = 0;
	
	for (element = ListHead(&GraphAdjLists(graph)); element != NULL; element = ListNext(element))
	{
		vertex_path = ((AdjList*)ListData(element))->vertex;

		if (match(vertex_path, start))
		{
			vertex_path->color = white;
			vertex_path->nDestance = 0;
			vertex_path->parent = NULL;
			nFound = 1;
		}
		else
		{
			vertex_path->color = white;
			vertex_path->nDestance = INT_MAX;
			vertex_path->parent = NULL;
		}
	}
	if (!nFound)
	{
		return -1;
	}

}