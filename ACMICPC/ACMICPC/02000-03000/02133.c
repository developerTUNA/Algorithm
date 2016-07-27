#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02133(void)
{
    int nTileLen = 0;
    int *p_nTileDP = NULL;

    scanf("%d", &nTileLen);
    p_nTileDP = (int*)malloc(sizeof(int)*(nTileLen + 1));
    memset(p_nTileDP, 0, sizeof(int)*(nTileLen + 1));

    p_nTileDP[0] = 1;
    for(int i = 2; i <= nTileLen; i += 2)
    {
        p_nTileDP[i] += 3 * p_nTileDP[i - 2];
        for(int j = 4; j <= i; j += 2)
        {
            p_nTileDP[i] += 2 * p_nTileDP[i - j];
        }
    }
    printf("%d", p_nTileDP[nTileLen]);
    free(p_nTileDP);
    return 0;
}