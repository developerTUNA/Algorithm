#pragma warning (disable:4996)
#include <stdio.h>

int Problem01978(void)
{
	int arr_nPrime[1001] = { 0, };
	int nCount = 0;
	int nIn = 0;
	int nResult = 0;
	
	arr_nPrime[1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		if (arr_nPrime[i] == 0)
		{
			for (int j = 2; i*j < 1001; j++)
			{
				arr_nPrime[i*j] = 1;
			}
		}
	}
	scanf("%d", &nCount);
	for (int i = 0; i < nCount; i++)
	{
		scanf("%d", &nIn);
		if (arr_nPrime[nIn] == 0)
		{
			nResult++;
		}
	}

	printf("%d\n", nResult);
	return 0;
}