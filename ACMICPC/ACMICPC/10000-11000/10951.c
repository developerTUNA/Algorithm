#pragma warning (disable:4996)
#include <stdio.h>

int Problem10951(void)
{
    int nA = 0;
    int nB = 0;

    while(scanf("%d %d", &nA, &nB)  == 2)
    {
        printf("%d\n", nA + nB);
    }
    return 0;
}