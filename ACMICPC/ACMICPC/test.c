#include <stdio.h>

int test(void)
{
    int DP[1001];
    int N = 1000;

    for(int i = 0; i <= 1000; i++){
        DP[i] = 1;
    }


    for(int i = 0; i <= N; i++){
        if(i + 2 <= N)
            DP[i + 2] += DP[i];
    }

    for(int i = 0; i <= N; i++){
        if(i + 5 <= N)
            DP[i + 5] += DP[i];
    }

    printf("%d\n", DP[N]);
    return 0;
}