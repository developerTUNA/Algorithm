#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Problem11052(void)
{
    int num;
    int *prise;
    int *D;

    scanf("%d", &num);
    prise = (int*)malloc(sizeof(int)*(num + 1));
    D = (int*)malloc(sizeof(int)*(num + 1));
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &prise[i]);
    }
    
    D[0] = 0;
    D[1] = prise[1];

    for (int i = 2; i <= num; i++)
    {
        D[i] = 0;
        for (int j = 1; j <= i; j++)
        {
            if (D[i] < prise[j] + D[i - j])
            {
                D[i] = prise[j] + D[i - j];
            }
        }
    }
    printf("%d\n", D[num]);
    free(prise);
    free(D);
    return 0;
}