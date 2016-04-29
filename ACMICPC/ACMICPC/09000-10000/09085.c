#pragma warning (disable:4996)
#include <stdio.h>

int Problem09085(void)
{
    int nRound = 0;
    int nCount = 0;
    int nSum = 0;
    int nGet = 0;

    scanf("%d", &nRound);
    for(int i = 0; i < nRound; i++)
    {
        scanf("%d", &nCount);
        nSum = 0;
        for(int j = 0; j < nCount; j++)
        {
            scanf("%d", &nGet);
            nSum += nGet;
        }
        printf("%d\n", nSum);
    }
    return 0;
}