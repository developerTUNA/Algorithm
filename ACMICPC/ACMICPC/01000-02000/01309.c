#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem01309(void)
{
    int nSize = 0;
    int nResult = 0;
    int **pp_nRoom = NULL;

    scanf("%d", &nSize);
    pp_nRoom = (int **)malloc(sizeof(int *)*nSize);
    for(int i = 0; i < nSize; i++)
    {
        pp_nRoom[i] = (int *)malloc(sizeof(int) * 3);
        memset(pp_nRoom[i], 0, sizeof(int) * 3);
    }

    pp_nRoom[0][0] = 1;
    pp_nRoom[0][1] = 1;
    pp_nRoom[0][2] = 1;

    for(int i = 1; i < nSize; i++)
    {
        pp_nRoom[i][0] = pp_nRoom[i - 1][0] + pp_nRoom[i - 1][1] + pp_nRoom[i - 1][2];
        pp_nRoom[i][1] = pp_nRoom[i - 1][0] + pp_nRoom[i - 1][2];
        pp_nRoom[i][2] = pp_nRoom[i - 1][0] + pp_nRoom[i - 1][1];
        pp_nRoom[i][0] %= 9901;
        pp_nRoom[i][1] %= 9901;
        pp_nRoom[i][2] %= 9901;
    }

    nResult = pp_nRoom[nSize - 1][0] + pp_nRoom[nSize - 1][1] + pp_nRoom[nSize - 1][2];
    nResult %= 9901;
    printf("%d\n", nResult);
    return 0;
}