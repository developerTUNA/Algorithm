#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)<(b)?(b):(a))

int Problem02579(void)
{
    int nCount = 0;
    int *p_nStap = NULL;
    int **pp_nStap_DP = NULL;

    scanf("%d", &nCount);
    p_nStap = (int*)malloc(sizeof(int)*nCount);
    pp_nStap_DP = (int**)malloc(sizeof(int*)*nCount);
    for(int i = 0; i < nCount; i++)
    {
        pp_nStap_DP[i] = (int*)malloc(sizeof(int) * 3);
    }
    for(int i = 0; i < nCount; i++)
    {
        scanf("%d", &p_nStap[i]);
    }

    pp_nStap_DP[0][0] = 0;
    pp_nStap_DP[0][1] = p_nStap[0];
    pp_nStap_DP[0][2] = p_nStap[0];

    for(int i = 1; i < nCount; i++)
    {
        pp_nStap_DP[i][0] = MAX(MAX(pp_nStap_DP[i - 1][0], pp_nStap_DP[i - 1][1]), pp_nStap_DP[i - 1][2]);
        pp_nStap_DP[i][1] = pp_nStap_DP[i - 1][0] + p_nStap[i];
        pp_nStap_DP[i][2] = pp_nStap_DP[i - 1][1] + p_nStap[i];
    }
    printf("%d\n", MAX(pp_nStap_DP[nCount - 1][1], pp_nStap_DP[nCount - 1][2]));

    for(int i = 0; i < nCount; i++)
    {
        free(pp_nStap_DP[i]);
    }
    free(pp_nStap_DP);
    free(p_nStap);
    return 0;
}