#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int Problem10820(void)
{
    char cInput = 0;
    int a_nCount[4] = {0,};

    while(cInput = getc(stdin))
    {
        if(cInput == EOF)
        {
            break;
        }

        if(cInput == '\n')
        {
            for(int i = 0; i < 4; i++)
            {
                printf("%d ", a_nCount[i]);
            }
            printf("\n");
            memset(a_nCount, 0, sizeof(a_nCount));
        }
        else if('a' <= cInput && cInput <= 'z')
        {
            a_nCount[0]++;
        }
        else if('A' <= cInput && cInput <= 'Z')
        {
            a_nCount[1]++;
        }
        else if('0' <= cInput && cInput <= '9')
        {
            a_nCount[2]++;
        }
        else if(cInput == ' ')
        {
            a_nCount[3]++;
        }
    }
    return 0;
}