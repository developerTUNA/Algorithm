#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int Probrem11723(void)
{
    int nCase = 0;
    int nSet = 0;
    unsigned int nBit = 0;
    char szOperand[10] = {0,};
    scanf("%d", &nCase);

    for(int i = 0; i < nCase; i++)
    {
        memset(szOperand, 0, sizeof(szOperand));
        nBit = 0;
        scanf("%s", szOperand);
        if(strcmp(szOperand, "add") == 0)
        {
            scanf("%d", &nBit);
            nSet = nSet | (1 << nBit);
        }
        else if(strcmp(szOperand, "remove") == 0)
        {
            scanf("%d", &nBit);
            nSet = nSet & ~(1 << nBit);
        }
        else if(strcmp(szOperand, "check") == 0)
        {
            scanf("%d", &nBit);
            if(nSet & (1 << nBit))
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(strcmp(szOperand, "toggle") == 0)
        {
            scanf("%d", &nBit);
            if(nSet & (1 << nBit))
            {
                nSet = nSet & ~(1 << nBit);
            }
            else
            {
                nSet = nSet | (1 << nBit);
            }
        }
        else if(strcmp(szOperand, "all") == 0)
        {
            nSet = ~0;
        }
        else if(strcmp(szOperand, "empty") == 0)
        {
            nSet = 0;
        }
    }

    return 0;
}