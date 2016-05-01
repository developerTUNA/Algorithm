#pragma warning (disable:4996)
#include <stdio.h>

int Problem02475(void)
{
    int num;
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num);
        result += (num*num) % 10;
    }
    result %= 10;
    printf("%d\n", result);

    return 0;
}