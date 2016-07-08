#pragma warning (disable:4996)
#include <stdio.h>

int Problem01094(void)
{
    unsigned char cLen = 0;
    int nResult = 0;
    scanf("%hhd", &cLen);
    
    for(int i = 0; i < 8; i++)
    {
        if(1 << i & cLen)
        {
            nResult++;
        }
    }
    printf("%d\n", nResult);
    return 0;
}