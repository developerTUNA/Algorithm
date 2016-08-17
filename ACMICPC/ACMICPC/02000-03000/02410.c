#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem02410(void)
{
    int nNum = 0;
    int *p_nNum_DP = NULL;

    scanf_s("%d", &nNum);
    p_nNum_DP = (int*)malloc(sizeof(int)*(nNum+1));
    memset(p_nNum_DP, 0, sizeof(int)*(nNum + 1));
    p_nNum_DP[0] = 1;
    for(int i = 1; i <= nNum; i *= 2)
    {
        for(int j = i; j <= nNum; j++)
        {
            p_nNum_DP[j] += p_nNum_DP[j-i];
            p_nNum_DP[j] %= 1000000000;
        }
    }
    printf("%d\n", p_nNum_DP[nNum]);
    free(p_nNum_DP);
    return 0;
}