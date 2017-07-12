#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Qsort_Compare_02309_inc(const void *a, const void *b)
{
    int nA = *(int *)a;
    int nB = *(int *)b;
    if (nA > nB)
        return 1;
    else if (nA < nB)
        return -1;
    else
        return 0;
}

int Problem02309(void)
{
    int a_nLength[9] = { 0, };
    int arr2_nMux[9][9] = { 0, };
    int nMax = 0;
    int nFind = 0;
    for(int i=0; i<9;i++)
    {
        scanf("%d", &a_nLength[i]);
        nMax += a_nLength[i];
    }
    qsort(a_nLength, 9, sizeof(int), Qsort_Compare_02309_inc);
    nFind = nMax - 100;


    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (nFind == (a_nLength[i] + a_nLength[j]))
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                        printf("%d\n", a_nLength[k]);
                }
                break;
            }
        }
    }
    
    return 0;
}