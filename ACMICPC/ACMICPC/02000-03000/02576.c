#pragma warning (disable:4996)
#include <stdio.h>

int Problem02576(void)
{
    int nNum = 0;
    int nSum = 0;
    int nMin = 101;

    for(int i = 0; i < 7; i++)
    {
        scanf("%d", &nNum);
        if(nNum % 2)
        {
            nSum += nNum;
            if(nNum < nMin)
            {
                nMin = nNum;
            }
        }
    }
    if(nSum)
    {
        printf("%d\n", nSum);
        printf("%d\n", nMin);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}