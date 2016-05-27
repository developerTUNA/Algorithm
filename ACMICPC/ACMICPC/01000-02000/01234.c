#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long GO_DP(int nStage, int nR, int nG, int nB, long long **pp_llnPascal)
{
    if(nStage == 0)
    {
        return 1;
    }
    if(nR < 0 || nG < 0 || nB < 0)
    {
        return 0;
    }

}

int Problem01234(void)
{
    int nN = 0;
    int nR = 0;
    int nG = 0;
    int nB = 0;
    long long llnResult = 0;
    long long **pp_llnPascal = NULL;

    scanf("%d %d %d %d", &nN, &nR, &nG, &nB);

    pp_llnPascal = (long long **)malloc(sizeof(long long *)* (nN+1));
    for(int i = 1; i < nN + 1; i++)
    {
        pp_llnPascal[i] = (long long *)malloc(sizeof(long long)*i);
        memset(pp_llnPascal[i], 0, sizeof(long long)*i);
    }

    llnResult = GO_DP(nN, nR, nG, nB, pp_llnPascal);
    printf("%lld", llnResult);

    for(int i = 1; i < nN + 1; i++)
    {
        free(pp_llnPascal[i]);
    }
    free(pp_llnPascal);
    return 0;
}