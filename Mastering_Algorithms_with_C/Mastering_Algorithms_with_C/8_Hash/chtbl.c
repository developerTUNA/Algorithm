#include <stdlib.h>
#include <string.h>
#include "chtbl.h"

int ChtblInit(CHTbl *htbl, int nBuckets, int(*hash)(const void *key), int(*match)(const void *key1, const void *key2), void(*destroy)(void *data))
{
	if ((htbl->tables = (List*)malloc(nBuckets * sizeof(List))) == NULL)
	{
		return -1;
	}
	htbl->nBuckets = nBuckets;
	for (int i = 0; i < htbl->nBuckets; i++)
	{
		ListInit(&htbl->tables[i], destroy);
	}
	htbl->hash = hash;
	htbl->match = match;
	htbl->destory = destroy;
	htbl->nSize = 0;

	return 0;
}

void ChtblDestory(CHTbl *htbl)
{
	for (int i = 0; i < htbl->nBuckets; i++)
	{
		ListDestory(&htbl->tables[i]);
	}
	free(htbl->tables);
	memset(htbl, 0, sizeof(CHTbl));

	return;
}

int ChtblInsert(CHTbl *htbl, const void *data)
{
	void *temp = NULL;
	int nBucket = 0;
	int nRetval = 0;

	temp = (void*)data;

	if (ChtblLookup(htbl, &temp) == NULL)
	{
		return 1;
	}
	nBucket = htbl->hash(data) % htbl->nBuckets;

	if ((nRetval = ListInsert_Next(&htbl->tables[nBucket], NULL, data)) == NULL)
	{
		htbl->nSize++;
	}

	return nRetval;
}

int ChtblRemove(CHTbl *htbl, void **data)
{
	ListElmt *element = NULL;
	ListElmt *prev = NULL;
	int nBucket = 0;

	nBucket = htbl->hash(*data) % htbl->nBuckets;

	prev = NULL;

	for (element = ListHead(&htbl->tables[nBucket]); element != NULL; element = ListNext(element))
	{
		if (htbl->match(*data, ListData(element)))
		{
			if (ListRemove_Next(&htbl->tables[nBucket], prev, data) == 0)
			{
				htbl->nSize--;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		prev = element;
	}
	return -1;
}

int ChtblLookup(const CHTbl *htbl, void **data)
{
	ListElmt *element = NULL;
	int nBucket = 0;

	nBucket = htbl->hash(*data) % htbl->nBuckets;
	for (element = ListHead(&htbl->tables[nBucket]); element != NULL; element = ListNext(element))
	{
		if (htbl->match(*data, ListData(element)))
		{
			*data = ListData(element);
			return 0;
		}
	}
	return -1;
}