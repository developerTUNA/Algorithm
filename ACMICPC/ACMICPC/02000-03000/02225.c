#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02225(void)
{
    int nN = 0;
    int nK = 0;
    long long **pp_llnDP = NULL;
    scanf("%d %d", &nN, &nK);

    pp_llnDP = (long long **)malloc(sizeof(long long*)*(nK + 1));
    for(int i = 0; i <= nK; i++)
    {
        pp_llnDP[i] = (long long *)malloc(sizeof(long long)*(nN + 1));
        memset(pp_llnDP[i], 0, sizeof(long long)*(nN + 1));
    }

    for(int i = 0; i <= nN; i++)
    {
        pp_llnDP[1][i] = 1;
    }

    for(int i = 1; i <= nK; i++)
    {
        for(int j=0; j<= nN;j++)
        {
            for(int k = 0; k <= j; k++)
            {
                pp_llnDP[i][j] += pp_llnDP[i - 1][j - k];
                pp_llnDP[i][j] %= 1000*1000*1000;
            }
        }
    }

    printf("%lld\n", pp_llnDP[nK][nN]);

    for(int i = 0; i <= nK; i++)
    {
        free(pp_llnDP[i]);
    }
    free(pp_llnDP);
    return 0;
}