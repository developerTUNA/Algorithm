#pragma warning (disable:4996)
#include <stdio.h>


int InsertSort02587(int p_nNum[5])
{
    int nPivot = 0;
    for(int i = 1; i < 5; i++)
    {
        nPivot = p_nNum[i];
        int j = 0;
        j = i - 1;
        while(0 <= j && nPivot < p_nNum[j])
        {
            p_nNum[j + 1] = p_nNum[j];
            j = j - 1;
        }
        p_nNum[j+1] = nPivot;
    }
    return 0;
}

int Problem02587(void)
{
    int p_nNum[5] = {0,};
    int nAvg = 0;
    int nMid = 0;

    for(int i=0;i<5;i++)
    {
        scanf("%d", &p_nNum[i]);
    }
    for(int i = 0; i<5; i++)
    {
        nAvg += p_nNum[i];
    }
    nAvg /= 5;
    InsertSort02587(p_nNum);
    nMid = p_nNum[2];

    printf("%d %d", nAvg, nMid);
    return 0;
}