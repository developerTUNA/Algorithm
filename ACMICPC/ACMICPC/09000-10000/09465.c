#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
int Problem09465(void)
{
	int num, round;
	int **D;
	int **P;
	scanf("%d", &round);
	int *result;
	result = (int*)malloc(sizeof(int)*round);

	for (int R = 0; R < round; R++)
	{
		scanf("%d", &num);
		D = (int**)malloc(sizeof(int*)*(num + 1));
		P = (int**)malloc(sizeof(int*)*(num + 1));
		for (int i = 0; i <= num; i++)
		{
			D[i] = (int*)malloc(sizeof(int) * 3);
			P[i] = (int*)malloc(sizeof(int) * 3);
		}
		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				scanf("%d", &P[j][i]);
			}
		}
		D[0][0] = 0;
		D[0][1] = 0;
		D[0][2] = 0;

		for (int i = 1; i <= num; i++)
		{
			D[i][0] = D[i - 1][0];
			if (D[i][0] < D[i - 1][1])
			{
				D[i][0] = D[i - 1][1];
			}
			if(D[i][0] < D[i - 1][2])
			{
				D[i][0] = D[i - 1][2];
			}
			
			D[i][1] = D[i - 1][0] + P[i][1];
			if(D[i][1] <  D[i - 1][2] + P[i][1])
			{
				D[i][1] =  D[i - 1][2] + P[i][1];
			}
			
			D[i][2] = D[i - 1][0] + P[i][2];
			if (D[i][2] <  D[i - 1][1] + P[i][2])
			{
				D[i][2] = D[i - 1][1] + P[i][2];
			}
		}
	
		
		result[R] = D[num][0];
		if (result[R] < D[num][1])
		{
			result[R] = D[num][1];
		}
		if (result[R] < D[num][2])
		{
			result[R] = D[num][2];
		}
		for (int i = 0; i <=num; i++)
		{
			free(D[i]);
			free(P[i]);
		}
		free(D);
		free(P);
	}
	for (int R = 0; R < round; R++)
	{
		printf("%d\n", result[R]);
	}
	free(result);
	return 0;
}