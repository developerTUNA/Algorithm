#include <stdlib.h>
#include <string.h>
#include "search.h"

int Search_Binary(void *sorted, const void *target, int nNum, int nBlockSize, int(*compare)(const void *key1, const void *key2))
{
	int nLeft = 0;
	int nMiddle = 0;
	int nRight = 0;

	nLeft = 0;
	nRight = nNum - 1;

	while (nLeft < nRight)
	{
		nMiddle = (nLeft + nRight) / 2;

		switch (compare(((char*)sorted + (nBlockSize * nMiddle)), target))
		{
		case -1:
			nLeft = nMiddle + 1;
			break;
		case 1:
			nRight = nMiddle - 1;
			break;
		case 0:
			return nMiddle;
		}
	}

	return -1;
}