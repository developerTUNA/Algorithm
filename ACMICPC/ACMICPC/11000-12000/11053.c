#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem11053(void)
{
	int nLen = 0;
	int *arrNum = NULL;
	int *arrDP = NULL;
	scanf("%d", &nLen);
	arrNum = (int*)malloc(sizeof(int)*(nLen + 1));
	memset(arrNum, 0, sizeof(int)*(nLen + 1));
	arrDP = (int*)malloc(sizeof(int)*(nLen + 1));
	memset(arrDP, 0, sizeof(int)*(nLen + 1));
	for (int i = 1; i <= nLen; i++)
	{
		scanf("%d", &arrNum[i]);
	}

	arrDP[0] = 1;
	for (int i = 1; i <= nLen; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arrDP[i] < arrDP[j] && arrNum[j] < arrNum[i])
			{
				arrDP[i] = arrDP[j] + 1;
			}
		}
	}

	return 0;
}