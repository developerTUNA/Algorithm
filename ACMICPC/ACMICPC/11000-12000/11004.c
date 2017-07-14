#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Swap11004(int *nA, int *nB)
{
	int nTemp = 0;
	nTemp = *nA;
	*nA = *nB;
	*nB = nTemp;
}

int QuickSelection11004(int nSize, int *ArrList, int nFind)
{
	if (ArrList == NULL || nSize <= nFind)
		return -1;

	int nStart = 0;
	int nEnd = nSize - 1;

	while (nStart < nEnd)
	{
		int i = nStart;
		int j = nEnd;
		int mid = ArrList[(i + j) / 2];

		while (i < j)
		{
			if (ArrList[i] >= mid)
			{
				Swap11004(ArrList[i], ArrList[j]);
				j--;
			}
			else
			{
				i++;
			}
		}

		if (ArrList[i] > mid)
		{
			i--;
		}
		if (nFind <= i)
		{
			nEnd = i;
		}
		else
		{
			nStart = i + 1;
		}
	}

	return ArrList[nFind];
}

int Problem11004(void)
{
	int nSize = 0;
	int nPosition = 0;
	int *p_nNumber=NULL;

	scanf("%d %d", &nSize, &nPosition);
	p_nNumber = malloc(sizeof(int)*(nSize));
	memset(p_nNumber, 0, sizeof(int)*(nSize));

	for (int i = 0; i < nSize; i++)
	{
		scanf("%d", &p_nNumber[i]);
	}


	int res = quickselection11004(nSize, p_nNumber, nPosition-1);

	printf("%d\n", res);
	free(p_nNumber);
	return 0;
}