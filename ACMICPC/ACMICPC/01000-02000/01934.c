#pragma warning (disable:4996)
#include <stdio.h>

int Problem01934(void)
{
	int round;
	int a, b;
	int a_t, b_t;
	int result;

	scanf("%d", &round);

	for (int i = 0; i<round;i++)
	{
		scanf("%d %d", &a, &b);
		a_t = a;
		b_t = b;
		while (1)
		{
			result = a_t % b_t;
			if (result == 0)
				break;
			a_t = b_t;
			b_t = result;
		}

		printf("%d\n", b_t * a / b_t * b / b_t);
	}
	return 0;
}