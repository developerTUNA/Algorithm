#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem02750(void)
{
    int nSize = 0;
    int *p_nNum = NULL;

    scanf("%d", &nSize);
    p_nNum = malloc(sizeof(int)*nSize);
    memset(p_nNum, 0, sizeof(int)*nSize);
    for(int i = 0; i < nSize; i++)
    {
        scanf("%d", &p_nNum[i]);
    }

    for(int i = 1; i < nSize; i++)
    {
        int nInsert = p_nNum[i];
        int iCheck = i - 1;
        while(0 <= iCheck && nInsert < p_nNum[iCheck])
        {
            p_nNum[iCheck + 1] = p_nNum[iCheck];
            iCheck--;
        }
        p_nNum[iCheck + 1] = nInsert;
    }

    for(int i = 0; i < nSize; i++)
    {
        printf("%d\n", p_nNum[i]);
    }

    free(p_nNum);
    return 0;
}

