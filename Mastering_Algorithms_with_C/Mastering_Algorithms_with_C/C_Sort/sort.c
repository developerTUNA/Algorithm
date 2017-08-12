#include <stdlib.h>
#include <string.h>
#include "sort.h"

int SortInsert(void *data, int nNum, int nSizeBlock, int (*compare)(const void *key1, const void *key2))
{
	char *a = NULL;
	void *key = NULL;
	int i = 0;
	int j = 0;

	a = data;

	if ((key = (char*)malloc(nSizeBlock)) == NULL)
	{
		return -1;
	}

	for (j = 1; j < nNum; j++)
	{
		memcpy(key, &a[j*nSizeBlock], nSizeBlock);
		i = j - 1;

		while (i >= 0 && compare(&a[i*nSizeBlock], key) > 0)
		{
			memcpy(&a[(i + 1)*nSizeBlock], &a[i*nSizeBlock], nSizeBlock);
			i--;
		}
		memcpy(&a[(i + 1)*nSizeBlock], key, nSizeBlock);
	}

	free(key);
	return 0;
}