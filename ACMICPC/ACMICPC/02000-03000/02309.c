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
    int arr_nLength[9] = { 0, };
    int arr2_nMux[9][9] = { 0, };
    int nMax = 0;
    int nFind = 0;
    for(int i=0; i<9;i++)
    {
        scanf("%d", &arr_nLength[i]);
        nMax += arr_nLength[i];
    }
    qsort(arr_nLength, 9, sizeof(int), Qsort_Compare_02309_inc);
    nFind = nMax - 100;


    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (nFind == (arr_nLength[i] + arr_nLength[j]))
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                        printf("%d\n", arr_nLength[k]);
                }
                i = 10;
                break;
            }
        }
    }
    
    return 0;
}