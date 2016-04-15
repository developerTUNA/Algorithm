#pragma warning (disable:4996)
#include <stdio.h>

int Problem01100(void)
{
	char str[9];
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		scanf("%s", str);
		for (int j = i%2; j < 8; j+=2)
		{
			if (str[j] == 'F')
				count++;
		}
	}
	printf("%d\n", count);
	return 0;
}