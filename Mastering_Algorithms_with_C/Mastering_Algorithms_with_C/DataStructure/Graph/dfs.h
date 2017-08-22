#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include "../List/list.h"

typedef struct DFSVertex_
{
	void *data;
	VertexColor color;
} DFSVertex;

int DFS(Graph *graph, List *ordered);

#endif
