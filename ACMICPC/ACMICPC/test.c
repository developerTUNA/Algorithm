#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int test(void)
{
	int nType = 0;
	int nSize = 0;
	int *p_nWeight = NULL;
	int *p_nPrize = NULL;
	int *p_nDP_Prize = NULL;

	scanf("%d %d", &nType, &nSize);
	p_nPrize = malloc(sizeof(int)*(nType));
	memset(p_nPrize, 0, sizeof(int)*(nType));
	p_nWeight = malloc(sizeof(int)*(nType));
	memset(p_nWeight, 0, sizeof(int)*(nType));

	p_nDP_Prize = malloc(sizeof(int)*(nSize+1));
	memset(p_nDP_Prize, 0, sizeof(int)*(nSize+1));
	
	for (int i = 0; i < nType; i++)
	{
		scanf("%d %d",&p_nWeight[i], &p_nPrize[i]);
	}

	for (int i = 0; i < nType; i++)
	{
		for (int j = p_nWeight[i]; j <= nSize; j++)
		{
			if (p_nDP_Prize[j] < p_nDP_Prize[j - p_nWeight[i]] + p_nPrize[i])
			{
				p_nDP_Prize[j] = p_nDP_Prize[j - p_nWeight[i]] + p_nPrize[i];
			}
		}
	}

	printf("%d\n", p_nDP_Prize[nSize]);
	free(p_nPrize);
	free(p_nWeight);
	free(p_nDP_Prize);

    return 0;
}
    

int test2(void)
{
	int nType = 0;
	int nSize = 0;
	int *p_nWeight = NULL;
	int *p_nPrize = NULL;
	int **pp_nDP_Prize = NULL;

	scanf("%d %d", &nType, &nSize);
	p_nPrize = malloc(sizeof(int)*(nType));
	memset(p_nPrize, 0, sizeof(int)*(nType));
	p_nWeight = malloc(sizeof(int)*(nType));
	memset(p_nWeight, 0, sizeof(int)*(nType));

	pp_nDP_Prize = malloc(sizeof(int*)*(nSize + 1));
	memset(pp_nDP_Prize, 0, sizeof(int*)*(nSize + 1));
	for (int i = 0; i <= nSize; i++)
	{
		pp_nDP_Prize[i] = malloc(sizeof(int*)*(nType));
		memset(pp_nDP_Prize[i], 0, sizeof(int*)*(nType));
	}

	for (int i = 0; i < nType; i++)
	{
		scanf("%d %d", &p_nWeight[i], &p_nPrize[i]);
	}

	for (int i = 1; i <= nSize; i++)
	{
		for (int j = 0; j < nType; j++)
		{
			if (i < p_nWeight[j])
			{
				pp_nDP_Prize[i][j] = pp_nDP_Prize[i][j-1];
			}
			else
			{
				if (pp_nDP_Prize[i][j-1] < pp_nDP_Prize[i - p_nWeight[j]][j] + p_nPrize[j])
				{
					pp_nDP_Prize[i][j] = pp_nDP_Prize[i - p_nWeight[j]][j] + p_nPrize[j];
				}
				else
				{
					pp_nDP_Prize[i][j] = pp_nDP_Prize[i][j-1];
				}
			}
		}
	}

	printf("%d\n", pp_nDP_Prize[nSize][nType - 1]);

	free(p_nPrize);
	free(p_nWeight);
	for (int i = 0; i <= nSize; i++)
	{
		free(pp_nDP_Prize[i]);
	}
	free(pp_nDP_Prize);
	return 0;
}