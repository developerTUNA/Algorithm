#ifndef QUEUE_H
#define QUEUE_H
	
#include <stdlib.h>
#include "../5_Linked_List/list.h"

typedef List Queue;

#define QueueInit ListInit
#define QueueDestroy ListDestory
int QueueEnqueue(Queue *queue, const void *data);
int QueueDequeue(Queue *queue, void **data);
#define QueuePeek(queue)(queue->head==NULL?NULL:queue->head->data)
#define QueueSize ListSize

#endif