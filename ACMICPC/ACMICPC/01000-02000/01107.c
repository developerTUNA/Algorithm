#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GetPush01107(int nChannel, int nNow, int a_nBroken[10])
{
	int nResult = 0;
	int nPushCount = 0;

	nResult = nNow - nChannel;
	if (nResult < 0)
	{
		nResult = -1 * nResult;
	}

	if(nNow == 100)
	{
		//no push
	}
	else if (nNow == 0)
	{
		if (a_nBroken[nNow % 10])
		{
			return -1;
		}
		nPushCount++;
	}
	else
	{
		while (nNow)
		{
			if (a_nBroken[nNow % 10])
			{
				return -1;
			}
			nNow = nNow / 10;
			nPushCount++;
		}
	}

	nResult = nResult + nPushCount;

	return nResult;
}

int Problem01107(void)
{
	int nGet = 0;
	int nResult = 0;
	int nChannel = 0;
	int nBroken = 0;
	int a_nBroken[10] = { 0, };

	scanf("%d", &nChannel);
	scanf("%d", &nBroken);
	for (int i = 0; i < nBroken; i++)
	{
		int nTemp = 0;
		scanf("%d", &nTemp);
		a_nBroken[nTemp] = 1;
	}

	nResult = 1000000;
	for (int i = 0; i < 1000000; i++)
	{
		nGet = GetPush01107(nChannel, i, a_nBroken);
		if (nGet == -1)
		{
			continue;
		}
		if (nGet < nResult)
		{
			nResult = nGet;
		}
	}

	printf("%d\n", nResult);
	return 0;
}