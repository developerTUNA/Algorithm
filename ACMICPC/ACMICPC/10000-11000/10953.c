#pragma warning (disable:4996)
#include <stdio.h>

int Problem10953(void)
{
    int nCount = 0;
    int nA = 0;
    int nB = 0;
    int nResult = 0;

    scanf("%d", &nCount);
    for(int i = 0; i < nCount; i++)
    {
        scanf("%d,%d", &nA, &nB);
        nResult = nA + nB;
        printf("%d\n", nResult);
    }

    return 0;
}