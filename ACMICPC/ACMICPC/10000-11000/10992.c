#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem10992(void)
{
    int nCount = 0;
    scanf("%d", &nCount);

    for (int i = 1; i <= nCount; i++)
    {
        if (i == 1)
        {
            for (int j = 0; j < nCount - i; j++)
            {
                printf(" ");
            }
            printf("*");
        }
        else if (i == nCount )
        {
            for (int j = 0; j < 2*nCount-1 ; j++)
            {
                printf("*");
            }
        }
        else{
            for (int j = 0; j < nCount - i; j++)
            {
                printf(" ");
            }
            printf("*");
            for (int j = 0; j < 2*i-3; j++)
            {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}