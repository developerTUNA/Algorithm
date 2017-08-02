#include <stdlib.h>
#include "bfs.h"
#include "graph.h"
#include "../5_Linked_List/list.h"
#include "../6_Stack_Queue/queue.h"

int BFS(Graph *graph, BFSVertex *start, List *hops)
{
	Queue queue;
	AdjList *adjlist = NULL;
	AdjList *adjlist_Clear = NULL;
	BFSVertex *vertex_Clear = NULL;
	BFSVertex *vertex_Adj = NULL;
	ListElmt *element = NULL;
	ListElmt *member = NULL;

	for (element = ListHead(&GraphAdjLists(graph)); element != NULL; element = ListNext(element))
	{
		vertex_Clear = ((AdjList*)ListData(element))->vertex;
		if (graph->match(vertex_Clear, start))
		{
			vertex_Clear->color = gray;
			vertex_Clear->nHops = 0;
		}
		else
		{
			vertex_Clear->color = white;
			vertex_Clear->nHops = -1;
		}
	}

	QueueInit(&queue, NULL);
	if (GraphAdjList(graph, start, &adjlist_Clear) != 0)
	{
		QueueDestroy(&queue);
		return -1;
	}
	if (QueueEnqueue(&queue, adjlist_Clear) != 0)
	{
		QueueDestory(&queue);
		return -1;
	}


}