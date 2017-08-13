#include <stdlib.h>
#include <string.h>
#include "sort.h"

int Sort_Insert(void *data, int nNum, int nBlockSize, int (*compare)(const void *key1, const void *key2))
{
	char *stream = NULL;
	void *key = NULL;
	int i = 0;
	int j = 0;

	stream = data;

	if ((key = (char*)malloc(nBlockSize)) == NULL)
	{
		return -1;
	}

	for (j = 1; j < nNum; j++)
	{
		memcpy(key, &stream[j*nBlockSize], nBlockSize);
		i = j - 1;

		while (i >= 0 && compare(&stream[i*nBlockSize], key) > 0)
		{
			memcpy(&stream[(i + 1)*nBlockSize], &stream[i*nBlockSize], nBlockSize);
			i--;
		}
		memcpy(&stream[(i + 1)*nBlockSize], key, nBlockSize);
	}

	free(key);
	return 0;
}