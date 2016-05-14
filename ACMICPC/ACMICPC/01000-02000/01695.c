#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem01695(void)
{
    int nSize = 0;
    int nResult = 0;
    int *p_nOrg = NULL;
    int *p_nRev = NULL;
    int **pp_nOrgRev_DP = NULL;

    scanf("%d", &nSize);

    p_nOrg = (int*)malloc(sizeof(int)*(nSize + 1));
    p_nRev = (int*)malloc(sizeof(int)*(nSize + 1));
    memset(p_nOrg, 0, sizeof(int)*(nSize + 1));
    memset(p_nRev, 0, sizeof(int)*(nSize + 1));
    pp_nOrgRev_DP = (int**)malloc(sizeof(int*)*(nSize + 1));
    for(int i = 0; i <= nSize; i++)
    {
        pp_nOrgRev_DP[i] = (int*)malloc(sizeof(int)*(nSize + 1));
        memset(pp_nOrgRev_DP[i], 0, sizeof(int)*(nSize + 1));
    }

    for(int i = 1; i <=nSize; i++)
    {
        scanf("%d", &p_nOrg[i]);
        p_nRev[nSize - i+1] = p_nOrg[i];
    }

    for(int i = 1; i <= nSize; i++)
    {
        for(int j = 1; j <= nSize; j++)
        {
            if(p_nOrg[i] == p_nRev[j])
            {
                pp_nOrgRev_DP[i][j] = pp_nOrgRev_DP[i - 1][j - 1] + 1;
            }
            else
            {
                pp_nOrgRev_DP[i][j] = pp_nOrgRev_DP[i - 1][j];
                if(pp_nOrgRev_DP[i][j] < pp_nOrgRev_DP[i][j - 1])
                {
                    pp_nOrgRev_DP[i][j] = pp_nOrgRev_DP[i][j - 1];
                }
            }
        }
    }
    nResult = pp_nOrgRev_DP[nSize][nSize];

    printf("%d\n", nSize - nResult);

    free(p_nOrg);
    free(p_nRev);
    for(int i = 0; i <= nSize; i++)
    {
        free(pp_nOrgRev_DP[i]);
    }
    free(pp_nOrgRev_DP);

    return 0;
}