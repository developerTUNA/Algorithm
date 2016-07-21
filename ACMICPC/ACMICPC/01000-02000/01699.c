#pragma warning (disable:4996)
#include <stdio.h>

int Problem01699(void)
{
    int nSqrtDP[100001] = {0,};
    int nBackCounter = 0;
    int nNum = 0;

    scanf("%d", &nNum);
    for(int i = 0; i < 317; i++)
    {
        nSqrtDP[i*i] = 1;
    }
    for(int i = 1; i < 100001; i++)
    {
        if(nSqrtDP[i] != 1)
        {
            nSqrtDP[i] = nSqrtDP[nBackCounter] + 1;
            nBackCounter++;
        }
        else
        {
            nBackCounter = 1;
        }
    }

    printf("%d\n", nSqrtDP[nNum]);
    return 0;
}