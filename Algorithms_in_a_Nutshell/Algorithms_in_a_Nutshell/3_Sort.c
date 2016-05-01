#include <stdio.h>
#include <stdlib.h>

int cmp(int a, int b)
{
    if(a == b)
    {
        return 0;
    }
    else if(a < b)
    {
        return -1;
    }
    else if(a > b)
    {
        return 1;
    }
}

int Sort_Insert(int *p_nNum, int nSize)
{
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
}

int Sort_Insert2(int *p_nNum, int nSize)
{
    for(int i = 1; i < nSize; i++)
    {
        int nInsert = p_nNum[i];
        for(int j = i; 0 < j && nInsert < p_nNum[j - 1]; j++)
        {
            p_nNum[j] = p_nNum[j - 1];
        }
    }
}