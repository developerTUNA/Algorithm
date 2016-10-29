#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem01086(void)
{
    int nNum_Count = 0;
    int nDiv = 0;
    int *p_nRemain = NULL;
    int *p_nNum_Len = NULL;
    char **pp_szNum = NULL;
    
    scanf("%d", &nNum_Count);
    pp_szNum = malloc(sizeof(char *)*(nNum_Count));
    for(int i = 0; i < nNum_Count; i++)
    {
        pp_szNum[i] = malloc(sizeof(char)*(51));
        memset(pp_szNum, 0, sizeof(char)*(51));
        scanf("%s", &pp_szNum[i]);
    }
    scanf("%d", &nDiv);
    p_nRemain = malloc(sizeof(int)*(nNum_Count));
    memset(p_nRemain, 0, sizeof(int)*(nNum_Count));
    p_nNum_Len = malloc(sizeof(int)*(nNum_Count));
    memset(p_nNum_Len, 0, sizeof(int)*(nNum_Count));

    for(int i = 0; i < nNum_Count; i++)
    {
        p_nNum_Len[i] = strlen(pp_szNum[i]);
        for(int j = 0; j < p_nNum_Len[i]; i++)
        {
            p_nRemain[i] = (p_nRemain[i]*10 + (pp_szNum[i][j] - '0')) % nDiv;
        }
    }

    return 0;
}