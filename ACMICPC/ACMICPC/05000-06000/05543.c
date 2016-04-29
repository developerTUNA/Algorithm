#pragma warning(disable:4996)
#include <stdio.h>

int Problem05543(void)
{
    int nHamMin = 2000;
    int nVerMin = 2000;
    int nGet = 0;
    
    for(int i = 0; i < 3; i++)
    {
        scanf("%d", &nGet);
        if(nHamMin > nGet)
        {
            nHamMin = nGet;
        }
    }
    for(int i = 0; i < 2; i++)
    {
        scanf("%d", &nGet);
        if(nVerMin > nGet)
        {
            nVerMin = nGet;
        }
    }
    printf("%d\n", nHamMin+nVerMin-50);
    return 0;
}