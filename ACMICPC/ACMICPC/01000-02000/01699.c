#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01699(void)
{
    int *p_nSqrtDP = NULL;
    int nBackCounter = 0;
    int nNum = 0;
    int nMin = 0;

    scanf("%d", &nNum);
    p_nSqrtDP = (int*)malloc(sizeof(int)*(nNum + 1));
    memset(p_nSqrtDP, 0, sizeof(int)*(nNum + 1));
    for(int i = 1; i <= nNum; i++)
    {
        
        nMin = p_nSqrtDP[i - 1];
        for(int j = 2; j*j <= i; j++)
        {
            if(p_nSqrtDP[i - j*j]<nMin)
            {
                nMin = p_nSqrtDP[i - j*j];
            }
        }
        p_nSqrtDP[i] = nMin+1;
    }

    printf("%d\n", p_nSqrtDP[nNum]);
    free(p_nSqrtDP);
    return 0;
}