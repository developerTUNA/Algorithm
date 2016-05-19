#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ABS05060(x)(((x)<0)?-(x):(x))

int Problem05060(void)
{
    int nTestCase = 0;
    int nHouseNum = 0;
    int nSaveNum = 0;
    int *p_nHousePoz = NULL;
    double **pp_lfSelect = NULL;
    double **pp_lfTwo = NULL;

    scanf("%d", &nTestCase);
    for(int i = 0; i < nTestCase; i++)
    {
        scanf("%d %d", &nHouseNum, &nSaveNum);
        p_nHousePoz = (int*)malloc(sizeof(int)*(nHouseNum + 1));
        memset(p_nHousePoz, 0, sizeof(int)*(nHouseNum + 1));
        pp_lfSelect = (double**)malloc(sizeof(double*)*(nHouseNum + 1));
        for(int j = 1; j <= nHouseNum; j++)
        {
            pp_lfSelect[j] = (double*)malloc(sizeof(double)*(j + 2));
            memset(pp_lfSelect[j], 0, sizeof(double)*(j + 2));
        }
        pp_lfTwo = (double**)malloc(sizeof(double*)*(nHouseNum + 1));
        for(int j = 1; j <= nHouseNum; j++)
        {
            pp_lfTwo[j] = (double*)malloc(sizeof(double)*(nHouseNum + 1));
            memset(pp_lfTwo[j], 0, sizeof(double)*(nHouseNum + 1));
        }

        for(int j = 1; j <= nHouseNum; j++)
        {
            scanf("%d", &p_nHousePoz[j]);
        }

        for(int j = 1; j < nHouseNum; j++)
        {
            for(int k = j+1; k <= nHouseNum; k++)
            {
                double nTemp = p_nHousePoz[j] + (p_nHousePoz[k] - p_nHousePoz[j]);
                for(int l = j+1; l < k; l++)
                {
                    pp_lfTwo[j][k] += ABS05060(p_nHousePoz[l]-(nTemp * (l - j) / (k - j)));
                }
            }
        }

        for(int j = 1; j <= nSaveNum; j++)
        {
            free(pp_lfSelect[j]);
            free(pp_lfTwo[j]);
        }
        free(pp_lfSelect);
        free(pp_lfTwo);
        free(p_nHousePoz);
    }
    return 0;
}