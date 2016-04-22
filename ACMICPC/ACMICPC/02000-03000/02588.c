#pragma warning(disable:4996)
#include <stdio.h>

int Problem02588(void)
{
	int nNum1 = 0;
	int nNum2 = 0;
	
	scanf("%d %d", &nNum1, &nNum2);
	printf("%d\n", nNum1 * (nNum2 % 10));
	printf("%d\n", nNum1 * ((nNum2 / 10) % 10));
	printf("%d\n", nNum1 * (nNum2 / 100));
	printf("%d\n", nNum1 * nNum2);
	
	return 0;
}