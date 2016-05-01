#pragma warning(disable:4996)
#include <stdio.h>

int Problem02953(void)
{
    int nScore = 0;
    int nWinNo = 0;
    int nWinScore = 0;
    int nMax = 0;
    int nSum = 0;
    for (int i = 0; i < 5; i++)
    {
        nSum = 0;
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &nScore);
            nSum += nScore;
        }
        if (nMax < nSum)
        {
            nMax = nSum;
            nWinNo = i;
            nWinScore = nSum;
        }
    }
    printf("%d %d\n", nWinNo + 1, nWinScore);

    return 0;
}