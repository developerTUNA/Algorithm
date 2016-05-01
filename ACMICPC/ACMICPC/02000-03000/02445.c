#pragma warning (disable:4996)
#include <stdio.h>

int Problem02445(void)
{
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            printf("*");
        }
        for (int j = 1; j <= (num - i)*2; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num-i; j++)
        {
            printf("*");
        }
        for (int j = 1; j <= i * 2; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= num-i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}