#pragma warning (disable:4996)
#include <stdio.h>

int Problem10818(void)
{
    int nNum = 0;
    int nNumCount = 0;
    int nMax = -1000001;
    int nMin = 1000001;

    scanf("%d", &nNumCount);

    for(int i = 0; i < nNumCount; i++)
    {
        scanf("%d", &nNum);
        if(nMax < nNum)
        {
            nMax = nNum;
        }
        if(nNum < nMin)
        {
            nMin = nNum;
        }
    }

    printf("%d %d", nMin, nMax);
    return 0;
}