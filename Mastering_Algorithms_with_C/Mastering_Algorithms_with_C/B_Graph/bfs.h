#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include "../5_Linked_List/list.h"

typedef struct BFSVertex_
{
	void *data;
	VertexColor color;
	int nHops;
} BFSVertex;

int BFS(Graph *graph, BFSVertex *start, List *hops);

#endif