#pragma warning (disable:4996)
#include <stdio.h>

int Problem09461(void)
{
    int nCase = 0;
    int nN = 0;
    long long a_llnDP[101] = {0,};

    a_llnDP[1] = 1;
    a_llnDP[2] = 1;
    a_llnDP[3] = 1;
    a_llnDP[4] = 2;
    a_llnDP[5] = 2;

    for(int i = 6; i < 101; i++)
    {
        a_llnDP[i] = a_llnDP[i - 1] + a_llnDP[i - 5];
    }

    scanf("%d", &nCase);
    for(int i = 0; i < nCase; i++)
    {
        scanf("%d", &nN);
        printf("%lld\n", a_llnDP[nN]);
    }

    return 0;
}