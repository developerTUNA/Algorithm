#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct CostData09023_
{
    int nCostStadium;
    int nCostHotelRent;
    int nCostHotelDay;
    int nTeamACity_Count;
    int nTeamBCity_Count;
    int arr_nTeamACity[101];
    int arr_nTeamBCity[101];
    int *****ppppp_nCostDP;
} typedef CostData09023;

int GO_DP09023(int nDay, int nTeamACity, int nTeamBCity, int nTeamARest, int nTeamBRest, CostData09023 Cost)
{
    int nResult = 0;
    int nResult_Min = 10000000;

    if(Cost.nTeamACity_Count == nTeamACity && Cost.nTeamBCity_Count == nTeamBCity)
    {
        return 0;
    }
    if(Cost.ppppp_nCostDP[nDay][nTeamACity][nTeamBCity][nTeamARest][nTeamBRest] != -1)
    {
        return Cost.ppppp_nCostDP[nDay][nTeamACity][nTeamBCity][nTeamARest][nTeamBRest];
    }

    if(nTeamACity < Cost.nTeamACity_Count && nTeamBCity < Cost.nTeamBCity_Count)
    {
        nResult = GO_DP09023(nDay + 1, nTeamACity + 1, nTeamBCity + 1, 0, 0, Cost);
        if(nResult != -1)
        {
            if(Cost.arr_nTeamACity[nTeamACity] == Cost.arr_nTeamBCity[nTeamBCity])
            {
                nResult += Cost.nCostStadium;
            }
            else
            {
                nResult += 2 * Cost.nCostStadium;
            }
            if(nResult < nResult_Min)
            {
                nResult_Min = nResult;
            }
        }
    }

    if(nTeamACity < Cost.nTeamACity_Count)
    {
        nResult = GO_DP09023(nDay + 1, nTeamACity + 1, nTeamBCity, 0, 1, Cost);
        if(nResult != -1)
        {
            nResult += Cost.nCostStadium;
            nResult += Cost.nCostHotelDay;
            if(nTeamBRest == 0)
            {
                nResult += Cost.nCostHotelRent;
            }
            if(nResult < nResult_Min)
            {
                nResult_Min = nResult;
            }
        }
    }

    if(nTeamBCity < Cost.nTeamBCity_Count)
    {
        nResult = GO_DP09023(nDay + 1, nTeamACity, nTeamBCity+1, 1, 0, Cost);
        if(nResult != -1)
        {
            nResult += Cost.nCostStadium;
            nResult += Cost.nCostHotelDay;
            if(nTeamARest == 0)
            {
                nResult += Cost.nCostHotelRent;
            }
            if(nResult < nResult_Min)
            {
                nResult_Min = nResult;
            }
        }
    }
    Cost.ppppp_nCostDP[nDay][nTeamACity][nTeamBCity][nTeamARest][nTeamBRest] = nResult_Min;
    return nResult_Min;
}

int Problem09023(void)
{
    int nTestCase = 0;
    int nResult = 0;
    CostData09023 Cost;
    scanf("%d", &nTestCase);

    for(int i = 0; i < nTestCase; i++)
    {
        scanf("%d %d %d", &Cost.nCostStadium, &Cost.nCostHotelRent, &Cost.nCostHotelDay);
        for(int j = 0; j < 100; j++)
        {
            scanf("%d", &Cost.arr_nTeamACity[j]);
            if(Cost.arr_nTeamACity[j] == 0)
            {
                Cost.nTeamACity_Count = j;
                break;
            }
        }
        for(int j = 0; j < 100; j++)
        {
            scanf("%d", &Cost.arr_nTeamBCity[j]);
            if(Cost.arr_nTeamBCity[j] == 0)
            {
                Cost.nTeamBCity_Count = j;
                break;
            }
        }
        Cost.ppppp_nCostDP = malloc(sizeof(int****)*(Cost.nTeamACity_Count + Cost.nTeamBCity_Count+1));
        memset(Cost.ppppp_nCostDP,0, sizeof(int****)*(Cost.nTeamACity_Count + Cost.nTeamBCity_Count+1));
        for(int j = 0; j <= Cost.nTeamACity_Count + Cost.nTeamBCity_Count; j++)
        {
            Cost.ppppp_nCostDP[j] = malloc(sizeof(int***)*(Cost.nTeamACity_Count+1));
            memset(Cost.ppppp_nCostDP[j], 0, sizeof(int***)*(Cost.nTeamACity_Count+1));
            for(int k = 0; k <= Cost.nTeamACity_Count; k++)
            {
                Cost.ppppp_nCostDP[j][k] = malloc(sizeof(int**)*(Cost.nTeamBCity_Count+1));
                memset(Cost.ppppp_nCostDP[j][k], 0, sizeof(int**)*(Cost.nTeamBCity_Count+1));
                for(int l = 0; l <= Cost.nTeamBCity_Count; l++)
                {
                    Cost.ppppp_nCostDP[j][k][l] = malloc(sizeof(int*)*(2));
                    memset(Cost.ppppp_nCostDP[j][k][l], 0, sizeof(int*)*(2));
                    for(int m = 0; m < 2; m++)
                    {
                        Cost.ppppp_nCostDP[j][k][l][m] = malloc(sizeof(int)*(2));
                        memset(Cost.ppppp_nCostDP[j][k][l][m], -1, sizeof(int)*(2));
                    }
                }
            }
        }

        nResult = GO_DP09023(0, 0, 0, 0, 0, Cost);
        printf("%d\n", nResult);
        
        for(int j = 0; j < Cost.nTeamACity_Count + Cost.nTeamBCity_Count; j++)
        {
            for(int k = 0; k < Cost.nTeamACity_Count; k++)
            {
                for(int l = 0; l < 2; l++)
                {
                    for(int m = 0; m < 2; m++)
                    {
                        free(Cost.ppppp_nCostDP[j][k][l][m]);
                    }
                    free(Cost.ppppp_nCostDP[j][k][l]);
                }
                free(Cost.ppppp_nCostDP[j][k]);
            }
            free(Cost.ppppp_nCostDP[j]);
        }
        free(Cost.ppppp_nCostDP);
    }
    return 0;
}