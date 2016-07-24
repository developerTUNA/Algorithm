#pragma warning (disable:4996)
#include <stdio.h>

int Problem10156(void)
{
    int nSnackPrice = 0;
    int nSnackNum = 0;
    int nCash = 0;

    scanf("%d", &nSnackPrice);
    scanf("%d", &nSnackNum);
    scanf("%d", &nCash);
    if(nCash < nSnackPrice*nSnackNum)
    {
        printf("%d\n", (nSnackPrice*nSnackNum) - nCash);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}