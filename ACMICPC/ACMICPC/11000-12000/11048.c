#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX11048(a,b) ((a)<(b))?(b):(a);

int Problem11048(void)
{
    int nRow = 0;
    int nCol = 0;
    int **pp_nMage = NULL;
    int **pp_nMage_DP = NULL;
    
    scanf("%d %d", &nRow, &nCol);
    pp_nMage = (int**)malloc(sizeof(int*)*(nRow+1));
    pp_nMage_DP = (int**)malloc(sizeof(int*)*(nRow + 1));
    for(int i=0; i <= nRow; i++)
    {
        pp_nMage[i] = (int*)malloc(sizeof(int)*(nCol + 1));
        pp_nMage_DP[i] = (int*)malloc(sizeof(int)*(nCol + 1));
        memset(pp_nMage[i], 0, sizeof(int)*(nCol + 1));
        memset(pp_nMage_DP[i], 0, sizeof(int)*(nCol + 1));
    }
    for(int i = 1; i <= nRow; i++)
    {
        for(int j = 1; j <= nCol; j++)
        {
            scanf("%d", &pp_nMage[i][j]);
        }
    }

    for(int i = 1; i <= nRow; i++)
    {
        for(int j = 1; j <= nCol; j++)
        {
            pp_nMage_DP[i][j] += pp_nMage[i][j];
            pp_nMage_DP[i][j] += MAX11048(pp_nMage_DP[i - 1][j], pp_nMage_DP[i][j - 1]);
        }
    }
    printf("%d\n", pp_nMage_DP[nRow][nCol]);
    for(int i = 0; i <= nRow; i++)
    {
        free(pp_nMage[i]);
    }
    free(pp_nMage);
    return 0;
}