#include <stdlib.h>
#include <string.h>
#include "ohtbl.h"

static char vacated;

int OhtblInit(OHTbl *htbl, int nPositions, int(*hash1)(const void *key), int(*hash2)(const void *key), int(*match)(const void *key1, const void *key2), void(*destory)(void *data))
{
	if ((htbl->table = (void**)malloc(nPositions * sizeof(void*))) == NULL)
	{
		return -1;
	}

	htbl->nPositions = nPositions;

	for (int i = 0; i < htbl->nPositions; i++)
	{
		htbl->table[i] = NULL;
	}

	htbl->vacated = &vacated;
	htbl->hash1 = hash1;
	htbl->hash2 = hash2;
	htbl->match = match;
	htbl->destory = destory;
	htbl->nSize = 0;

	return 0;
}

void OhtblDestory(OHTbl *htbl)
{
	if (htbl->destory != NULL)
	{
		for (int i = 0; i < htbl->nPositions; i++)
		{
			if (htbl->table[i] != NULL && htbl->table[i] != htbl->vacated)
			{
				htbl->destory(&htbl->table[i]);
			}
		}
	}

	free(htbl->table);
	memset(htbl, 0, sizeof(OHTbl));

	return;
}

int OhtblInsert(OHTbl *htbl, const void *data)
{
	void *temp = NULL;
	int nPosition = 0;

	if (htbl->nSize == htbl->nPositions)
	{
		return -1;
	}

	temp = (void*)data;

	if (OhtblLookup(htbl, &temp)==0)
	{
		return 1;
	}

	for (int i = 0; i < htbl->nPositions; i++)
	{
		nPosition = (htbl->hash1(data)*(i*htbl->hash2(data))) % htbl->nPositions;
		if (htbl->table[nPosition] == NULL || htbl->table[nPosition] == htbl->vacated)
		{
			htbl->table[nPosition] = (void *)data;
			htbl->nSize++;
			return 0;
		}
	}
	return -1;
}

int OhtblRemove(OHTbl *htbl, void **data)
{
	int nPosition = 0;

	for (int i = 0; i < htbl->nPositions; i++)
	{
		nPosition = (htbl->hash1(*data) * (i*htbl->hash2(*data))) % htbl->nPositions;

		if (htbl->table[nPosition] == NULL)
		{
			return -1;
		}
		else if(htbl->table[nPosition] == htbl->vacated)
		{
			continue;
		}
		else if (htbl->match(htbl->table[nPosition], *data))
		{
			*data = htbl->table[nPosition];
			htbl->table[nPosition] = htbl->vacated;
			htbl->nSize--;
			return 0;
		}
	}
	return -1;
}

int OhtblLookup(const OHTbl *htbl, void **data)
{
	int nPosition = 0;

	for (int i = 0; i < htbl->nPositions; i++)
	{
		nPosition = (htbl->hash1(*data) * (i*htbl->hash2(*data))) % htbl->nPositions;

		if (htbl->table[nPosition] == NULL)
		{
			return -1;
		}
		else if (htbl->match(htbl->table[nPosition], *data))
		{
			*data = htbl->table[nPosition];
			return 0;
		}
	}
	return -1;
}