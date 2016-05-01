#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Probrem11726(void)
{
    int num;
    int *D;

    scanf("%d", &num);
    D = (int *)malloc(sizeof(int)*(num + 1));
    D[0] = 0;
    D[1] = 1;
    D[2] = 2;

    for (int i = 3; i <= num; i++)
    {
        D[i] = D[i - 1] + D[i - 2];
        D[i] = D[i] % 10007;
    }

    printf("%d\n", D[num]);
    free(D);
    return 0;
}