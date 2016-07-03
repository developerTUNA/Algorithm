#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int Problem10820(void)
{
    char cInput = 0;
    int arr_nCount[4] = {0,};

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
                printf("%d ", arr_nCount[i]);
            }
            printf("\n");
            memset(arr_nCount, 0, sizeof(arr_nCount));
        }
        else if('a' <= cInput && cInput <= 'z')
        {
            arr_nCount[0]++;
        }
        else if('A' <= cInput && cInput <= 'Z')
        {
            arr_nCount[1]++;
        }
        else if('0' <= cInput && cInput <= '9')
        {
            arr_nCount[2]++;
        }
        else if(cInput == ' ')
        {
            arr_nCount[3]++;
        }
    }
    return 0;
}