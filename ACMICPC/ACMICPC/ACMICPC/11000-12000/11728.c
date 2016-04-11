#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int QsortFunction_11728(const void *a, const void *b)
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

int Problem11728(void)
{
    int nNumA = 0;
    int nNumB = 0;
    int nSum = 0;
    int *panNumArr = NULL;

    scanf("%d %d", &nNumA, &nNumB);
    getchar();
    nSum = nNumA + nNumB;

    panNumArr = (int *)malloc(nSum*sizeof(int));

    for(int i = 0; i < nNumA; i++)
    {
        scanf("%d", &panNumArr[i]);
    }
    getchar();
    for(int i = nNumA; i < nSum; i++)
    {
        scanf("%d", &panNumArr[i]);
    }
    qsort(panNumArr, nSum, sizeof(int), QsortFunction_11728);
    for(int i = 0; i < nSum; i++)
    {
        printf("%d ", panNumArr[i]);
    }
    return 0;
}
