#include <stdlib.h>
#include <string.h>
#include "bitree.h"

void BiTreeInit(BiTree *tree, void(*destory)(void *data))
{
	tree->nSize = 0;
	tree->destory = destory;
	tree->root = NULL;

	return;
}

void BiTreeDestory(BiTree *tree)
{
	BiTreeRemove_Left(tree, NULL);
	memset(tree, 0, sizeof(BiTree));

	return;
}

int BiTreeInsert_Left(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *nodeNew = NULL;
	BiTreeNode **position = NULL;

	if (node == NULL)
	{
		if (BiTreeSize(tree) != 0)
		{
			return -1;
		}
		position = &tree->root;
	}
	else
	{
		if (BiTreeLeft(node) != NULL)
		{
			return -1;
		}
		position = &node->left;
	}
	if ((nodeNew = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
	{
		return -1;
	}
	nodeNew->data = (void*)data;
	nodeNew->left = NULL;
	nodeNew->right = NULL;
	*position = nodeNew;
	tree->nSize++;

	return 0;
}

int BiTreeInsert_Right(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *nodeNew = NULL;
	BiTreeNode **position = NULL;
	if (node == NULL)
	{
		if (BiTreeSize(tree) != 0)
		{
			return -1;
		}
		position = &tree->root;
	}
	else
	{
		if (BiTreeRight(node) != NULL)
		{
			return -1;
		}
		position = &node->right;
	}

	if ((nodeNew = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
	{
		return -1;
	}
	nodeNew->data = (void*)data;
	nodeNew->left = NULL;
	nodeNew->right = NULL;
	*position = nodeNew;
	tree->nSize++;

	return 0;
}

void BiTreeRemove_Left(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position = NULL;

	if (BiTreeSize(tree) == NULL)
	{
		return;
	}

	if (node == NULL)
	{
		position = &tree->root;
	}
	else
	{
		position = &node->left;
	}

	if (*position != NULL)
	{
		BiTreeRemove_Left(tree, *position);
		BiTreeRemove_Right(tree, *position);

		if (tree->destory != NULL)
		{
			tree->destory((*position)->data);
		}

		free(*position);
		*position = NULL;
		tree->nSize--;
	}

	return;
}

void BiTreeRemove_Right(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position = NULL;

	if (BiTreeSize(tree) != 0)
	{
		return;
	}

	if (node == NULL)
	{
		*position = tree;
	}
	else
	{
		*position = node->right;
	}

	if (*position != NULL)
	{
		BiTreeRemove_Left(tree, *position);
		BiTreeRemove_Right(tree, *position);

		if (tree->destory != NULL)
		{
			tree->destory((*position)->data);
		}

		free(*position);
		*position = NULL;
		tree->nSize--;
	}

	return;
}

int BiTreeMerge(BiTree *treeMerge, BiTree *treeLeft, BiTree *treeRight, const void *data)
{
	BiTreeInit(treeMerge, treeLeft->destory);

	if (BiTreeInsert_Left(treeMerge, NULL, data) != NULL)
	{
		BiTreeDestory(treeMerge);
		return -1;
	}

	BiTreeRoot(treeMerge)->left = BiTreeRoot(treeLeft);
	BiTreeRoot(treeMerge)->right = BiTreeRoot(treeRight);
	treeMerge->nSize = treeMerge->nSize + BiTreeSize(treeLeft) + BiTreeSize(treeRight);
	treeLeft->root = NULL;
	treeLeft->nSize = 0;
	treeRight->root = NULL;
	treeRight->nSize = 0;
	
	return 0;
}