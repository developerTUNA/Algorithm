#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01476(void)
{
	int nE = 0;
	int nS = 0;
	int nM = 0;

	int nE_Counter = 0;
	int nS_Counter = 0;
	int nM_Counter = 0;

	scanf("%d %d %d", &nE, &nS, &nM);

	for (int i = 1; i <= 15*28*19; i++)
	{
		nE_Counter++;
		nS_Counter++;
		nM_Counter++;

		if (nE_Counter == 16)
		{
			nE_Counter = 1;
		}
		if (nS_Counter == 29)
		{
			nS_Counter = 1;
		}
		if (nM_Counter == 20)
		{
			nM_Counter = 1;
		}
		if (nE == nE_Counter && nS == nS_Counter && nM == nM_Counter)
		{
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
