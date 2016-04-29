#pragma warning(disable:4996)
#include <stdio.h>

int Problem02460(void)
{
    int nMax = 0;
    int nNow = 0;
    int nIn = 0, nOut = 0;

    for(int i = 0; i < 10; i++)
    {
        scanf("%d %d", &nOut, &nIn);
        nNow -= nOut;
        if(nMax < nNow)
        {
            nMax = nNow;
        }
        nNow += nIn;
        if(nMax < nNow)
        {
            nMax = nNow;
        }
    }
    printf("%d\n", nMax);
    return 0;
}