#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int Problem01076(void)
{
    char a_szColor[10][10] = {"black","brown","red","orange","yellow",
                                "green","blue","violet","grey","white"};
    char szTemp[10] = {0,};
    long long llnResult = 0;
    
    scanf("%s", szTemp);
    for(int i = 0; i < 10; i++)
    {
        if(strcmp(szTemp, a_szColor[i]) == 0)
        {
            llnResult += i * 10;
            break;
        }
    }

    memset(szTemp, 0, sizeof(szTemp));
    scanf("%s", szTemp);
    for(int i = 0; i < 10; i++)
    {
        if(strcmp(szTemp, a_szColor[i]) == 0)
        {
            llnResult += i;
            break;
        }
    }

    memset(szTemp, 0, sizeof(szTemp));
    scanf("%s", szTemp);
    for(int i = 0; i < 10; i++)
    {
        if(strcmp(szTemp, a_szColor[i]) == 0)
        {
            for(int j = 0; j < i; j++)
            {
                llnResult *= 10;
            }
        }
    }
    printf("%lld\n", llnResult);
    return 0;
}