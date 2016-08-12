#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GO_DP01520(int **pp_nBox, int **pp_nBox_DP, int nRowSize, int nColSize, int nRow, int nCol)
{
    int a_nRowMove[4] = {1,-1,0,0};
    int a_nColMove[4] = {0,0,1,-1};
    
    if(nRowSize == nRow && nColSize == nCol)
    {
        return 1;
    }
    if(nRowSize < nRow || nColSize < nCol)
    {
        return 0;
    }
    if(pp_nBox_DP[nRow][nCol] != 0)
    {
        return pp_nBox_DP[nRow][nCol];
    }

    for(int i = 0; i < 4; i++)
    {
        int nRowMove = nRow + a_nRowMove[i];
        int nColMove = nCol + a_nColMove[i];
        if(1<=nRowMove&&nRowMove<=nRowSize&&1<=nColMove&&nColMove<=nColSize)
        {
            if(pp_nBox[nRowMove][nColMove] < pp_nBox[nRow][nCol])
            {
                pp_nBox_DP[nRow][nCol] += GO_DP01520(pp_nBox, pp_nBox_DP,nRowSize,nColSize,nRowMove,nColMove);
            }
        }
    }
    return pp_nBox_DP[nRow][nCol];
}

int Problem01520(void)
{
    int nRow = 0;
    int nCol = 0;
    int **pp_nBox = NULL;
    int **pp_nBox_DP = NULL;

    scanf("%d %d", &nRow, &nCol);
    
    pp_nBox = (int**)malloc(sizeof(int*)*(nRow+1));
    pp_nBox_DP = (int**)malloc(sizeof(int*)*(nRow + 1));
    for(int i = 0; i <= nRow; i++)
    {
        pp_nBox[i] = (int*)malloc(sizeof(int)*(nCol + 1));
        pp_nBox_DP[i] = (int*)malloc(sizeof(int)*(nCol + 1));
        memset(pp_nBox[i], 0, sizeof(int)*(nCol + 1));
        memset(pp_nBox_DP[i], 0, sizeof(int)*(nCol + 1));
    }
    for(int i = 1; i <= nRow; i++)
    {
        for(int j = 1; j <= nCol; j++)
        {
            scanf("%d", &pp_nBox[i][j]);
        }
    }

    GO_DP01520(pp_nBox, pp_nBox_DP, nRow, nCol, 1, 1);
    printf("%d\n", pp_nBox_DP[1][1]);

    for(int i = 0; i <= nRow; i++)
    {
        free(pp_nBox[i]);
        free(pp_nBox_DP[i]);
    }
    free(pp_nBox);
    free(pp_nBox_DP);
    return 0;
}