#pragma warning (disable:4996)
#include <stdio.h>

int Problem10950(void)
{
	int nRound = 0;
	int nA = 0, nB = 0;

	scanf("%d", &nRound);
	for (int i = 0; i < nRound; i++)
	{
		scanf("%d %d", &nA, &nB);
		printf("%d", nA + nB);
	}
	return 0;
}