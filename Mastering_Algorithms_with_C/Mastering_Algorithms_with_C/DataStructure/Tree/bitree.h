#ifndef BITREE_H
#define BITREE_H

#include <stdlib.h>

typedef struct BiTreeNode_
{
	void *data;
	struct BiTreeNode_ *left;
	struct BiTreeNode_ *right;
} BiTreeNode;

typedef struct BiTree_
{
	int nSize;
	int(*compare)(const void *key1, const void *key2);
	void(*destory)(void *data);
	BiTreeNode *root;
}BiTree;

void BiTreeInit(BiTree *tree, void(*destroy)(void *data));
void BiTreeDestory(BiTree *tree);
int BiTreeInsert_Left(BiTree *tree, BiTreeNode *node, const void *data);
int BiTreeInsert_Right(BiTree *tree, BiTreeNode *node, const void *data);
void BiTreeRemove_Left(BiTree *tree, BiTreeNode *node);
void BiTreeRemove_Right(BiTree *tree, BiTreeNode *node);
int BitreeMerge(BiTree *treeMerge, BiTree *treeLeft, BiTree *treeRight, const void *data);
#define BiTreeSize(tree)((tree)->nSize)
#define BiTreeRoot(tree)((tree)->root)
#define BiTreeisEOB(node)((node)==NULL)
#define BiTreeisLeaf(node)((((node)->left) == NULL) && (((node)->right) == NULL))
#define BiTreeData(node)((node)->data)
#define BiTreeLeft(node)((node)->left)
#define BiTreeRight(node)((node)->right)

#endif