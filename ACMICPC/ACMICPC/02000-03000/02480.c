#pragma warning (disable:4996)
#include <stdio.h>

int Problem02480(void)
{
    int nA = 0;
    int nB = 0;
    int nC = 0;
    int nResult = 0;

    scanf("%d", &nA);
    scanf("%d", &nB);
    scanf("%d", &nC);

    if(nA == nB && nB == nC)
    {
        nResult = 10000 + nA * 1000;
    }
    else
    {
        if(nA == nB)
        {
            nResult = 1000 + nA * 100;
        }
        else if(nA == nC)
        {
            nResult = 1000 + nA * 100;
        }
        else if(nB == nC)
        {
            nResult = 1000 + nB * 100;
        }
        else
        {
            if((nA <= nB && nB <= nC) || (nB <= nA && nA <= nC))
            {
                nResult = nC * 100;
            }
            else if((nA <= nC && nC <= nB)|| (nC <= nA && nA <= nB))
            {
                nResult = nB * 100;
            }
            else if((nB <= nC && nC <= nA)|| (nC <= nB && nB <= nA))
            {
                nResult = nA * 100;
            }
        }
    }
    printf("%d\n", nResult);
    return 0;
}