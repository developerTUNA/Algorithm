#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01102(void)
{
    int nPowerstation = 0;
    int nGoal = 0;
    int nStart = 0;
    int nResult = 0;
    int * p_nCost_DP = NULL;
    int ** pp_nCost = NULL;

    scanf("%d", &nPowerstation);

    pp_nCost = (int**)malloc(sizeof(int*)*(nPowerstation));
    for(int i = 0; i < nPowerstation; i++)
    {
        pp_nCost[i] = (int*)malloc(sizeof(int)*(nPowerstation));
        memset(pp_nCost[i], 0, sizeof(int)*(nPowerstation));
    }
    for(int i = 0; i < nPowerstation; i++)
    {
        for(int j = 0; j < nPowerstation; j++)
        {
            scanf("%d ", &pp_nCost[i][j]);
        }
    }

    p_nCost_DP = (int*)malloc(sizeof(int)*(1 << nPowerstation));
    memset(p_nCost_DP, -1, sizeof(int)*(1 << nPowerstation));


    for(int i = 0; i < nPowerstation; i++)
    {
        char cTemp = 0;
        scanf("%c", &cTemp);
        if(cTemp == 'Y')
        {
            nStart |= (1 << i);
        }
    }
    p_nCost_DP[nStart] = 0;
    scanf("%d", &nGoal);
    for(int i = 0; i < (1 << nPowerstation); i++)
    {
        if(p_nCost_DP[i] == -1)
        {
            continue;
        }
        for(int j = 0; j < nPowerstation; j++)
        {
            if(i&(1 << j))
            {
                for(int k = 0; k < nPowerstation; k++)
                {
                    if(!(i&(1 << k)))
                    {
                        if(p_nCost_DP[i | (1 << k)] == -1 || p_nCost_DP[i] + pp_nCost[j][k] < p_nCost_DP[i | (1 << k)])
                            p_nCost_DP[i | (1 << k)] = p_nCost_DP[i] + pp_nCost[j][k];
                    }
                }
            }
        }
    }

    nResult = -1;
    for(int i = 0; i < (1 << nPowerstation); i++)
    {
        int nOn_Count = 0;
        if(p_nCost_DP[i] == -1)
        {
            continue;
        }
        for(int j = 0; j < nPowerstation; j++)
        {
            if(i&(1 << j))
            {
                nOn_Count++;
            }
        }
        if(nGoal <= nOn_Count)
        {
            if(nResult == -1 || nResult < p_nCost_DP[i])
            {
                nResult = p_nCost_DP[i];
            }
        }
    }

    printf("%d\n", nResult);

    for(int i = 0; i < nPowerstation; i++)
    {
        free(pp_nCost[i]);
    }
    free(pp_nCost);
    free(p_nCost_DP);
    return 0;
}