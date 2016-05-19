#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem01670(void)
{
    int nPeople = 0;
    long long *p_Shake_DP = NULL;

    scanf("%d", &nPeople);
    p_Shake_DP = (long long*)malloc(sizeof(long long)*(nPeople+1));
    memset(p_Shake_DP, 0, sizeof(long long)*(nPeople + 1));
    p_Shake_DP[0] = 1;
    p_Shake_DP[2] = 1;
    for(int i = 4; i <= nPeople; i += 2)
    {
        for(int j = i - 2; 0 <= j; j -= 2)
        {
            p_Shake_DP[i] += p_Shake_DP[j] * p_Shake_DP[i - j - 2];
            p_Shake_DP[i] %= 987654321;
        }
    }

    printf("%lld\n", p_Shake_DP[nPeople]);
    free(p_Shake_DP);
    return 0;
}