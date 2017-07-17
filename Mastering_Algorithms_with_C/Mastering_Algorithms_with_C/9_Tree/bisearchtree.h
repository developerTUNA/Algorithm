#ifndef BISTREE_H
#define BISTREE_H
#include "bitree.h"

#define AVL_LEFT_HEAVY 1
#define AVL_BALANCE 0
#define AVL_RIGHT_HEAVY -1

typedef struct AVLNode_
{
	void *data;
	int nHidden;
	int nFactor;
}AVLNode;

typedef BiTree BiSearchTree;

void BiSerachTreeInit(BiSearchTree *tree, int(*compare)(const void *key1, const void *key2), void(*destory)(void *data));
void BiSearchTreeDestory(BiSearchTree *tree);
int BiSearchTreeInsert(BiSearchTree *tree, const void *data);
int BiSearchTreeRemove(BiSearchTree *tree, const void *data);
int BiSearchTreeLookup(BiSearchTree *tree, void **data);
#define BiSearchTreeSize(tree) ((tree)->nSize)
#endif