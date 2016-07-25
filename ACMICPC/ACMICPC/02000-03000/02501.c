#pragma warning (disable:4996)
#include <stdio.h>

int Problem02501(void)
{
    int nP = 0;
    int nQ = 0;
    int nK = 0;
    int nCounter = 0;
    int nResult = 0;
    scanf("%d", &nP);
    scanf("%d", &nK);


    for(int i = nP; 0 < i; i--)
    {
        if(nP%i == 0)
        {
            nCounter++;
            if(nCounter == nK)
            {
                nResult = nP/i;
                break;
            }
        }
    }

    printf("%d\n", nResult);

    return 0;
}