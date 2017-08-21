#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include "../05_Linked_List/list.h"
#include "../07_Sets/set.h"

typedef struct AdjList_
{
	void *vertex;
	Set Adjacent;
}AdjList;

typedef struct Graph_
{
	int n_Vcount;
	int n_Ecount;
	int(*match)(const void *key1, const void *key2);
	void(*destory)(void *data);
	List AdjLists;
}Graph;

typedef enum VertexColor_ { white, gray, black } VertexColor;
void GraphInit(Graph *graph, int(*match)(const void *key1, const void *key2), void(*destory)(void *data));
void GraphDestory(Graph *graph);
int GraphInsert_Vertex(Graph *graph, const void *data);
int GraphInsert_Edge(Graph *graph, const void *data1, const void *data2);
int GraphRemove_Vertex(Graph *graph, void **data);
int GraphRemove_Edge(Graph *graph, void *data1, void **data2);
int GraphAdjList(const Graph *graph, const void *data, AdjList **adjlist);
int GraphIsAdjacent(const Graph *graph, const void *data1, const void *data2);
#define GraphAdjLists(graph)((graph)->AdjLists)
#define GraphVcount(graph)(graph)->n_Vcount)
#define GraphEcount(graph)(graph)->n_Ecount)

#endif GRAPH_H