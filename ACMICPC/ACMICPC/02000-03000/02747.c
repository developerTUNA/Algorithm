#pragma warning(disable:4996)
#include <stdio.h>

int Problem02747(void)
{
    int nNum = 0;
    int a_nFib[46];

    scanf("%d", &nNum);
    
    a_nFib[1] = 1;
    a_nFib[2] = 1;
    
    for (int i = 3; i <= nNum; i++)
    {
        a_nFib[i] = a_nFib[i - 1] + a_nFib[i - 2];
    }
    printf("%d", a_nFib[nNum]);
    
    return 0;
}