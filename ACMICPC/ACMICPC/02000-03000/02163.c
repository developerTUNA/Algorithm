#pragma warning (disable:4996)
#include <stdio.h>
int Problem02163(void)
{
	int nRow = 0, nCol = 0;
	scanf("%d %d", &nRow, &nCol);
	printf("%d\n", nRow*nCol - 1);
	return 0;
}