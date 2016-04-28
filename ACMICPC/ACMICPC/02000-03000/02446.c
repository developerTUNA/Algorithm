#pragma warning (disable:4996)
#include <stdio.h>

int Problem02446(void)
{
    int nNum = 0;
    scanf("%d", &nNum);
    for (int i = 0; i < nNum-1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < (nNum-i)*2-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 0; i < nNum-1; i++)
    {
        printf(" ");
    }
    printf("*\n");

    for (int i = 0; i < nNum - 1; i++)
    {
        for (int j = i; j < nNum-2; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i*2+2; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}