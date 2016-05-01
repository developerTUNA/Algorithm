#pragma warning(disable:4996)
#include <stdio.h>

int Problem02522(void)
{
    int nNum = 0;
    scanf("%d", &nNum);
    for (int i = 1; i < nNum ; i++)
    {
        for (int j = i; j < nNum; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 0; i < nNum; i++)
    {
        printf("*");
    }
    printf("\n");
    for (int i = 1; i < nNum; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j = i; j < nNum; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}