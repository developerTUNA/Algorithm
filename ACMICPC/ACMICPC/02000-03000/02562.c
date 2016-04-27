#pragma warning(disable:4996)
#include <stdio.h>

int Problem02562(void)
{
    int nTemp = 0;
    int nMax = 0;
    int nPos = 0;

    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &nTemp);
        if (nMax < nTemp)
        {
            nMax = nTemp;
            nPos = i;
        }
    }
    printf("%d\n%d", nMax, nPos+1);
    return 0;
}