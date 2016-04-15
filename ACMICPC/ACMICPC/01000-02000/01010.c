#pragma warning (disable:4996)
#include <stdio.h>

int Problem01010(void)
{
	int round;
	int a, b;
	int mid;
	long long result;
	scanf("%d", &round);

	for (int i = 0; i < round; i++)
	{
		scanf("%d %d", &a, &b);
		
		mid = a;
		if (a < b - a)
		{
			mid = b - a;
		}
		result = 1;
		for (int j = mid +1; j <= b; j++)
		{
			result *= j;
		}

		for (int j = 1; j <= b - a; j++)
		{
			result /= j;
		}

		printf("%lld\n", result);
	}
	return 0;
}