#pragma warning (disable:4996)
#include <stdio.h>

int Problem01009(void)
{
	int round;
	int result;
	int a, b;
	scanf("%d", &round);
	
	for (int i = 0; i < round; i++)
	{
		scanf("%d %d", &a, &b);
		result = 1;
		for (int j = 0; j < b; j++)
		{
			result = (a*result) % 10;
		}
		if (result == 0)
			result = 10;
		printf("%d\n", result);
	}
	return 0;
}