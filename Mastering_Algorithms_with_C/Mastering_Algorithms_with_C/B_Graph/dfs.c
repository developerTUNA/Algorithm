#include <stdlib.h>
#include "dfs.h"
#include "graph.h"
#include "../5_Linked_List/list.h"

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