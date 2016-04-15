#pragma warning (disable:4996)
#include <stdio.h>

int Problem01085(void)
{
	int x, y, w, h;
	int min;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	min = x;
	if (min > w - x)
	{
		min = w - x;
	}
	if (min > y)
	{
		min = y;
	}
	if (min > h - y)
	{
		min = h - y;
	}
	
	printf("%d\n", min);
	return 0;
}