#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int QuickSelection11004(int n, int *ArrList, int k)
{
	if (ArrList == NULL || n <= k)
		return -1;

	int start = 0;
	int end = n - 1;

	while (start < end)
	{
		int i = start;
		int j = end;
		int mid = ArrList[(i + j) / 2];

		while (i < j)
		{
			if (ArrList[i] >= mid)
			{
				int tmp = ArrList[j];
				ArrList[j] = ArrList[i];
				ArrList[i] = tmp;
				j--;
			}
			else {
				i++;
			}
		}

		if (ArrList[i] > mid)
			i--;

		if (k <= i)
			end = i;
		else
			start = i + 1;
	}

	return ArrList[k];
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