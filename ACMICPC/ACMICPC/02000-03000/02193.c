#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
int Problem02193(void)
{
    int num;
    long long **D;

    scanf("%d", &num);

    D = (long long**)malloc(sizeof(long long*)*(num + 1));
    for (int i = 0; i <= num; i++)
    {
        D[i] = (long long*)malloc(sizeof(long long) * 2);
    }
    D[1][0] = 0;
    D[1][1] = 1;
    for (int i = 2; i <= num; i++)
    {
        D[i][0] = D[i - 1][0] + D[i - 1][1];
        D[i][1] = D[i - 1][0];
    }

    long long sum;
    sum = D[num][0] + D[num][1];

    printf("%lld\n", sum);
    return 0;
}