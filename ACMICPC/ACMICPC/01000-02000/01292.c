#pragma warning (disable:4996)
#include <stdio.h>

int Problem01292(void)
{
    int arr_nNum[1000] = {0,};
    int nStart = 0;
    int nEnd = 0;
    int nSum = 0;
    int nCount = 0;
    int nScore = 1;

    while(nCount < 1000)
    {
        for(int i = 0; i < nScore && nCount < 1000; i++)
        {
            arr_nNum[nCount] = nScore;
            nCount++;
        }
        nScore++;
    }
    
    scanf("%d %d", &nStart, &nEnd);
    for(int i = nStart - 1; i < nEnd; i++)
    {
        nSum += arr_nNum[i];
    }
    printf("%d\n", nSum);
    return 0;
}