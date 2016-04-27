#pragma warning (disable:4996)
#include <stdio.h>

int Problem02609(void)
{
    int a, b;
    int a_t, b_t;
    int result;
    int min, max;

    scanf("%d %d", &a, &b);
    a_t = a;
    b_t = b;
    while (1)
    {
        result = a_t % b_t;
        if (result == 0)
            break;
        a_t = b_t;
        b_t = result;
    }

    min = b_t;
    max = min * a / min * b / min;

    printf("%d\n%d\n", min, max);
    return 0;
}