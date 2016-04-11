#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int QsortFunction(const void *a, const void *b)
{
    int nA = *(int *)a;
    int nB = *(int *)b;
    if(nA > nB)
        return 1;
    else if(nA < nB)
        return -1;
    else
        return 0;
}

int Problem02512(void)
{
    int nNum = 0;
    int nSum = 0;
    int nMax = 0;
    int nResult = 0;
    int *panNumArr = NULL;

    scanf("%d", &nNum);
    getchar();
    panNumArr = (int *)malloc(nNum*sizeof(int));
    for(int i = 0; i < nNum; i++)
    {
        scanf("%d", &panNumArr[i]);
    }
    getchar();
    scanf("%d", &nMax);
    qsort(panNumArr, nNum, sizeof(int), QsortFunction);

    for(int i = 0; i < nNum; i++)
    {
        if(nSum + panNumArr[i] * (nNum - i) > nMax)
        {
            nResult = (nMax - nSum) / (nNum - i);
            break;
        }
        else
        {
            nSum += panNumArr[i];
        }
    }

    if(nResult)
    {
        printf("%d", nResult);
    }
    else
    {
        printf("%d", panNumArr[nNum - 1]);
    }
    return 0;
}
int main(void)
{
    Problem02512();
    return 0;
}