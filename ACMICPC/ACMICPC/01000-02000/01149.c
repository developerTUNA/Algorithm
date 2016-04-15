#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))

int Problem01149(void)
{
	int num;
	int **D;
	int **P;
	int result;

	scanf("%d", &num);
	D = (int **)malloc(sizeof(int*)*(num + 1));
	P = (int **)malloc(sizeof(int*)*(num + 1));
	for (int i = 0; i <= num; i++)
	{
		D[i] = (int*)malloc(sizeof(int) * 3);
		P[i] = (int*)malloc(sizeof(int) * 3);
		memset(D[i], 0, sizeof(int) * 3);
		memset(P[i], 0, sizeof(int) * 3);
	}

	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &P[i][j]);
		}
	}

	for (int i = 1; i <= num; i++)
	{
		D[i][0] = MIN(D[i - 1][1], D[i - 1][2]) + P[i][0];
		D[i][1] = MIN(D[i - 1][0], D[i - 1][2]) + P[i][1];
		D[i][2] = MIN(D[i - 1][0], D[i - 1][1]) + P[i][2];
	}

	result = MIN(MIN(D[num][0], D[num][1]), D[num][2]);
	printf("%d\n", result);

	for (int i = 0; i <= num; i++)
	{
		free(D[i]);
		free(P[i]);
	}
	free(D);
	free(P);
	return 0;
}