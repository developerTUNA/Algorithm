#pragma warning (disable:4996)
#include <stdio.h>

int Problem09461(void)
{
    int nCase = 0;
    int nN = 0;
    long long arr_llnDP[101] = {0,};

    arr_llnDP[1] = 1;
    arr_llnDP[2] = 1;
    arr_llnDP[3] = 1;
    arr_llnDP[4] = 2;
    arr_llnDP[5] = 2;

    for(int i = 6; i < 101; i++)
    {
        arr_llnDP[i] = arr_llnDP[i - 1] + arr_llnDP[i - 5];
    }

    scanf("%d", &nCase);
    for(int i = 0; i < nCase; i++)
    {
        scanf("%d", &nN);
        printf("%lld\n", arr_llnDP[nN]);
    }

    return 0;
}