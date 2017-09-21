#include <stdio.h>

int PrintIntArray1(int *p_nArray, int nBegin, int nEnd)
{
	for (int i = nBegin; i <= nEnd; i++)
	{
		printf("%d ", p_nArray[i]);
	}
	printf("\n");
	return 0;
}
int PrintIntArray2(int **pp_nArray, int nRowBegin, int nRowEnd, int nColBegin, int nColEnd)
{
	for (int i = nRowBegin; i <= nRowEnd; i++)
	{
		for (int j = nColBegin; j <= nColEnd; j++)
		{
			printf("%d ", pp_nArray[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int main(void)
{
	Problem01759();
    return 0;
}