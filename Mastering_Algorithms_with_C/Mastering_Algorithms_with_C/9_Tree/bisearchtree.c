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

static void Rotate_Left(BiTreeNode **node)
{
	BiTreeNode *left = NULL;
	BiTreeNode *grandChild = NULL;

	left = BiTreeLeft(*node);
	if (((AVLNode*)BiTreeData(left))->nFactor == AVL_LEFT_HEAVY)	//LL
	{
		BiTreeLeft(*node) = BiTreeRight(left);
		BiTreeRight(left) = *node;
		((AVLNode*)BiTreeData(*node))->nFactor = AVL_BALANCE;
		((AVLNode*)BiTreeData(left))->nFactor = AVL_BALANCE;
		*node = left;
	}
	else															//LR
	{
		grandChild = BiTreeRight(left);
		BiTreeRight(left) = BiTreeLeft(grandChild);
		BiTreeLeft(grandChild) = left;
		BiTreeLeft(*node) = BiTreeRight(grandChild);
		BiTreeRight(grandChild) = *node;

		switch (((AVLNode*)BiTreeData(grandChild))->nFactor)
		{
		case AVL_LEFT_HEAVY:
			((AVLNode*)BiTreeData(*node))->nFactor = AVL_RIGHT_HEAVY;
			((AVLNode*)BiTreeData(left))->nFactor = AVL_BALANCE;
			break;
		case AVL_RIGHT_HEAVY:
			((AVLNode*)BiTreeData(*node))->nFactor = AVL_BALANCE;
			((AVLNode*)BiTreeData(left))->nFactor = AVL_BALANCE;
			break;
		case AVL_BALANCE:
			((AVLNode*)BiTreeData(*node))->nFactor = AVL_BALANCE;
			((AVLNode*)BiTreeData(left))->nFactor = AVL_LEFT_HEAVY;
			break;
		}
		((AVLNode *)BiTreeData(grandChild))->nFactor = AVL_BALANCE;
		*node = grandChild;
	}

	return;
}

static void Rotate_Right(BiTreeNode **node)
{
	BiTreeNode *right = NULL;
	BiTreeNode *grandChild = NULL;

	right = BiTreeRight(*node);
	if (((AVLNode*)BiTreeData(right))->nFactor == AVL_LEFT_HEAVY)	//RR
	{
		BiTreeRight(*node) = BiTreeLeft(right);
		BiTreeLeft(right) = *node;
		((AVLNode*)BiTreeData(*node))->nFactor = AVL_BALANCE;
		((AVLNode*)BiTreeData(right))->nFactor = AVL_BALANCE;
		*node = right;
	}
	else															//RL
	{
		grandChild = BiTreeLeft(right);
		BiTreeLeft(right) = BiTreeRight(grandChild);
		BiTreeRight(grandChild) = right;
		BiTreeRight(*node) = BiTreeLeft(grandChild);
		BiTreeLeft(grandChild) = *node;

		switch (((AVLNode*)BiTreeData(grandChild))->nFactor)
		{
		case AVL_LEFT_HEAVY:
			((AVLNode*)BiTreeData(*node))->nFactor = AVL_BALANCE;
			((AVLNode*)BiTreeData(right))->nFactor = AVL_RIGHT_HEAVY;
			break;
		case AVL_RIGHT_HEAVY:
			((AVLNode*)BiTreeData(*node))->nFactor = AVL_BALANCE;
			((AVLNode*)BiTreeData(right))->nFactor = AVL_BALANCE;
			break;
		case AVL_BALANCE:
			((AVLNode*)BiTreeData(*node))->nFactor = AVL_LEFT_HEAVY;
			((AVLNode*)BiTreeData(right))->nFactor = AVL_BALANCE;
			break;
		}
		((AVLNode *)BiTreeData(grandChild))->nFactor = AVL_BALANCE;
		*node = grandChild;
	}

	return;
}

static void Destory_Left(BiSearchTree *tree, BiTreeNode *node)
{
	BiTreeNode **position = NULL;
	if (BiTreeSize(tree) == 0)
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
		Destory_Left(tree, *position);
		Destory_Right(tree, *position);
		if (tree->destory != NULL)
		{
			tree->destory(((AVLNode*)(*position)->data)->data);
		}
		free((*position)->data);
		free(*position);
		*position = NULL;

		tree->nSize--;
	}

	return;
}

static void Destory_Right(BiSearchTree *tree, BiTreeNode *node)
{
	BiTreeNode **position = NULL;
	if (BiTreeSize(tree) == 0)
	{
		return;
	}

	if (node == NULL)
	{
		position = &tree->root;
	}
	else
	{
		position = &node->right;
	}
	if (*position != NULL)
	{
		Destory_Left(tree, *position);
		Destory_Right(tree, *position);
		if (tree->destory != NULL)
		{
			tree->destory(((AVLNode*)(*position)->data)->data);
		}
		free((*position)->data);
		free(*position);
		*position = NULL;

		tree->nSize--;
	}

	return;
}

static int BiSearchTreeInsert_Rec(BiSearchTree *tree, BiTreeNode **node, const void *data, int *nBalance)
{
	AVLNode *AVLData = NULL;
	int nCmp = 0;
	int nRet = 0;

	if (BiTreeisEOB(*node))
	{
		if ((AVLData = (AVLNode*)malloc(sizeof(AVLNode))) == NULL)
		{
			return -1;
		}
		AVLData->nFactor = AVL_BALANCE;
		AVLData->nHidden = 0;
		AVLData->data = (void*)data;
		return BiTreeInsert_Left(tree, *node, AVLData);
	}
	else
	{
		nCmp = tree->compare(data, ((AVLNode*)BiTreeData(*node))->data);
		if (nCmp < 0)
		{
			if (BiTreeisEOB(BiTreeLeft(*node)))
			{
				if ((AVLData = (AVLNode*)malloc(sizeof(AVLNode))) == NULL)
				{
					return -1;
				}
				AVLData->nFactor = AVL_BALANCE;
				AVLData->nHidden = 0;
				AVLData->data = (void*)data;

				if (BiTreeInsert_Left(tree, *node, AVLData) != 0)
				{
					return -1;
				}
				*nBalance = 0;
			}
			else
			{
				if ((nRet = BiSearchTreeInsert_Rec(tree, &BiTreeLeft(*node), data, nBalance)) != 0)
				{
					return nRet;
				}
			}
			if (!(*nBalance))
			{
				switch (((AVLNode*)BiTreeData(*node))->nFactor)
				{
				case AVL_LEFT_HEAVY:
					Rotate_Left(node);
					*nBalance = 1;
					break;
				case AVL_BALANCE:
					((AVLNode*)BiTreeData(*node))->nFactor = AVL_LEFT_HEAVY;
					break;
				case AVL_RIGHT_HEAVY:
					((AVLNode*)BiTreeData(*node))->nFactor = AVL_BALANCE;
					*nBalance = 1;
					break;
				}
			}
		}
		else if(0 < nCmp)
		{
			if (BiTreeisEOB(BiTreeRight(*node)))
			{
				if ((AVLData = (AVLNode*)malloc(sizeof(AVLNode))) == NULL)
				{
					return -1;
				}
				AVLData->nFactor = AVL_BALANCE;
				AVLData->nHidden = 0;
				AVLData->data = (void*)data;

				if (BiTreeInsert_Right(tree, *node, AVLData) != 0)
				{
					return -1;
				}
				*nBalance = 0;
			}
			else
			{
				if ((nRet = BiSearchTreeInsert_Rec(tree, &BiTreeRight(*node), data, nBalance))!=0)
				{
					return nRet;
				}
			}
			if (!(*nBalance))
			{
				switch (((AVLNode*)BiTreeData(*node))->nFactor)
				{
				case AVL_LEFT_HEAVY:
					((AVLNode*)BiTreeData(*node))->nFactor = AVL_BALANCE;
					*nBalance = 1;
					break;
				case AVL_BALANCE:
					((AVLNode*)BiTreeData(*node))->nFactor = AVL_RIGHT_HEAVY;
					break;
				case AVL_RIGHT_HEAVY:
					Rotate_Right(node);
					*nBalance = 1;
					break;
				}
			}
		}
		else
		{
			if (!((AVLNode*)BiTreeData(*node))->nHidden)
			{
				return 1;
			}
			else
			{
				if (tree->destory != NULL)
				{
					tree->destory(((AVLNode*)BiTreeData(*node))->data);
				}
				((AVLNode*)BiTreeData(*node))->data = (void *)data;
				((AVLNode*)BiTreeData(*node))->nHidden = 0;
				*nBalance = 1;
			}
		}
	}
	return 0;
}

static int BiSearchTreeRemove_Rec(BiSearchTree *tree, BiTreeNode *node, const void *data)
{
	int nCmp = 0;
	int nRet = 0;

	if (BiTreeisEOB(node))
	{
		return -1;
	}

	nCmp = tree->compare(data, ((AVLNode*)BiTreeData(node))->data);

	if (nCmp < 0)
	{
		nRet = BiSearchTreeRemove_Rec(tree, BiTreeLeft(node), data);
	}
	else if (0 < nCmp)
	{
		nRet = BiSearchTreeRemove_Rec(tree, BiTreeRight(node), data);
	}
	else
	{
		((AVLNode*)BiTreeData(node))->nHidden = 1;
		nRet = 0;
	}
	return nRet;
}

static int BiSearchTreeLookup_Rec(BiSearchTree *tree, BiTreeNode *node, void **data)
{
	int nCmp = 0;
	int nRet = 0;

	if (BiTreeisEOB(node))
	{
		return -1;
	}

	nCmp = tree->compare(*data, ((AVLNode*)BiTreeData(node))->data);

	if (nCmp < 0)
	{
		nRet = BiSearchTreeLookup_Rec(tree, BiTreeLeft(node), data);
	}
	else if (0<nCmp)
	{
		nRet = BiSearchTreeLookup_Rec(tree, BiTreeRight(node), data);
	}
	else
	{
		if (!((AVLNode*)BiTreeData(node))->nHidden)
		{
			*data = ((AVLNode*)BiTreeData(node))->data;
		}
		else
		{
			return -1;
		}
	}
	return nRet;
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

