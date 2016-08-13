#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t StackLen10799(char *p_szStack)
{
    return strlen(p_szStack);
}
int StackPush10799(char *p_szStack, char cData)
{
    size_t nPoz = StackLen10799(p_szStack);
    p_szStack[nPoz] = cData;
    return 0;
}
int StackPop10799(char *p_szStack, char *cData)
{
    size_t nPoz = StackLen10799(p_szStack);
    *cData = p_szStack[nPoz];
    p_szStack[nPoz-1] = 0;
    return 0;
}

int Problem10799(void)
{
    char cTemp = 0;
    char *p_szString = NULL;
    char *p_szStack = NULL;
    size_t nStringLen = 0;
    size_t nPices = 0;
    p_szString = malloc(sizeof(char) * 100001);
    p_szStack = malloc(sizeof(char) * 100001);
    memset(p_szString, 0, sizeof(char) * 100001);
    memset(p_szStack, 0, sizeof(char) * 100001);
    scanf("%s", p_szString);
    nStringLen = strlen(p_szString);
    
    for(int i = 0; i < nStringLen; i++)
    {
        if(i+1 < nStringLen && p_szString[i] == '(' && p_szString[i+1] == ')')
        {
            nPices += StackLen10799(p_szStack);
            i++;
        }
        else if(p_szString[i] == '(')
        {
            StackPush10799(p_szStack, '(');
        }
        else if(p_szString[i] == ')')
        {
            StackPop10799(p_szStack, &cTemp);
            nPices += 1;
        }
    }

    free(p_szString);
    free(p_szStack);
    printf("%zd\n", nPices);
    return 0;
}