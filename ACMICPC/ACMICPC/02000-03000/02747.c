#pragma warning(disable:4996)
#include <stdio.h>

int Problem02747(void)
{
	int nNum = 0;
	int arr_nFib[46];

	scanf("%d", &nNum);
	
	arr_nFib[1] = 1;
	arr_nFib[2] = 1;
	
	for (int i = 3; i <= nNum; i++)
	{
		arr_nFib[i] = arr_nFib[i - 1] + arr_nFib[i - 2];
	}
	printf("%d", arr_nFib[nNum]);
	
	return 0;
}