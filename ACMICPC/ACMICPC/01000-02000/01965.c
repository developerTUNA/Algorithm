#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem01965(void)
{
    int nNum = 0;
    int nMax = 0;
    int *p_nBox = NULL;
    int *p_nBoxDP = NULL;

    scanf("%d", &nNum);
    p_nBox = (int*)malloc(sizeof(int)*(nNum + 1));
    p_nBoxDP = (int*)malloc(sizeof(int)*(nNum + 1));
    memset(p_nBox, 0, sizeof(int)*(nNum + 1));
    memset(p_nBoxDP, 0, sizeof(int)*(nNum + 1));

    for(int i = 1; i <= nNum; i++)
    {
        scanf("%d", &p_nBox[i]);
    }
    for(int i = 2; i <= nNum; i++)
    {
        for(int j = i - 1; 0 < j; j--)
        {
            if(p_nBox[j] < p_nBox[i] && p_nBoxDP[i] <= p_nBoxDP[j])
            {
                p_nBoxDP[i] = p_nBoxDP[j] + 1;
            }
        }
    }
    for(int i = 1; i <= nNum; i++)
    {
        if(nMax < p_nBoxDP[i])
        {
            nMax = p_nBoxDP[i];
        }
    }
    printf("%d\n", nMax + 1);
    free(p_nBox);
    free(p_nBoxDP);
    return 0;
}