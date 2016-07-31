#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Problem11051(void)
{
    int nN = 0;
    int nK = 0;
    int **pp_nPascalTriangle = NULL;

    scanf("%d %d", &nN, &nK);

    pp_nPascalTriangle = (int**)malloc(sizeof(int*)*(nN + 1));
    memset(pp_nPascalTriangle, 0, sizeof(int)*(nN + 1));
    for(int i = 0; i <= nN; i++)
    {
        pp_nPascalTriangle[i] = (int*)malloc(sizeof(int)*(nN + 2));
        memset(pp_nPascalTriangle[i], 0, sizeof(int)*(nN + 2));
    }
    pp_nPascalTriangle[0][1] = 1;
    for(int i = 1; i <= nN; i++)
    {
        for(int j = 1; j <= nN+1; j++)
        {
            pp_nPascalTriangle[i][j] = (pp_nPascalTriangle[i - 1][j - 1] + pp_nPascalTriangle[i - 1][j])% 10007;
        }
    }
    printf("%d\n", pp_nPascalTriangle[nN][nK+1]);
    for(int i = 0; i <= nN; i++)
    {
        free(pp_nPascalTriangle[i]);
    }
    free(pp_nPascalTriangle);
    return 0;
}
