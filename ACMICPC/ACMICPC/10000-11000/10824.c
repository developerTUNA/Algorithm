#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Problem10824(void)
{
    char szA[20] = {0,};
    char szB[20] = {0,};
    char szC[20] = {0,};
    char szD[20] = {0,};
    long long llnA = 0;
    long long llnC = 0;

    scanf("%s", szA);
    scanf("%s", szB);
    scanf("%s", szC);
    scanf("%s", szD);

    strcat(szA, szB);
    strcat(szC, szD);

    llnA = atoll(szA);
    llnC = atoll(szC);

    printf("%lld\n", llnA + llnC);
    return 0;
}