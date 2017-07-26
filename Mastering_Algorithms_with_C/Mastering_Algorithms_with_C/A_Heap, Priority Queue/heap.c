#include <stdlib.h>
#include <string.h>
#include "heap.h"

#define HeapParent(npos)((int)(((npos)-1)/2))
#define HeapLeft(npos)(((npos)*2)+1)
#define HeapRight(npos)(((npos)*2)+2)
void HeapInit(Heap *heap, int(*compare)(const void *key1, const void *key2), void(*destory)(void *data))
{
	heap->nSize = 0;
	heap->compare = compare;
	heap->destory = destory;
	heap->tree = NULL;

	return;
}

void HeapDestory(Heap *heap)
{
	int i = 0;

	if (heap->destory != NULL)
	{
		for (i = 0; i < HeapSize(heap); i++)
		{
			heap->destory(heap->tree[i]);
		}
	}
	free(heap->tree);
	memset(heap, 0, sizeof(heap));
	
	return;
}

int HeapInsert(Heap *heap, const void *data)
{
	void *temp = NULL;
	int ipos = 0;
	int ppos = 0;

	if ((temp = (void**)realloc(heap->tree, (HeapSize(heap) + 1) * sizeof(void*))) == NULL)
	{
		return -1;
	}
	else
	{
		heap->tree = temp;
	}

	heap->tree[HeapSize(heap)] = (void*)data;

	ipos = HeapSize(heap);
	ppos = HeapParent(ipos);

	while (ipos > 0 && heap->compare(heap->tree[ppos], heap->tree[ipos]) < 0)
	{
		temp = heap->tree[ppos];
		heap->tree[ppos] = heap->tree[ipos];
		heap->tree[ipos] = temp;

		ipos = ppos;
		ppos = HeapParent(ipos);
	}
	heap->nSize++;
	
	return 0;
}

int HeapExtract(Heap *heap, void **data)
{
	void *save = NULL;
	void *temp = NULL;

	int ipos = 0;
	int lpos = 0;
	int rpos = 0;
	int mpos = 0;

	if (HeapSize(heap) == 0)
	{
		return -1;
	}
	*data = heap->tree[0];

	save = heap->tree[HeapSize(heap) - 1];
	if (0 < HeapSize(heap) - 1)
	{
		if ((temp = (void**)realloc(heap->tree, (HeapSize(heap) - 1) * sizeof(void*))) == NULL)
		{
			return -1;
		}
		else
		{
			heap->tree = temp;
		}
		heap->nSize--;
	}
	else
	{
		free(heap->tree);
		heap->tree = NULL;
		heap->nSize = 0;
		return 0;
	}
	heap->tree[0] = save;
	ipos = 0;
	lpos = HeapLeft(ipos);
	rpos = HeapRight(ipos);

	while (1)
	{
		lpos = HeapLeft(ipos);
		rpos = HeapRight(ipos);
		if (lpos < HeapSize(heap) && heap->compare(heap->tree[lpos], heap->tree[rpos])>0)
		{
			mpos = lpos;
		}
		else
		{
			mpos = ipos;
		}

		if (rpos < HeapSize(heap) && heap->compare(heap->tree[rpos], heap->tree[lpos])>0)
		{
			mpos = rpos;
		}
		
		if (mpos == ipos)
		{
			break;
		}
		else
		{
			temp = heap->tree[mpos];
			heap->tree[mpos] = heap->tree[ipos];
			heap->tree[ipos] = temp;

			ipos = mpos;
		}
	}

	return 0;
}
