#include <stdlib.h>
#include <string.h>
#include "sort.h"

static int merge(void *data, int nBlockSize, int nStart, int nMid, int nEnd, int(*compare)(const void *key1, const void *key2))
{
	char *stream = NULL;
	char *mergeBlock = NULL;
	int nFrontPos = 0;
	int nMidPos = 0;
	int nMergePos = 0;

	stream = data;
	nFrontPos = nStart;
	nMidPos = nMid + 1;
	
	if ((mergeBlock = (char*)malloc(nBlockSize*((nEnd - nStart) + 1))) == NULL)
	{
		return -1;
	}

	while (nFrontPos <= nMid || nMidPos <= nEnd)
	{
		if (nMid < nFrontPos)
		{
			while (nMidPos <= nEnd)
			{
				memcpy(&mergeBlock[nMergePos * nBlockSize], &stream[nMidPos*nBlockSize], nBlockSize);
				nMidPos++;
				nMergePos++;
			}
			continue;
		}
		else if (nEnd < nMidPos)
		{
			while (nFrontPos <= nMid)
			{
				memcpy(&mergeBlock[nMergePos * nBlockSize], &stream[nFrontPos*nBlockSize], nBlockSize);
				nFrontPos++;
				nMergePos++;
			}
			continue;
		}

		if (compare(&stream[nFrontPos*nBlockSize], &stream[nMidPos*nBlockSize]) < 0)
		{
			memcpy(&mergeBlock[nMergePos*nBlockSize], &stream[nFrontPos *nBlockSize], nBlockSize);
			nFrontPos++;
			nMergePos++;
		}
		else
		{
			memcpy(&mergeBlock[nMergePos*nBlockSize], &stream[nMidPos *nBlockSize], nBlockSize);
			nMidPos++;
			nMergePos++;
		}
	}

	memcpy(&stream[nStart * nBlockSize], mergeBlock, nBlockSize * ((nEnd - nStart) + 1));
	free(mergeBlock);

	return 0;
}