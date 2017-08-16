#include <stdlib.h>
#include <string.h>
#include "sort.h"

int Sort_Count(int *data, int nNum, int nMax)
{
	int *count = NULL;
	int *temp = NULL;

	if ((count = (int*)malloc(nMax * sizeof(int))) == NULL)
	{
		return -1;
	}
	if ((temp = (int*)malloc(nNum * sizeof(int))) == NULL)
	{
		return -1;
	}

	for (int i = 0; i < nMax; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < nNum; i++)
	{
		count[data[i]] = count[data[i]] + 1;
	}

	for (int i = 1; i < nMax; i++)
	{
		count[i] = count[i] + count[i - 1];
	}

	for (int i = nNum - 1; 0 <= i; i--)
	{
		temp[count[data[i]] - 1] = data[i];
		count[data[i]] = count[data[i]] - 1;
	}

	memcpy(data, temp, nNum * sizeof(int));

	free(count);
	free(temp);

	return 0;
}