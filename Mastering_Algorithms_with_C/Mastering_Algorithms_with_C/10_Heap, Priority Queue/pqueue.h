#ifndef PQUEUE_H
#define PQUEUE_H
#include "heap.h"

typedef Heap PQueue;
#define PQueueInit HeapInit
#define PQueueDestory HeapDestory
#define PQueueInsert HeapInsert
#define PQueueExtract HeapExtract
#define PQueuePeek(pqueue) ((pqueue)->tree == NULL ? NULL : (pqueue)->tree[0])
#define PQueueSize HeapSize

#endif PQUEUE_H