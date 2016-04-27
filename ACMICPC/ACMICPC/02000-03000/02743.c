#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int Problem02743(void)
{
    char str_str[101] = { 0, };
    scanf("%s", str_str);
    printf("%zd\n", strlen(str_str));
    return 0;
}