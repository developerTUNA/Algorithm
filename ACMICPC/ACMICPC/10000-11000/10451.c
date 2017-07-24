#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem10451(void)
{
	int nTestCase = 0;
	int nEdge = 0;
	int *p_nVertex = NULL;
	int *p_nCheck = NULL;

	scanf("%d", &nTestCase);
	for (int i = 0; i < nTestCase; i++)
	{
		scanf("%d", &nEdge);
		p_nVertex = (int *)malloc(sizeof(int)*(nEdge));
		memset(p_nVertex,0,sizeof(int)*(nEdge));
		p_nCheck = (int *)malloc(sizeof(int)*(nEdge));
		memset(p_nCheck, 0, sizeof(int)*(nEdge));
		for (int j = 0; j < nEdge; j++)
		{
			scanf("%d", &p_nVertex[j]);
		}

		int nCount = 0;

		for (int j = 0; j < nEdge; j++)
		{
			if (p_nCheck[j] == 0)
			{
				nCount++;
				int nNow = j;
				while (p_nCheck[nNow] == 0)
				{
					p_nCheck[nNow] = nCount;
					nNow = p_nVertex[nNow]-1;
				}
			}
		}
		printf("%d\n", nCount);
		free(p_nVertex);
		free(p_nCheck);
	}

	return 0;
}