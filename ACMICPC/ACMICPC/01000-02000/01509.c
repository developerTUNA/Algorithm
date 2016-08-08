#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN01509(a,b) (a)<(b) ? (a) : (b);

int GO_DP01509(int **pp_nString_DP, char *p_cString, int nStart, int nEnd)
{
    if(nEnd<nStart)
    {
        pp_nString_DP[nStart][nEnd] = 0;
    }
    else if(0 <= pp_nString_DP[nStart][nEnd])
    {
        return pp_nString_DP[nStart][nEnd];
    }
    else if(nStart == nEnd)
    {
        pp_nString_DP[nStart][nEnd] = 1;
    }
    else if(nStart == nEnd - 1)
    {
        if(p_cString[nStart] == p_cString[nEnd])
        {
            pp_nString_DP[nStart][nEnd] = 1;
        }
        else
        {
            pp_nString_DP[nStart][nEnd] = 0;
        }
    }
    else if(p_cString[nStart] != p_cString[nEnd])
    {
        pp_nString_DP[nStart][nEnd] = 0;
    }
    else if(p_cString[nStart] == p_cString[nEnd])
    {
        pp_nString_DP[nStart][nEnd] = GO_DP01509(pp_nString_DP, p_cString, nStart + 1, nEnd - 1);
    }
    return pp_nString_DP[nStart][nEnd];
}

int Problem01509(void)
{
    char cString[2502];
    int nString_Len = 0;
    int nMin = 0;
    int *p_nString_DP = NULL;
    int **pp_nString_DP = NULL;

    scanf("%s", cString+1);
    nString_Len = (int)strlen(cString+1);
    p_nString_DP = (int*)malloc(sizeof(int)*(nString_Len+1));
    memset(p_nString_DP, 0, sizeof(int)*(nString_Len + 1));
    pp_nString_DP = (int**)malloc(sizeof(int*)*(nString_Len + 1));
    for(int i = 0; i <= nString_Len; i++)
    {
        pp_nString_DP[i] = (int*)malloc(sizeof(int)*(nString_Len + 1));
        memset(pp_nString_DP[i], -1, sizeof(int)*(nString_Len + 1));
    }
    
    for(int i = 1; i <= nString_Len; i++)
    {
        nMin = i;
        for(int j = 1; j <= i; j++)
        {
            if(GO_DP01509(pp_nString_DP,cString,j,i))
            {
                nMin = MIN01509 (nMin, p_nString_DP[j-1] + 1);
            }
        }
        p_nString_DP[i] = nMin;
    }

    printf("%d", p_nString_DP[nString_Len]);
    free(p_nString_DP);
    for(int i = 0; i <= nString_Len; i++)
    {
        free(pp_nString_DP[i]);
    }
    free(pp_nString_DP);
    return 0;
}


int Problem01509_2(void)
{
    char cString[2502];
    int nString_Len = 0;
    int nMin = 0;
    int *p_nString_DP = NULL;
    int **pp_nString_DP = NULL;

    scanf("%s", cString + 1);
    nString_Len = (int)strlen(cString + 1);
    p_nString_DP = (int*)malloc(sizeof(int)*(nString_Len + 1));
    memset(p_nString_DP, 0, sizeof(int)*(nString_Len + 1));
    pp_nString_DP = (int**)malloc(sizeof(int*)*(nString_Len + 1));
    for(int i = 0; i <= nString_Len; i++)
    {
        pp_nString_DP[i] = (int*)malloc(sizeof(int)*(nString_Len + 1));
        memset(pp_nString_DP[i], -1, sizeof(int)*(nString_Len + 1));
    }

    for(int i = 1; i <= nString_Len; i++)
    {
        pp_nString_DP[i][i] = 1;
    }

    for(int i = 2; i <= nString_Len; i++)
    {
        if(cString[i - 1] == cString[i])
        {
            pp_nString_DP[i - 1][i] = 1;
        }
        else
        {
            pp_nString_DP[i - 1][i] = 0;
        }
    }

    for(int nGap = 2; nGap < nString_Len; nGap++)
    {
        for(int i = 1; i <= nString_Len-nGap; i++)
        {
            int j = i + nGap;

            if(cString[i] == cString[j] && pp_nString_DP[i+1][j-1]==1)
            {
                pp_nString_DP[i][j] = 1;
            }
            else
            {
                pp_nString_DP[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= nString_Len; i++)
    {
        nMin = i;
        for(int j = 1; j <= i; j++)
        {
            if(pp_nString_DP[j][i])
            {
                nMin = MIN01509(nMin, p_nString_DP[j - 1] + 1);
            }
        }
        p_nString_DP[i] = nMin;
    }

    printf("%d", p_nString_DP[nString_Len]);
    free(p_nString_DP);
    for(int i = 0; i <= nString_Len; i++)
    {
        free(pp_nString_DP[i]);
    }
    free(pp_nString_DP);
    return 0;
}