#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Problem02753(void)
{
	int nYear;
	scanf("%d", &nYear);
	if (nYear % 400 == 0)
	{
		printf("1\n");
	}
	else if (nYear % 4 == 0 && nYear % 100 != 0)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
	return 0;
}