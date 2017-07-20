#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem13398(void)
{
	int nSize = 0;
	int nMax = 0;
	int *p_nNum = NULL;
	int *p_nLeft_DP = NULL;
	int *p_nRight_DP = NULL;
	
	scanf("%d", &nSize);
	p_nNum = (int*)malloc(sizeof(int)*(nSize));
	memset(p_nNum, 0, sizeof(int)*(nSize));
	p_nLeft_DP = (int*)malloc(sizeof(int)*(nSize));
	memset(p_nLeft_DP, 0, sizeof(int)*(nSize));
	p_nRight_DP = (int*)malloc(sizeof(int)*(nSize));
	memset(p_nRight_DP, 0, sizeof(int)*(nSize));

	for (int i = 0; i < nSize; i++)
	{
		scanf("%d", &p_nNum[i]);
	}

	p_nLeft_DP[0] = p_nNum[0];
	for (int i = 1; i < nSize; i++)
	{
		if (p_nNum[i] < p_nLeft_DP[i - 1] + p_nNum[i])
		{
			p_nLeft_DP[i] = p_nLeft_DP[i - 1] + p_nNum[i];
		}
		else
		{
			p_nLeft_DP[i] = p_nNum[i];
		}
	}
	p_nRight_DP[nSize-1] = p_nNum[nSize-1];
	for (int i = nSize-2; 0 <=i ; i--)
	 {
		if (p_nNum[i] < p_nRight_DP[i + 1] + p_nNum[i])
		{
			p_nRight_DP[i] = p_nRight_DP[i + 1] + p_nNum[i];
		}
		else
		{
			p_nRight_DP[i] = p_nNum[i];
		}
	}
	nMax = p_nLeft_DP[0];
	for (int i = 1; i < nSize; i++)
	{
		if (nMax < p_nLeft_DP[i])
		{
			nMax = p_nLeft_DP[i];
		}
	}
	for (int i = 0; i < nSize-2; i++)
	{
		if (nMax < p_nLeft_DP[i] + p_nRight_DP[i + 2])
		{
			nMax = p_nLeft_DP[i] + p_nRight_DP[i + 2];
		}
	}

	printf("%d\n", nMax);

	free(p_nNum);
	free(p_nLeft_DP);
	free(p_nRight_DP);
	return 0;
}