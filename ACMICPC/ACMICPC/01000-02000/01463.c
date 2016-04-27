#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Problem01463(void)
{
    int num;
    int *D;
    scanf("%d", &num);
    D = (int *)malloc(sizeof(int)*(num + 1));
    D[0] = 0;
    D[1] = 0;
    D[2] = 1;
    D[3] = 1;
    for (int i = 4; i <= num; i++)
    {
        D[i] = D[i - 1] + 1;
        if (i % 3 == 0 && D[i] > D[i / 3])
        {
            D[i] = D[i / 3] + 1;
        }
        if (i % 2 == 0 && D[i] > D[i / 2])
        {
            D[i] = D[i / 2] + 1;
        }
    }
    printf("%d\n", D[num]);

    return 0;
}