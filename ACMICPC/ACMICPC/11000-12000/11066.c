#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN11066(a,b)((a)<(b))?(a):(b)

int GO_DP11066(int nChapterNum, int *p_nChapterSize,int nStart, int nEnd, int **pp_nChapterSize_DP, int **pp_nChapterSize_SUM)
{
    if(nStart == nEnd)
    {
        pp_nChapterSize_DP[nStart][nEnd] = p_nChapterSize[nStart];
        return 0;
    }
    if(nStart == nEnd-1)
    {
        pp_nChapterSize_DP[nStart][nEnd] = pp_nChapterSize_SUM[nStart][nEnd];
        return pp_nChapterSize_DP[nStart][nEnd];
    }
    if(0 < pp_nChapterSize_DP[nStart][nEnd])
    {
        return pp_nChapterSize_DP[nStart][nEnd];
    }
    
    for(int i = nStart; i < nEnd; i++)
    {
        if(pp_nChapterSize_DP[nStart][nEnd] == 0)
        {
            pp_nChapterSize_DP[nStart][nEnd] = pp_nChapterSize_SUM[nStart][nEnd] + GO_DP11066(nChapterNum, p_nChapterSize, nStart, i, pp_nChapterSize_DP,pp_nChapterSize_SUM) + GO_DP11066(nChapterNum, p_nChapterSize, i + 1, nEnd, pp_nChapterSize_DP, pp_nChapterSize_SUM);
        }
        else
        {
            pp_nChapterSize_DP[nStart][nEnd] = MIN11066(pp_nChapterSize_DP[nStart][nEnd], pp_nChapterSize_SUM[nStart][nEnd] + GO_DP11066(nChapterNum, p_nChapterSize, nStart, i, pp_nChapterSize_DP, pp_nChapterSize_SUM) + GO_DP11066(nChapterNum, p_nChapterSize, i + 1, nEnd, pp_nChapterSize_DP, pp_nChapterSize_SUM));
        }
    }
    return pp_nChapterSize_DP[nStart][nEnd];
}
int Problem11066(void)
{
    int nRound = 0;
    int nChapterNum = 0;
    int nResult = 0;
    int *p_nChapterSize = NULL;
    int **pp_nChapterSize_DP = NULL;
    int **pp_nChapterSize_SUM = NULL;

    scanf("%d", &nRound);
    for(int i = 0; i < nRound; i++)
    {
        scanf("%d", &nChapterNum);
        p_nChapterSize = (int *)malloc(sizeof(int)*(nChapterNum));
        memset(p_nChapterSize, 0, sizeof(int)*(nChapterNum));
        for(int j = 0; j < nChapterNum; j++)
        {
            scanf("%d", &p_nChapterSize[j]);
        }

        pp_nChapterSize_DP = (int **)malloc(sizeof(int*)*(nChapterNum + 1));
        pp_nChapterSize_SUM = (int **)malloc(sizeof(int*)*(nChapterNum + 1));
        for(int j = 0; j <= nChapterNum; j++)
        {
            pp_nChapterSize_DP[j] = (int *)malloc(sizeof(int)*(nChapterNum + 1));
            memset(pp_nChapterSize_DP[j], 0, sizeof(int)*(nChapterNum + 1));
            pp_nChapterSize_SUM[j] = (int *)malloc(sizeof(int)*(nChapterNum + 1));
            memset(pp_nChapterSize_SUM[j], 0, sizeof(int)*(nChapterNum + 1));
        }
        for(int j = 0; j < nChapterNum; j++)
        {
            pp_nChapterSize_SUM[j][j] = p_nChapterSize[j];
            for(int k = j+1; k < nChapterNum; k++)
            {
                pp_nChapterSize_SUM[j][k] = pp_nChapterSize_SUM[j][k-1] + p_nChapterSize[k];
            }
        }
        nResult = GO_DP11066(nChapterNum-1, p_nChapterSize, 0, nChapterNum-1, pp_nChapterSize_DP, pp_nChapterSize_SUM);
        printf("%d\n", nResult);

        free(p_nChapterSize);
        for(int j = 0; j <= nChapterNum; j++)
        {
            free(pp_nChapterSize_DP[j]);
            free(pp_nChapterSize_SUM[j]);
        }
        free(pp_nChapterSize_DP);
        free(pp_nChapterSize_SUM);
    }
    return 0;
}