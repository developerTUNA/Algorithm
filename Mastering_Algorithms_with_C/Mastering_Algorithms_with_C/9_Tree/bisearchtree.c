#include <stdlib.h>
#include <string.h>
#include "bisearchtree.h"

void BiSearchTreeInit(BiSearchTree *tree, int(*compare)(const void *key1, const void *key2), void(*destory)(void *data))
{
	BiTreeInit(tree, destory);
	tree->compare = compare;

	return;
}

void BiSearchTreeDestory(BiSearchTree *tree)
{
	BiTreeDestory(tree);
	memset(tree, 0, sizeof(BiSearchTree));
	
	return;
}

int BiSearchTreeInsert(BiSearchTree *tree, const void *data)
{
	int nBalance = 0;
	return BiSearchTreeInsert_Rec(tree, &BiTreeRoot(tree), data, &nBalance);
}

int BiSearchTreeRemove(BiSearchTree *tree, const void *data)
{

	return BiSearchTreeRemove_Rec(tree, BiTreeRoot(tree), data);
}

int BiSearchTreeLookup(BiSearchTree *tree, void **data)
{

	return BiSearchTreeLookup_Rec(tree, BiTreeRoot(tree), data);
}