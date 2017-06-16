#include <stdlib.h>
#include <string.h>

#include "stack.h"

int StackPush(Stack *stack, const void *data)
{
	return ListInsert_Next(stack, NULL, data);
}

int StackPop(Stack *stack, const void **data)
{
	return ListRemove_Next(stack, NULL, *data);
}