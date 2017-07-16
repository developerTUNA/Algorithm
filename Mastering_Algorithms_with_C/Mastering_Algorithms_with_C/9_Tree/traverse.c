#include "../5_Linked_List/list.h"
#include "traverse.h"

int BiTreeOrder_Pre(const BiTreeNode *node, List *list)
{
	if (!BiTreeisEOB(node))
	{
		if (ListInsert_Next(list, ListTail(list), BiTreeData(node)) != 0)
		{
			return -1;
		}
		if (!BiTreeisEOB(BiTreeLeft(node)))
		{
			if (BiTreeOrder_Pre(BiTreeLeft(node), list) != 0)
			{
				return -1;
			}
		}
		if (!BiTreeisEOB(BiTreeRight(node)))
		{
			if (BiTreeOrder_Pre(BiTreeRight(node), list) != 0)
			{
				return -1;
			}
		}
	}

	return 0;
}

int BiTreeOrder_In(const BiTreeNode *node, List *list)
{
	if (!BiTreeisEOB(node))
	{

		if (!BiTreeisEOB(BiTreeLeft(node)))
		{
			if (BiTreeOrder_Pre(BiTreeLeft(node), list) != 0)
			{
				return -1;
			}
		}
		if (ListInsert_Next(list, ListTail(list), BiTreeData(node)) != 0)
		{
			return -1;
		}
		if (!BiTreeisEOB(BiTreeRight(node)))
		{
			if (BiTreeOrder_Pre(BiTreeRight(node), list) != 0)
			{
				return -1;
			}
		}
	}

	return 0;
}

int BiTreeOrder_Post(const BiTreeNode *node, List *list)
{
	if (!BiTreeisEOB(node))
	{

		if (!BiTreeisEOB(BiTreeLeft(node)))
		{
			if (BiTreeOrder_Pre(BiTreeLeft(node), list) != 0)
			{
				return -1;
			}
		}
		if (!BiTreeisEOB(BiTreeRight(node)))
		{
			if (BiTreeOrder_Pre(BiTreeRight(node), list) != 0)
			{
				return -1;
			}
		}
		if (ListInsert_Next(list, ListTail(list), BiTreeData(node)) != 0)
		{
			return -1;
		}
	}

	return 0;
}