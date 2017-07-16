#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "bitree.h"
#include "../5_Linked_List/list.h"

int BiTreeOrder_Pre(const BiTreeNode *node, List *list);
int BiTreeOrder_In(const BiTreeNode *node, List *list);
int BiTreeOrder_Post(const BiTreeNode *node, List *list);

#endif
