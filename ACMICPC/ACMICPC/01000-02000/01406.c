#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _Stack01406
{
    size_t nSize;
    char *p_Data;
}Stack01406;

int StackInitialize01046(Stack01406 *Stack, int nSize)
{
    (*Stack).nSize = 0;
    (*Stack).p_Data = malloc(sizeof(char)*nSize);
    memset((*Stack).p_Data, 0, sizeof(char)*nSize);
    return 0;
}
int StackFinalize01046(Stack01406 *Stack)
{
    free((*Stack).p_Data);
    return 0;
}
size_t StackLen01406(Stack01406 Stack)
{
    return Stack.nSize;
}
int StackPush01406(Stack01406 *Stack, char cData)
{
    size_t nPoz = StackLen01406(*Stack);
    (*Stack).p_Data[nPoz] = cData;
    (*Stack).nSize++;
    return 0;
}
int StackPop01406(Stack01406 *Stack, char *cData)
{
    size_t nPoz = StackLen01406(*Stack);
    if(nPoz == 0)
    {
        return 1;
    }
    *cData = (*Stack).p_Data[nPoz - 1];
    (*Stack).p_Data[nPoz - 1] = 0;
    (*Stack).nSize--;
    return 0;
}

int Problem01406(void)
{
    char cTemp = 0;
    char cCommand = 0;
    Stack01406 StackLeft;
    Stack01406 StackRight;
    int nCommand = 0;

    StackInitialize01046(&StackLeft, 600001);
    StackInitialize01046(&StackRight, 600001);
    
    scanf("%s", StackLeft.p_Data);
    StackLeft.nSize = strlen(StackLeft.p_Data);
    scanf("%d", &nCommand);

    for(int i = 0; i < nCommand; i++)
    {
        scanf(" %c", &cCommand);
        if(cCommand == 'L')
        {
            if (StackPop01406(&StackLeft, &cTemp) == 0)
            {
                StackPush01406(&StackRight, cTemp);
            }
        }
        else if(cCommand == 'D')
        {
            if(StackPop01406(&StackRight, &cTemp) == 0)
            {
                StackPush01406(&StackLeft, cTemp);
            }
        }
        else if(cCommand == 'B')
        {
            StackPop01406(&StackLeft, &cTemp);
        }
        else if(cCommand == 'P')
        {
            scanf(" %c", &cTemp);
            StackPush01406(&StackLeft, cTemp);
        }
    }

    while(StackLen01406(StackRight))
    {
        if(StackPop01406(&StackRight, &cTemp) == 0)
        {
            StackPush01406(&StackLeft, cTemp);
        }
    }
    printf("%s\n", StackLeft.p_Data);
    StackFinalize01046(&StackLeft);
    StackFinalize01046(&StackRight);
    return 0;
}