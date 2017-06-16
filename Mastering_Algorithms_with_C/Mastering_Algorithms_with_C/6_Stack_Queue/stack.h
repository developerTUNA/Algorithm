#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "../5_Linked_List/list.h"

typedef List Stack;

#define StackInit ListInit
#define StackDestory ListDestory
int StackPush(Stack *stack, const void *data);
int StackPop(Stack *stack, void **data);
#define StackPeek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)
#define StackSize ListSize;

#endif