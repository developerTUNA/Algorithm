#pragma warning (disable:4996)
#include <stdio.h>

int Problem10797(void)
{
    int nDay = 0;
    int nCount = 0;
    int nCar = 0;

    scanf("%d", &nDay);
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &nCar);
        if(nCar == nDay)
        {
            nCount++;
        }
    }
    printf("%d\n", nCount);
    
    return 0;
}