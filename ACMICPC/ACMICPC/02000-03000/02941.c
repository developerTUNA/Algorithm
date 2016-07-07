#pragma warning (disable:4996)
#include <stdio.h>

int Problem02941(void)
{
    int nA = 0;
    int nB = 0;
    int nResult = 0;

    scanf("%d %d", &nA, &nB);
    nResult = nA * nB - nA + 1;
    printf("%d\n", nResult);

    return 0;
}