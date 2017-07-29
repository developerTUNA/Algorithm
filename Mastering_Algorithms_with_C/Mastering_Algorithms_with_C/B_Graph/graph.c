#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "../5_Linked_List/list.h"
#include "../7_Sets/set.h"

void GraphInit(Graph *graph, int(*match)(const void *key1, const void *key2), void(*destory)(void *data))
{
	graph->n_Vcount = 0;
	graph->n_Ecount = 0;
	graph->match = match;
	graph->destory = destory;
	ListInit(&graph->AdjLists, NULL);

	return;
}

void GraphDestory(Graph *graph)
{
	AdjList *adjlist;

	while (ListSize(&graph->AdjLists) > 0)
	{
		if (ListRemove_Next(&graph->AdjLists, NULL, (void**)&adjlist) == 0)
		{
			SetDestory(&adjlist->Adjacent);
			if(graph->destory != NULL)
			{
				graph->destory(adjlist->vertex);
			}
			free(adjlist);
		}
	}

	ListDestory(&graph->AdjLists);
	memset(graph, 0, sizeof(Graph));
	return;
}