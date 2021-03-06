#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int Problem08958(void)
{
    char szOXResult[81] = {0,};
    int nOXResultLen = 0;
    int nTestCase = 0;
    int nResult = 0;
    int a_nScore[81] = {0,};

    scanf("%d", &nTestCase);

    for(int i = 0; i < nTestCase;i++)
    {
        nResult = 0;
        memset(szOXResult, 0, sizeof(char) * 81);
        memset(a_nScore, 0, sizeof(int) * 81);
        
        scanf("%s", szOXResult);
        nOXResultLen = (int)strlen(szOXResult);
        for(int j = 1; j <= nOXResultLen; j++)
        {
            if(szOXResult[j-1] == 'O')
            {
                a_nScore[j] = a_nScore[j-1]+1;
                nResult += a_nScore[j];
            }
        }
        printf("%d\n", nResult);
    }

    return 0;
}