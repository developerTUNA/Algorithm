#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int QsortFunction_01026_inc(const void *a, const void *b)
{
	int nA = *(int *)a;
	int nB = *(int *)b;
	if (nA > nB)
		return 1;
	else if (nA < nB)
		return -1;
	else
		return 0;
}

int QsortFunction_01026_dec(const void *a, const void *b)
{
	int nA = *(int *)a;
	int nB = *(int *)b;
	if (nA < nB)
		return 1;
	else if (nA > nB)
		return -1;
	else
		return 0;
}

int Problem01026(void)
{
	int num;
	int *A, *B;
	int sum;

	scanf("%d", &num);
	A = (int*)malloc(sizeof(int)*num);
	B = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &B[i]);
	}

	qsort(A, num, sizeof(int), QsortFunction_01026_inc);
	qsort(B, num, sizeof(int), QsortFunction_01026_dec);

	sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += A[i] * B[i];
	}

	printf("%d\n", sum);
	return 0;
}
