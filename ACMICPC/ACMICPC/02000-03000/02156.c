#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
int Problem02156(void)
{
    int num;
    int *D;
    int *P;

    scanf("%d", &num);
    D = (int *)malloc(sizeof(int)*(num+1));
    P = (int *)malloc(sizeof(int)*(num+1));
    
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &P[i]);
    }
    D[0] = 0;
    D[1] = P[1];
    D[2] = P[1] + P[2];

    for (int i = 3; i <= num; i++)
    {
        D[i] = D[i - 1];
        if (D[i] < P[i] + D[i - 2])
        {
            D[i] = P[i] + D[i - 2];
        }
        if (D[i] < P[i] + P[i - 1] + D[i - 3])
        {
            D[i] = P[i] + P[i - 1] + D[i - 3];
        }
    }
    printf("%d\n", D[num]);
    free(D);
    free(P);
    return 0;
}