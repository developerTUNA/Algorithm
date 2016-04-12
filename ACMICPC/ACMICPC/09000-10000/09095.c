#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Problem09095(void)
{
	int round, num;
	int *D;

	num = 10;
	D = (int *)malloc(sizeof(int)*(num + 1));
	D[0] = 0;
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for (int i = 4; i <= num; i++)
	{
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}

	scanf("%d", &round);
	for (int i = 0; i < round; i++)
	{
		scanf("%d", &num);
		printf("%d\n", D[num]);
	}

	free(D);
	return 0;
}