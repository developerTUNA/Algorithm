#pragma warning (disable:4996)
#include <stdio.h>

int DP[21][21][21];
int DPRecursive(int nA, int nB, int nC)
{
    if(nA <= 0 || nB <= 0 || nC <= 0)
    {
        return 1;
    }
    if(20 < nA || 20 < nB || 20 < nC)
    {
        DP[20][20][20] = DPRecursive(20, 20, 20);
        return DP[20][20][20];
    }
    if(0 < DP[nA][nB][nC])
    {
        return DP[nA][nB][nC];
    }
    if(nA < nB && nB < nC)
    {
        DP[nA][nB][nC - 1] = DPRecursive(nA, nB, nC - 1);
        DP[nA][nB - 1][nC - 1] = DPRecursive(nA, nB - 1, nC - 1);
        DP[nA][nB - 1][nC] = DPRecursive(nA, nB - 1, nC);
        DP[nA][nB][nC] = DP[nA][nB][nC - 1] + DP[nA][nB - 1][nC - 1] - DP[nA][nB - 1][nC];
        return DP[nA][nB][nC];
    }
    DP[nA - 1][nB][nC] = DPRecursive(nA - 1, nB, nC);
    DP[nA - 1][nB - 1][nC] = DPRecursive(nA - 1, nB - 1, nC);
    DP[nA - 1][nB][nC - 1] = DPRecursive(nA - 1, nB, nC - 1);
    DP[nA - 1][nB - 1][nC - 1] = DPRecursive(nA - 1, nB - 1, nC - 1);
    DP[nA][nB][nC] = DP[nA - 1][nB][nC] + DP[nA - 1][nB - 1][nC] + DP[nA - 1][nB][nC - 1] - DP[nA - 1][nB - 1][nC - 1];
    return DP[nA][nB][nC];
}

int Problem09124(void)
{
    int nA = 0;
    int nB = 0;
    int nC = 0;
    int nResult = 0;

    while(1)
    {
        nResult = 0;
        scanf("%d %d %d", &nA, &nB, &nC);
        if(nA == -1 && nB == -1 && nC == -1)
        {
            break;
        }
        nResult = DPRecursive(nA, nB, nC);
        printf("w(%d, %d, %d) = %d\n", nA, nB, nC, nResult);
    }
    return 0;
}