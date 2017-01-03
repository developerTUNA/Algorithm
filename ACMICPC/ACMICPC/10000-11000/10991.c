#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem10991(void)
{
    int nCount = 0;
    scanf("%d", &nCount);

    for (int i = 0; i < nCount; i++)
    {
        for (int j = 1; j < nCount-i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("*");
            if (j != i)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}