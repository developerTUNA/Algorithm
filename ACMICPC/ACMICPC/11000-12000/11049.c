#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Array11049
{
    int nX;
    int nY;
} Array11049;

int GO_DP11049(int nArrayNum, Array11049 *p_Array, int **pp_nArrayMux_DP, int nStart, int nEnd)
{
    int nTemp = 0;
    if(0 < pp_nArrayMux_DP[nStart][nEnd])
    {
        return pp_nArrayMux_DP[nStart][nEnd];
    }

    if(nEnd <= nStart)
    {
        return 0;
    }

    if(nStart == nEnd-1)
    {
        pp_nArrayMux_DP[nStart][nEnd] = p_Array[nStart].nX * p_Array[nStart].nY *p_Array[nEnd].nY;
        return pp_nArrayMux_DP[nStart][nEnd];
    }
    
    for(int i = nStart; i < nEnd; i++)
    {
        nTemp = GO_DP11049(nArrayNum, p_Array, pp_nArrayMux_DP, nStart, i) + GO_DP11049(nArrayNum, p_Array, pp_nArrayMux_DP, i+1, nEnd)
            + p_Array[nStart].nX * p_Array[i].nY *p_Array[nEnd].nY;
        if(pp_nArrayMux_DP[nStart][nEnd] == 0 || nTemp < pp_nArrayMux_DP[nStart][nEnd])
        {
            pp_nArrayMux_DP[nStart][nEnd] = nTemp;
        }
    }
    return pp_nArrayMux_DP[nStart][nEnd];
}

int Problem11049(void)
{
    int nArrayNum = 0;
    int nResult = 0;
    int **pp_nArrayMux_DP = NULL;
    Array11049 *p_Array = NULL;
    
    scanf("%d", &nArrayNum);
    p_Array = (Array11049*)malloc(sizeof(Array11049)*(nArrayNum));
    pp_nArrayMux_DP = (int **)malloc(sizeof(int*)*(nArrayNum));
    for(int i = 0; i < nArrayNum; i++)
    {
        scanf("%d %d", &p_Array[i].nX, &p_Array[i].nY);
        pp_nArrayMux_DP[i] = (int *)malloc(sizeof(int)*(nArrayNum));
        memset(pp_nArrayMux_DP[i], 0, sizeof(int)*(nArrayNum));
    }

    nResult = GO_DP11049(nArrayNum, p_Array, pp_nArrayMux_DP, 0, nArrayNum-1);
    printf("%d\n", nResult);

    free(p_Array);
    for(int i = 0; i < nArrayNum; i++)
    {
        free(pp_nArrayMux_DP[i]);
    }
    free(pp_nArrayMux_DP);
    return 0;
}