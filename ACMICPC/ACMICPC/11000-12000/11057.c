#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Problem11057(void)
{
    int num;
    int **D;

    scanf("%d", &num);
    D = (int**)malloc(sizeof(int*)*(num + 1));
    for (int i = 0; i <= num; i++)
    {
        D[i] = (int*)malloc(sizeof(int) * 10);
    }

    for (int i = 0; i <= 9; i++)
    {
        D[1][i] = 1;
    }


    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            D[i][j] = 0;
            for (int k = 0; k <= j; k++)
            {
                D[i][j] += D[i - 1][k];
            }
            D[i][j] %= 10007;
        }
    }

    int sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        sum += D[num][i];
    }
    sum = sum % 10007;
    printf("%d\n", (int)sum);
    return 0;
}