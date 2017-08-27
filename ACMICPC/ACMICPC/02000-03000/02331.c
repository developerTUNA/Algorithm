#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02331(void)
{
	int *p_nBlock = NULL;
	int nNum = 0;
	int nNow = 0;
	int nPrev = 0;
	int nPow = 0;
	int nCount = 0;
	int nResult = 0;
	scanf("%d %d", &nNum, &nPow);
	nNow = nNum;
	p_nBlock = (int*)malloc(sizeof(int)*(9 * 9 * 9 * 9 * 9 * 5));
	memset(p_nBlock, 0, sizeof(int)*(9 * 9 * 9 * 9 * 9 * 5));

	while (p_nBlock[nNow] == 0)
	{
		int nTemp = 0;
		nCount++;
		p_nBlock[nNow] = nCount;
		nPrev = nNow;
		nNum = nNow;
		nNow = 0;
		while (0 < nNum)
		{
			nTemp = 1;
			for(int i=0; i<nPow;i++)
			{
				nTemp *= nNum % 10;
			}
			nNow += nTemp;
			nNum /= 10;
		}
	}
	nResult = p_nBlock[nNow]-1;
	printf("%d\n", nResult);
	free(p_nBlock);
	return 0;
}