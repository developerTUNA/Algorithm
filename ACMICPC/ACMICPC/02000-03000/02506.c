#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02506(void)
{
    int nNum = 0;
    int nTotalScore = 0;
    int *p_nResult = NULL;
    int *p_nScore = NULL;

    scanf("%d", &nNum);
    p_nResult = (int*)malloc(sizeof(int)*(nNum+1));
    p_nScore = (int*)malloc(sizeof(int)*(nNum + 1));
    memset(p_nResult, 0, sizeof(int)*(nNum + 1));
    memset(p_nScore, 0, sizeof(int)*(nNum + 1));
    for(int i = 1; i <= nNum; i++)
    {
        scanf("%d", &p_nResult[i]);
    }
    for(int i = 1; i <= nNum; i++)
    {
        if(p_nResult[i])
        {
            p_nScore[i] = p_nScore[i - 1]+1;
        }
    }
    for(int i = 1; i <= nNum; i++)
    {
        nTotalScore += p_nScore[i];
    }
    printf("%d\n", nTotalScore);
    free(p_nResult);
    free(p_nScore);
    return 0;
}