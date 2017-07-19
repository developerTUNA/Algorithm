#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Check01654(long long llnCut, int nHave, int nNeed, int *p_nLen)
{
	long long llnCount = 0;
	for (int i = 0; i < nHave; i++)
	{
		llnCount += p_nLen[i] / llnCut;
	}

	return nNeed<=llnCount;
}

int Problem01654(void)
{
	int nHave = 0;
	int nNeed = 0;
	int *p_nLen = NULL;
	long long llnStart = 1;
	long long llnEnd = 0;
	long long llnCut = 0;
	long long llnMax = 0;

	scanf("%d %d", &nHave, &nNeed);
	p_nLen = (int *)malloc(sizeof(int)*(nHave));
	memset(p_nLen, 0, sizeof(int)*(nHave));

	for (int i = 0; i < nHave; i++)
	{
		scanf("%d", &p_nLen[i]);
		if (llnEnd < p_nLen[i])
		{
			llnEnd = p_nLen[i];
		}
	}

	while (llnStart <= llnEnd)
	{
		llnCut = (llnStart + llnEnd) / 2;
		if (Check01654(llnCut, nHave, nNeed, p_nLen))
		{
			if (llnMax < llnCut)
			{
				llnMax = llnCut;
			}
			llnStart = llnCut + 1;
		}
		else
		{
			llnEnd = llnCut - 1;
		}
	}

	printf("%lld\n", llnMax);
	free(p_nLen);
	return 0;
}