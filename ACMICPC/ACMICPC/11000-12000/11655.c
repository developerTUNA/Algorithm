#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int Problem11655(void)
{
    char szString[101] = {0,};
    size_t llnStringLen = 0;

    scanf("%[0-9a-zA-Z ]s", szString);
    llnStringLen = strlen(szString);

    for(int i = 0; i < llnStringLen; i++)
    {
        if('a' <= szString[i] && szString[i] <= 'z')
        {
            szString[i] = ((szString[i] - 'a') + 13) % 26 + 'a';
        }
        if('A' <= szString[i] && szString[i] <= 'Z')
        {
            szString[i] = ((szString[i] - 'A') + 13) % 26 + 'A';
        }
    }

    printf("%s\n", szString);
    return 0;
}