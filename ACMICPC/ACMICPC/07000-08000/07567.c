#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int Problem07567(void)
{
    char cLast = '\0';
    char arr_szDish[51] = {0,};
    int nHeight = 0;
    size_t nSize = 0;
    scanf("%s", arr_szDish);
    nSize = strlen(arr_szDish);

    cLast = arr_szDish[0];
    nHeight = 10;
    for(int i = 1; i < nSize; i++)
    {
        if(cLast == arr_szDish[i])
        {
            nHeight += 5;
        }
        else
        {
            cLast = arr_szDish[i];
            nHeight += 10;
        }
    }
    printf("%d\n", nHeight);
    return 0;
}