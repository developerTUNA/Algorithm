#include <float.h>
#include <stdlib.h>
#include <math.h>
#include "../../DataStructure/List/list.h"
#include "../../DataStructure/Graph/graph.h"
#include "graphalgo.h"

int TSP(List *vertex, const TSPVertex *start, List *tour, int(*match)(const void *key1, const void *key2))
{
	TSPVertex *vertex_TSP = NULL;
	TSPVertex *vectex_start = NULL;
	TSPVertex *select = NULL;
	ListElmt *element = NULL;
	int nFound = 0;
	int nCount = 0;
	double dDistance = 0;
	double dMin = 0;
	double dX = 0;
	double dY = 0;
	

	ListInit(tour, NULL);
	
	for(element = ListHead(vertex);element != NULL; element = ListNext(element))
	{
		vertex_TSP = ListData(element);
		if (match(vertex_TSP, start))
		{
			if (ListInsert_Next(tour, ListTail(tour), vertex_TSP) != 0)
			{
				ListDestory(tour);
				return -1;
			}

			vectex_start = vertex_TSP;
			dX = vertex_TSP->dX;
			dY = vertex_TSP->dY;
			vertex_TSP->color = black;
			nFound = 1;
		}
		else
		{
			vertex_TSP->color = white;
		}
	}

	if (!nFound)
	{
		ListDestory(tour);
		return -1;
	}

	while (nCount < ListSize(vertex) - 1)
	{
		dMin = DBL_MAX;
		for (element = ListHead(vertex); element != NULL; element = ListNext(element))
		{
			vertex_TSP = ListData(element);

			if (vertex_TSP->color == white)
			{
				dDistance = sqrt(pow(vertex_TSP->dX - dX, 2) + pow(vertex_TSP->dY - dY, 2));
				if (dDistance < dMin)
				{
					dMin = dDistance;
					select = vertex_TSP;
				}
			}
		}

		dX = select->dX;
		dY = select->dY;
		select->color = black;

		if (ListInsert_Next(tour, ListTail(tour), select) != 0)
		{
			ListDestory(tour);
			return -1;
		}
		nCount++;
	}

	if (ListInsert_Next(tour, ListTail(tour), vectex_start) != 0)
	{
		ListDestory(tour);
		return -1;
	}

	return 0;
}