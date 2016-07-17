#pragma warning (disable:4996)
#include <stdio.h>

int Problem02566(void)
{
    int nNum = 0;
    int nMax = 0;
    int nRow = 0;
    int nCol = 0;

    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            scanf("%d", &nNum);
            if(nMax < nNum)
            {
                nMax = nNum;
                nRow = i;
                nCol = j;
            }
        }
    }
    printf("%d\n", nMax);
    printf("%d %d\n", nRow, nCol);

    return 0;
}