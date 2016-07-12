#pragma warning (disable:4996)
#include <stdio.h>

int Problem02523(void)
{
    int nNum = 0;
    
    scanf("%d",&nNum);

    for(int i = 1; i <= nNum; i++)
    {
        for(int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(int i = nNum - 1; 0 < i; i--)
    {
        for(int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}