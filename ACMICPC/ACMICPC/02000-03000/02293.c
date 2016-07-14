#pragma warning (disable:4996)
#include <stdio.h>

int InsertSort02293(int arr_nCoin[101], int nCoinNum)
{
    int nPivot = 0;
    for(int i = 1; i < nCoinNum; i++)
    {
        nPivot = arr_nCoin[i];
        int j = 0;
        j = i - 1;
        while(0 <= j && nPivot < arr_nCoin[j])
        {
            arr_nCoin[j + 1] = arr_nCoin[j];
            j = j - 1;
        }
        arr_nCoin[j+1] = nPivot;
    }
    return 0;
}

int Problem02293(void)
{
    long long llnCountDP[10001] = {0,};
    int nCoinNum = 0;
    int nGoal = 0;
    int arr_nCoin[101] = {0,};
    scanf("%d %d", &nCoinNum, &nGoal);

    for(int i = 0; i < nCoinNum; i++)
    {
        scanf("%d", &arr_nCoin[i]);
    }

    InsertSort02293(arr_nCoin, nCoinNum);

    llnCountDP[0] = 1;
    for(int i=0;i<nCoinNum;i++)
    {
        for(int j = 0; j <= nGoal; j++)
        {
            if(j + arr_nCoin[i] <= nGoal)
                llnCountDP[j + arr_nCoin[i]] += llnCountDP[j];
        }
    }
    printf("%lld\n", llnCountDP[nGoal]);
    return 0;
}