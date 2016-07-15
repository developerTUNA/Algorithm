#pragma warning (disable:4996)
#include <stdio.h>

int Problem02592(void)
{
    int p_nNum[10] = {0,};
    int p_nNumCount[10] = {0,};
    int nAvg = 0;
    int nMany = 0;
    int nManyPoz = 0;

    for(int i = 0; i<10; i++)
    {
        scanf("%d", &p_nNum[i]);
        nAvg += p_nNum[i];
        for(int j = 0; j<=i; j++)
        {
            if(p_nNum[i] == p_nNum[j])
            {
                p_nNumCount[i] ++;
            }
        }
    }
    nAvg /= 10;
    
    for(int i = 0; i < 10; i++)
    {
        if(nMany < p_nNumCount[i])
        {
            nMany = p_nNumCount[i];
            nManyPoz = i;
        }
    }
    
    printf("%d %d", nAvg, p_nNum[nManyPoz]);
    return 0;
}