#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
int Problem09465(void)
{
	int num, round;
	int **D;
	int **P;
	scanf("%d", &round);
	long long *result;
	result = (long long*)malloc(sizeof(long long)*round);

	for (int R = 0; R < round; R++)
	{
		scanf("%d", &num);
		D = (int**)malloc(sizeof(int*)*3);
		P = (int**)malloc(sizeof(int*)*3);
		for (int i = 0; i < 3; i++)
		{
			D[i] = (int*)malloc(sizeof(int) * (num + 1));
			P[i] = (int*)malloc(sizeof(int) * (num + 1));
		}
		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				scanf("%d", &P[i][j]);
			}
		}
		D[0][0] = 0;
		D[1][0] = 0;
		D[2][0] = 0;
		for (int i = 1; i <= num; i++)
		{
			D[0][i] = D[0][i - 1];
			if (D[0][i] < D[1][i - 1])
			{
				D[0][i] = D[1][i - 1];
			}
			else if(D[0][i] < D[2][i - 1])
			{
				D[0][i] = D[2][i - 1];
			}
			
			D[1][i] = D[0][i - 1] + P[1][i];
			if(D[1][i] <  D[2][i - 1] + P[1][i])
			{
				D[1][i] = D[2][i - 1] + P[1][i];
			}
			
			D[2][i] = D[0][i - 1] + P[2][i];
			if (D[2][i] <  D[1][i - 1] + P[2][i])
			{
				D[2][i] = D[1][i - 1] + P[2][i];
			}
		}
	
		
		result[R] = D[0][num];
		if (result[R] < D[1][num])
		{
			result[R] = D[1][num];
		}
		if (result[R] < D[2][num])
		{
			result[R] = D[2][num];
		}
		for (int i = 0; i <3; i++)
		{
			free(D[i]);
			free(P[i]);
		}
		free(D);
		free(P);
	}
	for (int R = 0; R < round; R++)
	{
		printf("%lld\n", result[R]);
	}
	free(result);
	return 0;
}