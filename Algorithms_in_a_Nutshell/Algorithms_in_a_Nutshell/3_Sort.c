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

int Sort_Insert(int *arr_nNum, int nSize)
{
    for(int i = 0; i < nSize; i++)
    {
        int nPic = arr_nNum[i];
        int iCheck = i-1;
        while(iCheck >= 0 && arr_nNum[iCheck] > nPic)
        {
            arr_nNum[iCheck + 1] = arr_nNum[iCheck];
            iCheck--;
        }
        arr_nNum[iCheck + 1] = nPic;
    }
}