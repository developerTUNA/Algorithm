#ifndef GRAPHALGO_H
#define GRAPHALGO_H
#include "../../DataStructure/Graph/graph.h"
#include "../../DataStructure/List/list.h"

typedef struct MSTVertex_
{
	void *data;
	int nWeight;
	VertexColor color;
	int nKey;
	struct MSTVertex_ *parent;
}MSTVertex;

typedef struct PathVertex_
{
	void *data;
	int nWeight;
	VertexColor color;
	int nDistance;
	struct PathVertex_ *parent;
}PathVertex;

typedef struct TSPVertex_
{
	void *data;
	double dX;
	double dY;
	VertexColor color;
}TSPVertex;

int MST_Prim(Graph *graph, const MSTVertex *start, List *span, int(*match)(const void *key1, const void *key2));
int ShortPath_Dijkstra(Graph *graph, const PathVertex *start, List *path, int(*match)(const void *key1, const void *key2));
int TSP(List *vertex, const TSPVertex *start, List *tour, int(*match)(const void *key1, const void *key2));

#endif