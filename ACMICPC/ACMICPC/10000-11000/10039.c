#pragma warning(disable:4996)
#include <stdio.h>

int Problem10039(void)
{
	int nScore = 0;
	int nSum = 0;

	for(int i=0; i<5;i++)
	{
		scanf("%d", &nScore);
		if (nScore < 40)
		{
			nScore = 40;
		}
		nSum += nScore;
	}
	printf("%d\n", nSum / 5);
	
	return 0;
}