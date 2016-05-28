#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long GO_DP01234(int nStage, int nR, int nG, int nB, long long ****pppp_llnTree, long long **pp_llnPascal)
{
    if(nR < 0 || nG < 0 || nB < 0)
    {
        return 0;
    }
    if(nStage == 0)
    {
        return 1;
    }
    if(pppp_llnTree[nStage][nR][nG][nB] != -1)
    {
        return pppp_llnTree[nStage][nR][nG][nB];
    }

    pppp_llnTree[nStage][nR][nG][nB] = 0;
    pppp_llnTree[nStage][nR][nG][nB] += GO_DP01234(nStage - 1, nR - nStage, nG, nB, pppp_llnTree, pp_llnPascal);
    pppp_llnTree[nStage][nR][nG][nB] += GO_DP01234(nStage - 1, nR, nG - nStage, nB, pppp_llnTree, pp_llnPascal);
    pppp_llnTree[nStage][nR][nG][nB] += GO_DP01234(nStage - 1, nR, nG, nB - nStage, pppp_llnTree, pp_llnPascal);
    if(nStage % 2 == 0)
    {
        pppp_llnTree[nStage][nR][nG][nB] += GO_DP01234(nStage - 1, nR - nStage / 2, nG - nStage / 2, nB, pppp_llnTree, pp_llnPascal) * pp_llnPascal[nStage][nStage / 2];
        pppp_llnTree[nStage][nR][nG][nB] += GO_DP01234(nStage - 1, nR, nG - nStage / 2, nB - nStage / 2, pppp_llnTree, pp_llnPascal) * pp_llnPascal[nStage][nStage / 2];
        pppp_llnTree[nStage][nR][nG][nB] += GO_DP01234(nStage - 1, nR - nStage / 2, nG, nB - nStage / 2, pppp_llnTree, pp_llnPascal) * pp_llnPascal[nStage][nStage / 2];
    }
    if(nStage % 3 == 0)
    {
        pppp_llnTree[nStage][nR][nG][nB] += GO_DP01234(nStage - 1, nR - nStage / 3, nG - nStage / 3, nB - nStage / 3, pppp_llnTree, pp_llnPascal)*pp_llnPascal[nStage][nStage / 3] * pp_llnPascal[nStage / 3 * 2][nStage / 3];
    }
    return pppp_llnTree[nStage][nR][nG][nB];
}

int Problem01234(void)
{
    int nN = 0;
    int nR = 0;
    int nG = 0;
    int nB = 0;
    long long llnResult = 0;
    long long **pp_llnPascal = NULL;
    long long ****pppp_llnTree = NULL;
    scanf("%d %d %d %d", &nN, &nR, &nG, &nB);

    pp_llnPascal = (long long **)malloc(sizeof(long long *)* (nN + 1));
    for(int i = 1; i <= nN; i++)
    {
        pp_llnPascal[i] = (long long *)malloc(sizeof(long long)*(i+1));
        memset(pp_llnPascal[i], 0, sizeof(long long)*(i + 1));
    }

    pppp_llnTree = (long long ****)malloc(sizeof(long long ***)*(nN + 1));
    for(int i = 0; i <= nN; i++)
    {
        pppp_llnTree[i] = (long long ***)malloc(sizeof(long long **)*(nR + 1));
        for(int j = 0; j <= nR; j++)
        {
            pppp_llnTree[i][j] = (long long**)malloc(sizeof(long long *)*(nG + 1));
            for(int k = 0; k <= nG; k++)
            {
                pppp_llnTree[i][j][k] = (long long *)malloc(sizeof(long long)*(nB + 1));
                for(int l = 0; l <= nB; l++)
                {
                    pppp_llnTree[i][j][k][l] = -1;
                }
            }
        }
    }

    for(int i = 1; i <= nN; i++)
    {
        pp_llnPascal[i][0] = 1;
        pp_llnPascal[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            pp_llnPascal[i][j] = pp_llnPascal[i - 1][j - 1] + pp_llnPascal[i-1][j];
        }
    }
    llnResult = GO_DP01234(nN, nR, nG, nB, pppp_llnTree, pp_llnPascal);
    printf("%lld\n", llnResult);

    for(int i = 1; i < nN + 1; i++)
    {
        free(pp_llnPascal[i]);
    }
    free(pp_llnPascal);

    for(int i = 0; i <= nN; i++)
    {
        for(int j = 0; j <= nR; j++)
        {
            for(int k = 0; k <= nG; k++)
            {
                free(pppp_llnTree[i][j][k]);
            }
            free(pppp_llnTree[i][j]);
        }
        free(pppp_llnTree[i]);
    }
    free(pppp_llnTree);
    return 0;
}