#pragma warning (disable:4996)
#include <stdio.h>

int Problem02577(void)
{
    int nMux = 0;
    int nGet = 0;
    int arr_nNumCount[10] = {0,};
    nMux = 1;
    for(int i = 0; i < 3; i++)
    {
        scanf("%d", &nGet);
        nMux *= nGet;
    }
    while(nMux != 0)
    {
        arr_nNumCount[nMux % 10]++;
        nMux /= 10;
    }
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arr_nNumCount[i]);
    }
    return 0;
}