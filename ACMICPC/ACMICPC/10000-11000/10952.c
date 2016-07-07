#pragma warning (disable:4996)
#include <stdio.h>

int Problem10952(void)
{
    int nA = 0;
    int nB = 0;
    int nResult = 0;

    while(1)
    {
        scanf("%d %d", &nA, &nB);
        if(nA == 0 && nB == 0)
        {
            break;
        }
        nResult = nA + nB;
        printf("%d\n", nResult);
    }

    return 0;
}