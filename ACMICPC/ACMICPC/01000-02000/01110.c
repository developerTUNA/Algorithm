#pragma warning (disable:4996)
#include <stdio.h>

int Problem01110(void)
{
	int start = 0;
	int num = 0;
	int count = 0;
	int x = 0, y = 0;

	scanf("%d", &start);
	num = start;
	while (1)
	{
		x = num % 10;
		y = (num / 10 + num % 10) % 10;
		num = x*10 + y;
		count++;
		if (start == num)
			break;
	}
	printf("%d\n", count);

	return 0;
}