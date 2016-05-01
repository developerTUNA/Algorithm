#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
int Problem02010(void)
{
    int nPlug = 0;
    int nSize = 0;
    int nTotal = 1;

    scanf("%d", &nPlug);
    for (int i = 0; i < nPlug; i++)
    {
        scanf("%d", &nSize);
        nTotal += nSize - 1;
    }
    printf("%d\n", nTotal);
    return 0;
}