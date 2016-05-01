#pragma warning(disable:4996)
#include <stdio.h>

int Problem03046(void)
{
    int nR1 = 0;
    int nR2 = 0;
    int nS = 0;

    scanf("%d %d", &nR1, &nS);
    nR2 = 2 * nS - nR1;
    printf("%d\n", nR2);
    return 0;
}