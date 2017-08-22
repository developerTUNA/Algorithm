#ifndef QUEUE_H
#define QUEUE_H
	
#include <stdlib.h>
#include "../List/list.h"

typedef List Queue;

#define QueueInit ListInit
#define QueueDestroy ListDestory
int QueueEnqueue(Queue *queue, const void *data);
int QueueDequeue(Queue *queue, void **data);
#define QueuePeek(queue)((queue)->Head==NULL?NULL:(queue)->Head->data)
#define QueueSize ListSize

#endif