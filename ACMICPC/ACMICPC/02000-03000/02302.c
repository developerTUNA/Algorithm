#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem02302(void)
{
    int nChair = 0;
    int nVipNum = 0;
    int nVipChair = 0;
    int nVipBefore = 0;
    int nResult = 0;
    int *p_nFibo = NULL;

    scanf("%d", &nChair);
    if(nChair == 1)
    {
        printf("1\n");
        return 0;
    }

    p_nFibo = (int*)malloc(sizeof(int)*(nChair + 1));
    memset(p_nFibo, 0, sizeof(int)*(nChair + 1));
    p_nFibo[0] = 1;
    p_nFibo[1] = 1;

    for(int i = 2; i <= nChair; i++)
    {
        p_nFibo[i] = p_nFibo[i - 1] + p_nFibo[i - 2];
    }

    nVipBefore = 0;
    nVipChair = 0;
    nResult = 1;
    scanf("%d", &nVipNum);
    for(int i = 0; i < nVipNum; i++)
    {
        scanf("%d", &nVipChair);
        nResult *= p_nFibo[nVipChair - nVipBefore - 1];
        nVipBefore = nVipChair;
    }
    nResult *= p_nFibo[nChair - nVipBefore];

    printf("%d\n", nResult);
    free(p_nFibo);
    return 0;
}