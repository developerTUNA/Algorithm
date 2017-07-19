#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Check02805(long long llnCut, int nTreeNum, int nNeed, int *p_nTree)
{
	long long llnGet = 0;

	for (int i = 0; i < nTreeNum; i++)
	{
		if (0 < p_nTree[i] - llnCut)
		{
			llnGet += p_nTree[i] - llnCut;
		}
	}

	return nNeed <= llnGet;
}

int Problem02805(void)
{
	int nTreeNum = 0;
	int nNeed = 0;
	long long llnMax = 0;
	long long llnStart = 0;
	long long llnEnd = 0;
	int *p_nTree = NULL;

	scanf("%d %d", &nTreeNum, &nNeed);
	p_nTree = (int*)malloc(sizeof(int)*(nTreeNum));
	memset(p_nTree, 0, sizeof(int)*(nTreeNum));

	for (int i = 0; i < nTreeNum; i++)
	{
		scanf("%d", &p_nTree[i]);
		if (llnEnd < p_nTree[i])
		{
			llnEnd = p_nTree[i];
		}
	}

	while (llnStart <= llnEnd)
	{
		long long llnCut = (llnStart + llnEnd) / 2;
		if (Check02805(llnCut, nTreeNum, nNeed, p_nTree))
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
	free(p_nTree);

	return 0;
}