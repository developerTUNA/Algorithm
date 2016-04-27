#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Problem10844(void)
{
    int num;
    long long **D;

    scanf("%d", &num);
    D = (long long**)malloc(sizeof(long long*)*(num+1));
    for (int i = 0; i <= num; i++)
    {
        D[i] = (long long*)malloc(sizeof(long long) * 10);
    }

    D[1][0] = 0;
    for (int i = 1; i <= 9; i++)
    {
        D[1][i] = 1;
    }
    

    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                D[i][j] = D[i - 1][j + 1];
            }
            else if (j == 9)
            {
                D[i][j] = D[i - 1][j - 1];
            }
            else
            {
                D[i][j] = D[i - 1][j + 1] + D[i - 1][j - 1];
            }
            D[i][j] = D[i][j] % 1000000000;
        }
    }

    long long sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        sum += D[num][i];
    }
    sum = sum%1000000000;
    printf("%d\n", (int)sum);
    return 0;
}