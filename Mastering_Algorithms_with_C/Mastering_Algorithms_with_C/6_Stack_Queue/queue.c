#include <stdlib.h>
#include <string.h>
#include "queue.h"

int QueueEnqueue(Queue *queue, const void *data)
{
	return ListInsert_Next(queue, ListTail(queue), data);
}

int QueueDequeue(Queue *queue, void **data)
{
	return ListRemove_Next(queue, NULL, data);
}