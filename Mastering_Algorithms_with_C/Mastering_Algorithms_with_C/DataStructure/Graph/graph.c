#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "../List/list.h"
#include "../Sets/set.h"

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
			if (graph->destory != NULL)
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

int GraphInsert_Vertex(Graph *graph, const void *data)
{
	ListElmt *element = NULL;
	AdjList *adjlist = NULL;
	int nReturn = 0;

	for (element = ListHead(&graph->AdjLists); element != NULL; element = ListNext(element))
	{
		if (graph->match(data, ((AdjList*)ListData(element))->vertex))
		{
			return 1;
		}
	}

	if ((adjlist = (AdjList*)malloc(sizeof(AdjList))) == NULL)
	{
		return -1;
	}

	adjlist->vertex = (void*)data;
	SetInit(&adjlist->Adjacent, graph->match, NULL);

	if ((nReturn = ListInsert_Next(&graph->AdjLists, ListTail(&graph->AdjLists), adjlist)) != 0)
	{
		return nReturn;
	}
	graph->n_Vcount++;

	return 0;
}

int GraphInsert_Edge(Graph *graph, const void *data1, const void *data2)
{
	ListElmt *element = NULL;
	int nReturn = 0;

	for (element = ListHead(&graph->AdjLists); element != NULL; element = ListNext(element))
	{
		if (graph->match(data2, ((AdjList*)ListData(element))->vertex))
		{
			break;
		}
	}
	if (element == NULL)
	{
		return -1;
	}

	for (element = ListHead(&graph->AdjLists); element != NULL; element = ListNext(element))
	{
		if (graph->match(data1, ((AdjList*)ListData(element))->vertex))
		{
			break;
		}
	}
	if (element == NULL)
	{
		return -1;
	}

	if ((nReturn = SetInsert(&((AdjList *)ListData(element))->Adjacent, data2)) != 0)
	{
		return nReturn;
	}

	graph->n_Ecount++;

	return 0;
}

int GraphRemove_Vertex(Graph *graph, void **data)
{
	ListElmt *element = NULL;
	ListElmt *temp = NULL;
	ListElmt *prev = NULL;
	AdjList *adjlist = NULL;
	int nFound = 0;

	for (element = ListHead(&graph->AdjLists); element != NULL; element = ListNext(element))
	{
		if (SetisMember(&((AdjList *)ListData(element))->Adjacent, *data))
		{
			return -1;
		}
		if (graph->match(*data, ((AdjList*)ListData(element))->vertex))
		{
			temp = element;
			nFound = 1;
		}
		if (!nFound)
		{
			prev = element;
		}
	}

	if (!nFound)
	{
		return -1;
	}

	if (SetSize(&((AdjList*)ListData(temp))->Adjacent) > 0)
	{
		return -1;
	}
	if (ListRemove_Next(&graph->AdjLists, prev, (void**)&adjlist) != 0)
	{
		return -1;
	}

	*data = adjlist->vertex;
	free(adjlist);

	graph->n_Vcount--;
	return 0;
}

int GraphRemove_Edge(Graph *graph, void *data1, void **data2)
{
	ListElmt *element = NULL;

	for (element = ListHead(&graph->AdjLists); element != NULL; element = ListNext(element))
	{
		if (graph->match(data1, ((AdjList*)ListData(element))->vertex))
		{
			break;
		}
	}
	if (element == NULL)
	{
		return -1;
	}

	if (SetRemove(&((AdjList*)ListData(element))->Adjacent, data2) != 0)
	{
		return -1;
	}

	graph->n_Ecount--;

	return 0;
}

int GraphAdjList(const Graph *graph, const void *data, AdjList **adjlist)
{
	ListElmt *element = NULL;
	ListElmt *prev = NULL;

	for (element = ListHead(&graph->AdjLists); element != NULL; element = ListNext(element))
	{
		if (graph->match(data, ((AdjList*)ListData(element))->vertex))
		{
			break;
		}
		prev = element;
	}

	if (element == NULL)
	{
		return -1;
	}

	*adjlist = ListData(element);

	return 0;
}

GraphIsAdjacent(const Graph *graph, const void *data1, const void *data2)
{
	ListElmt *element = NULL;
	ListElmt *prev = NULL;

	for (element = ListHead(&graph->AdjLists); element != NULL; element = ListNext(element))
	{
		if (graph->match(data1, ((AdjList*)ListData(element))->vertex))
		{
			break;
		}
		prev = element;
	}

	if (element == NULL)
	{
		return 0;
	}

	return SetisMember(&((AdjList*)ListData(element))->Adjacent, data2);
}