#pragma warning (disable:4996)
#include <stdio.h>

int Problem11022(void)
{
    int nCase = 0;
    int nA = 0;
    int nB = 0;
    int nResult = 0;

    scanf("%d", &nCase);
    for(int i = 1; i <= nCase; i++)
    {
        scanf("%d %d", &nA, &nB);
        nResult = nA + nB;
        printf("Case #%d: %d + %d = %d\n", i, nA, nB, nResult);
    }
    return 0;
}