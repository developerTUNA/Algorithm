#pragma warning (disable:4996)
#include <stdio.h>

int Problem02490(void)
{
    int nCount = 0;
    for(int i = 0; i < 3; i++)
    {
        nCount = 0;
        for(int j = 0; j < 4; j++)
        {
            int nGet = 0;
            scanf("%d", &nGet);
            nCount += nGet;
        }
        if(nCount == 3)
        {
            printf("A\n");
        }
        else if(nCount == 2)
        {
            printf("B\n");
        }
        else if(nCount == 1)
        {
            printf("C\n");
        }
        else if(nCount == 0)
        {
            printf("D\n");
        }
        else if(nCount == 4)
        {
            printf("E\n");
        }

    }
    return 0;
}