#pragma warning (disable:4996)
#include <stdio.h>

int Problem02744(void)
{
    char szString[101] = {0,};
    
    scanf("%s", szString);
    for(int i = 0; szString[i]; i++)
    {
        if('a' <= szString[i] && szString[i] <= 'z')
        {
            szString[i] += 'A' - 'a';
        }
        else if('A' <= szString[i] && szString[i] <= 'Z')
        {
            szString[i] += 'a' - 'A';
        }
    }
    
    printf("%s", szString);
    return 0;
}