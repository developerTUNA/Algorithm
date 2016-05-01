#pragma warning(disable:4996)
#include <stdio.h>

int Problem05565(void)
{
    int nTotal=0;
    int nGet=0;
    scanf("%d", &nTotal);
    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &nGet);
        nTotal -= nGet;
    }
    printf("%d\n", nTotal);
    return 0;
}