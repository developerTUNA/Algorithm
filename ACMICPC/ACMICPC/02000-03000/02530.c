#pragma warning (disable:4996)
#include <stdio.h>

int Problem02530(void)
{
    int nHour = 0;
    int nMin = 0;
    int nSec = 0;
    int nCookingSec = 0;
    int nTotalSec = 0;

    scanf("%d %d %d", &nHour, &nMin, &nSec);
    scanf("%d", &nCookingSec);
    nTotalSec = nHour * 60 * 60 + nMin * 60 + nSec + nCookingSec;

    nTotalSec = nTotalSec % (24 * 60 * 60);
    nHour = nTotalSec / (60 * 60);
    nMin = nTotalSec % (60 * 60)/60;
    nSec = nTotalSec % 60;

    printf("%d %d %d\n", nHour, nMin, nSec);
    return 0;
}