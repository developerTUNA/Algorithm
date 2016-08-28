#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01495(void)
{
    int nMusicNum = 0;
    int nVolumMax = 0;
    int nVolumStart = 0;
    int nResult = 0;
    int *p_nVolumList = NULL;
    int **pp_nVolum_DP = NULL;
    
    scanf("%d %d %d", &nMusicNum, &nVolumStart, &nVolumMax);
    p_nVolumList = (int*)malloc(sizeof(int)*(nMusicNum + 1));
    memset(p_nVolumList, 0, sizeof(int)*(nMusicNum + 1));
    for(int i = 0; i < nMusicNum; i++)
    {
        scanf("%d", &p_nVolumList[i]);
    }

    pp_nVolum_DP = (int**)malloc(sizeof(int*)*(nMusicNum+1));
    for(int i = 0; i <= nMusicNum; i++)
    {
        pp_nVolum_DP[i] = (int*)malloc(sizeof(int)*(nVolumMax + 1));
        memset(pp_nVolum_DP[i], 0, sizeof(int)*(nVolumMax + 1));
    }

    pp_nVolum_DP[0][nVolumStart] = 1;
    for(int i = 0; i < nMusicNum; i++)
    {
        for(int j = 0; j <= nVolumMax; j++)
        {
            if(pp_nVolum_DP[i][j] == 1)
            {
                if(0 <= j - p_nVolumList[i])
                {
                    pp_nVolum_DP[i + 1][j - p_nVolumList[i]] = 1;
                }
                if(j + p_nVolumList[i] <= nVolumMax)
                {
                    pp_nVolum_DP[i + 1][j + p_nVolumList[i]] = 1;
                }
            }
        }
    }

    nResult = -1;
    for(int i = 0; i <= nVolumMax; i++)
    {
        if(pp_nVolum_DP[nMusicNum][i] == 1 && nResult<i)
        {
            nResult = i;
        }
    }
    printf("%d\n", nResult);
    free(p_nVolumList);
    for(int i = 1; i <= nMusicNum; i++)
    {
        free(pp_nVolum_DP[i]);
    }
    free(pp_nVolum_DP);
    return 0;
}