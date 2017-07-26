#ifndef HEAP_H
#define HEAP_H

typedef struct Heap_
{
	int nSize;
	int(*compare)(const void *key1, const void *key2);
	void(*destory)(void*data);
	void **tree;
} Heap;

void HeapInit(Heap *heap, int(*compare)(const void *key1, const void *key2), void(*destory)(void *data));
void HeapDestory(Heap *heap);
int HeapInsrt(Heap *heap, const void *data);
int HeapExtract(Heap *heap, void **data);
#define HeapSize(heap)((heap)->nSize)

#endif