#pragma warning(disable:4996)
#include <stdio.h>

int Problem02525(void)
{
    int nNowMin = 0;
    int nNowHour = 0;
    int nCookMin = 0;

    scanf("%d %d", &nNowHour, &nNowMin);
    scanf("%d", &nCookMin);

    nNowMin = nNowMin + nCookMin;
    nNowHour = (nNowHour + (nNowMin / 60)) % 24;
    nNowMin %= 60;

    printf("%d %d\n", nNowHour, nNowMin);
    return 0;
}