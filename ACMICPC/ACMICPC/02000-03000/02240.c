#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02240(void)
{
    int nTime = 0;
    int nMove = 0;
    int *p_nDropTime = NULL;

    scanf("%d %d", &nTime, &nMove);
    p_nDropTime = (int*)malloc(sizeof(int)*(nTime + 1));
    for(int i = 1; i <= nTime; i++)
    {
        scanf("%d", &p_nDropTime[i]);
    }

    free(p_nDropTime);
    return 0;
}