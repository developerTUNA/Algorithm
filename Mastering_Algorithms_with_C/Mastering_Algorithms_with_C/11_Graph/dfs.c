#include <stdlib.h>
#include "dfs.h"
#include "graph.h"
#include "../05_Linked_List/list.h"

static int DFS_main(Graph *graph, AdjList *adjlist, List *ordered)
{
	AdjList *adjlist_Clear = NULL;
	DFSVertex *vertex_Clear = NULL;
	DFSVertex *vertex_Adj = NULL;
	ListElmt *member = NULL;

	((DFSVertex*)adjlist->vertex)->color = gray;

	for (member = ListHead(&adjlist->Adjacent); member != NULL; member = ListNext(member))
	{
		vertex_Adj = ListData(member);
		if (GraphAdjList(graph, vertex_Adj, &adjlist_Clear) != 0)
		{
			return -1;
		}

		vertex_Clear = adjlist_Clear->vertex;

		if (vertex_Clear->color == white)
		{
			if (DFS_main(graph, adjlist_Clear, ordered) != 0)
			{
				return -1;
			}
		}
	}

	((DFSVertex*)adjlist->vertex)->color = black;

	if (ListInsert_Next(ordered, NULL, (DFSVertex*)adjlist->vertex) != 0)
	{
		return -1;
	}

	return 0;
}

int DFS(Graph *graph, List *ordered)
{
	DFSVertex *vertex = NULL;
	ListElmt *element = NULL;

	for (element = ListHead(&GraphAdjLists(graph)); element != NULL; element = ListNext(element))
	{
		vertex = ((AdjList *)ListData(element))->vertex;
		vertex->color = white;
	}
	ListInit(ordered, NULL);
	for (element = ListHead(&GraphAdjLists(graph)); element != NULL; element = ListNext(element))
	{
		vertex = ((AdjList*)ListData(element))->vertex;

		if (vertex->color == white)
		{
			if (DFS_main(graph, (AdjList*)ListData(element), ordered) != 0)
			{
				ListDestory(ordered);
				return -1;
			}
		}
	}

	return 0;
}