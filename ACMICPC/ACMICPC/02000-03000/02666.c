#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN02666(a,b)  (( (a) < (b) ) ? (a) : (b))
#define ABS02666(a) ( (0<(a)) ? (a) : -(a) )

int GO_DP02666(int nMoveNum, int*** ppp_nDoor, int* p_nOpenDoor, int nCount, int nDoor1, int nDoor2)
{
    int nResult = 0;
    if(nMoveNum == nCount)
    {
        return 0;
    }
    if(ppp_nDoor[nCount][nDoor1][nDoor2] != -1)
    {
        return ppp_nDoor[nCount][nDoor1][nDoor2];
    }
    nResult = MIN02666(GO_DP02666(nMoveNum, ppp_nDoor, p_nOpenDoor, nCount + 1, nDoor1, p_nOpenDoor[nCount]) + ABS02666(p_nOpenDoor[nCount]- nDoor2)
                       , GO_DP02666(nMoveNum, ppp_nDoor, p_nOpenDoor, nCount + 1, p_nOpenDoor[nCount], nDoor2) + ABS02666(p_nOpenDoor[nCount]- nDoor1));
    ppp_nDoor[nCount][nDoor1][nDoor2] = nResult;
    return nResult;
}

int Problem02666(void)
{
    int nSize = 0;
    int nOpen1 = 0;
    int nOpen2 = 0;
    int nMoveNum = 0;
    int nResult = 0;
    int* p_nOpenDoor = NULL;
    int*** ppp_nDoor = NULL;

    scanf("%d", &nSize);
    scanf("%d %d", &nOpen1, &nOpen2);
    scanf("%d", &nMoveNum);
    
    p_nOpenDoor = (int *)malloc(sizeof(int)*nMoveNum);
    memset(p_nOpenDoor, 0, sizeof(int)*nMoveNum);
    for(int i = 0; i < nMoveNum; i++)
    {
        scanf("%d", &p_nOpenDoor[i]);
    }

    ppp_nDoor = (int ***)malloc(sizeof(int**)*(nMoveNum + 1));
    memset(ppp_nDoor, 0, sizeof(int**)*(nMoveNum + 1));
    for(int i = 0; i <= nMoveNum; i++)
    {
        ppp_nDoor[i] = (int **)malloc(sizeof(int*)*(nSize + 1));
        memset(ppp_nDoor[i], 0, sizeof(int*)*(nSize + 1));
        for(int j = 0; j <= nSize; j++)
        {
            ppp_nDoor[i][j] = (int*)malloc(sizeof(int)*(nSize + 1));
            memset(ppp_nDoor[i][j], -1, sizeof(int)*(nSize + 1));
        }
    }

    nResult = GO_DP02666(nMoveNum, ppp_nDoor, p_nOpenDoor, 0, nOpen1, nOpen2);
    printf("%d\n", nResult);
    
    free(p_nOpenDoor);
    for(int i = 0; i <= nMoveNum; i++)
    {
        for(int j = 0; j <= nSize; j++)
        {
            free(ppp_nDoor[i][j]);
        }
        free(ppp_nDoor[i]);
    }
    free(ppp_nDoor);
    return 0;
}