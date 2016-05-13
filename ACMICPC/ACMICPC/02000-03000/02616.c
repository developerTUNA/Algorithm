#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Problem02616(void)
{
    int nCoach = 0;
    int nPower = 0;
    int *p_nPeople = NULL;
    int *p_nSum = NULL;
    int *p_nMax = NULL;
    int *p_nMaxDP = NULL;
    int nMax = 0;
    int nTemp = 0;

    scanf("%d", &nCoach);
    p_nPeople = (int*)malloc(sizeof(int)*nCoach);
    p_nSum = (int*)malloc(sizeof(int)*nCoach);
    p_nMax = (int*)malloc(sizeof(int)*nCoach);
    p_nMaxDP = (int*)malloc(sizeof(int)*nCoach);

    memset(p_nPeople, 0, sizeof(int)*nCoach);
    memset(p_nSum, 0, sizeof(int)*nCoach);
    memset(p_nMax, 0, sizeof(int)*nCoach);
    memset(p_nMaxDP, 0, sizeof(int)*nCoach);

    for(int i = 0; i < nCoach; i++)
    {
        scanf("%d", &p_nPeople[i]);
    }
    scanf("%d", &nPower);


    for(int i = 0; i <= nCoach - nPower; i++)
    {
        for(int j = 0; j < nPower; j++)
        {
            p_nSum[i] += p_nPeople[i + j];
        }
    }

    nTemp = 0;
    for(int i = 0; i <= nCoach - nPower; i++)
    {
        nTemp = p_nSum[i];
        for(int j = i; 0 <= j; j--)
        {
            if(nTemp < p_nMax[j])
            {
                break;
            }
            p_nMax[j] = nTemp;
        }
    }

    for(int i = nCoach - (nPower*2); 0 <= i; i--)
    {
        p_nMaxDP[i] = p_nSum[i] + p_nMax[i+nPower];
        if(p_nMaxDP[i] < p_nMaxDP[i + 1])
        {
            p_nMaxDP[i] = p_nMaxDP[i + 1];
        }
    }
    
    for(int i = 0; i <nCoach - (nPower*2); i++)
    {
        if(nMax < p_nSum[i]+ p_nMaxDP[i + nPower])
        {
            nMax = p_nSum[i] + p_nMaxDP[i + nPower];
        }
    }

    printf("%d\n", nMax);
    free(p_nPeople);
    free(p_nSum);
    free(p_nMax);
    free(p_nMaxDP);
    return 0;
}
