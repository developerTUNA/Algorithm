#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int Problem04999(void)
{
    char szPatient[1001] = {0,};
    char szDoctor[1001] = {0,};
    int nPatient = 0;
    int nDoctor = 0;

    scanf("%s", szPatient);
    scanf("%s", szDoctor);

    nPatient = strlen(szPatient);
    nDoctor = strlen(szDoctor);

    if(nDoctor <= nPatient)
    {
        printf("go\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}