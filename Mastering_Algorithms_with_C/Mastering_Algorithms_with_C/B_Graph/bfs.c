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
		QueueDestroy(&queue);
		return -1;
	}

	while (QueueSize(&queue) > 0)
	{
		adjlist = QueuePeek(&queue);
		for (member = ListHead(&adjlist->Adjacent); member != NULL; member = ListNext(member))
		{
			vertex_Adj = ListData(member);

			if (GraphAdjList(graph, vertex_Adj, &adjlist_Clear))
			{
				QueueDestroy(&queue);
				return -1;
			}
			vertex_Clear = adjlist_Clear->vertex;

			if (vertex_Clear->color == white)
			{
				vertex_Clear->color = gray;
				vertex_Clear->nHops = ((BFSVertex*)adjlist->vertex)->nHops + 1;

				if (QueueEnqueue(&queue, adjlist_Clear) != 0)
				{
					QueueDestroy(&queue);
					return -1;
				}
			}
		}
		if (QueueDequeue(&queue, (void**)&adjlist) == 0)
		{
			((BFSVertex*)adjlist->vertex)->color = black;
		}
		else
		{
			QueueDestroy(&queue);
			return -1;
		}
	}
	QueueDestroy(&queue);

	ListInit(hops, NULL);
	for (element = ListHead(&GraphAdjLists(graph)); element != NULL; element = ListNext(element))
	{
		vertex_Clear = ((AdjList*)ListData(element))->vertex;
		if (vertex_Clear->nHops != -1)
		{
			if (ListInsert_Next(hops, ListTail(hops), vertex_Clear) != 0)
			{
				ListDestory(hops);
				return -1;
			}
		}
	}

	return 0;
}