#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem05557(void)
{
    int nSize = 0;
    int nAnswer = 0;
    int *p_nNum = NULL;
    long long **pp_llnResult_DP = NULL;
    
    scanf("%d", &nSize);
    nSize--;
    p_nNum = (int*)malloc(sizeof(int)*(nSize + 1));
    memset(p_nNum, 0, sizeof(int)*(nSize + 1));
    pp_llnResult_DP = (long long **)malloc(sizeof(long long*)*(nSize + 1));
    for(int i = 0; i <= nSize; i++)
    {
        pp_llnResult_DP[i] = (long long*)malloc(sizeof(long long) * 21);
        memset(pp_llnResult_DP[i], 0, sizeof(long long) * 21);
    }
    
    for(int i=1;i<=nSize;i++)
    {
        scanf("%d", &p_nNum[i]);
    }
    scanf("%d", &nAnswer);

    pp_llnResult_DP[1][p_nNum[1]] = 1;
    for(int i = 2; i <= nSize; i++)
    {
        for(int j = 0; j <= 20; j++)
        {
            if(j + p_nNum[i] <= 20)
            {
                pp_llnResult_DP[i][j] += pp_llnResult_DP[i - 1][j + p_nNum[i]];
            }
            if(0 <= j - p_nNum[i])
            {
                pp_llnResult_DP[i][j] += pp_llnResult_DP[i - 1][j - p_nNum[i]];
            }
        }
    }
    
    printf("%lld\n", pp_llnResult_DP[nSize][nAnswer]);
    free(p_nNum);
    for(int i = 0; i <= nSize; i++)
    {
        free(pp_llnResult_DP[i]);
    }
    free(pp_llnResult_DP);
    return 0;
}