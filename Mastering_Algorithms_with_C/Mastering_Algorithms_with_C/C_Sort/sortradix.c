#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int Sort_Radix(int *data, int nNum, int nDigit, int nBase)
{
	int *count = NULL;
	int *temp = NULL;
	int nIndex = 0;
	int nPivot = 0;

	if ((count=(int*)malloc(nBase * sizeof(int))) == NULL)
	{
		return -1;
	}

	if ((temp = (int*)malloc(nNum * sizeof(int))) == NULL)
	{
		return -1;
	}

	for (int i = 0; i < nDigit; i++)
	{
		for (int j = 0; j < nBase; j++)
		{
			count[j] = 0;
		}

		nPivot = 1;
		for (int j = 0; j < i; j++)
		{
			nPivot = nPivot * nBase;
		}

		for (int j = 0; j < nNum; j++)
		{
			nIndex = (int)(data[j] / nPivot) % nBase;
			count[nIndex] = count[nIndex] + 1;
		}

		for (int j = 1; j < nBase; j++)
		{
			count[j] = count[j] + count[j - 1];
		}

		for (int j = nNum - 1; 0 <= j; j--)
		{
			nIndex = (int)(data[j] / nPivot) % nBase;
			temp[count[nIndex] - 1] = data[j];
			count[nIndex] = count[nIndex] - 1;
		}

		memcpy(data, temp, nNum * sizeof(int));
	}

	free(count);
	free(temp);

	return 0;
}