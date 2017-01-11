#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem10989(void)
{
    int nCount = 0;
    int nTemp = 0;
    int arr_nSort[10001];
    
    memset(arr_nSort, 0, sizeof(arr_nSort));
    scanf("%d", &nCount);

    for(int i = 0; i < nCount; i++)
    {
        scanf("%d", &nTemp);
        arr_nSort[nTemp]++;
    }

    for(int i = 1; i <= 10000; i++)
    {
        if(arr_nSort[i])
        {
            for(int j = 0; j <arr_nSort[i];j++)
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}