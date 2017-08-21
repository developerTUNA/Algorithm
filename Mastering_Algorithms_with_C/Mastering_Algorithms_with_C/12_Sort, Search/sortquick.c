#include <stdlib.h>
#include <string.h>
#include "sort.h"

static int CompareInt(const void *key1, const void *key2)
{
	if (*(const int *)key2 < *(const int*)key1)
	{
		return 1;
	}
	else if (*(const int *)key1 < *(const int*)key2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

static int partition(void *data, int nBlockSize, int nStart, int nEnd, int(*compare)(const void *key1, const void *key2))
{
	char *stream = NULL;
	void *pivot = NULL;
	void *temp = NULL;
	int nRandomMid[3] = { 0, };

	stream = data;

	if ((pivot = malloc(nBlockSize)) == NULL)
	{
		return -1;
	}
	if ((temp = malloc(nBlockSize)) == NULL)
	{
		free(pivot);
		return -1;
	}

	nRandomMid[0] = (rand() % (nEnd - nStart + 1)) + 1;
	nRandomMid[1] = (rand() % (nEnd - nStart + 1)) + 1;
	nRandomMid[2] = (rand() % (nEnd - nStart + 1)) + 1;
	Sort_Insert(nRandomMid, 3, sizeof(int), CompareInt);
	memcpy(pivot, &stream[nRandomMid[1] * nBlockSize], nBlockSize);

	nStart--;
	nEnd++;

	while (1)
	{
		do
		{
			nEnd--;
		} while (compare(&stream[nEnd*nBlockSize], pivot) > 0);

		do
		{
			nStart++;
		} while (compare(&stream[nStart*nBlockSize], pivot) < 0);

		if (nEnd <= nStart)
		{
			break;
		}
		else
		{
			memcpy(temp, &stream[nStart*nBlockSize], nBlockSize);
			memcpy(&stream[nStart*nBlockSize], &stream[nEnd*nBlockSize], nBlockSize);
			memcpy(&stream[nEnd*nBlockSize], temp, nBlockSize);
		}
	}

	free(pivot);
	free(temp);

	return nEnd;
}

int Sort_Quick(void *data, int nNum, int nBlockSize, int nStart, int nEnd, int(*compare)(const void *key1, const void *key2))
{
	int nPivot = 0;

	while (nStart < nEnd)
	{
		if ((nPivot = partition(data, nBlockSize, nStart, nEnd, compare)) < 0)
		{
			return -1;
		}

		if (Sort_Quick(data, nNum, nBlockSize, nStart, nPivot, compare) < 0)
		{
			return -1;
		}

		nStart = nPivot + 1;
	}

	return 0;
}