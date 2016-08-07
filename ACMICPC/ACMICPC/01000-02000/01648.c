#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GO_DP01648(int **pp_nBox, int nRow, int nCol, int nPos, int nStatus)
{
    int nAnswer = 0;
    int nBoxSize = nRow * nCol;
    if(nPos > nBoxSize)                 //더 넘겨서 계산은 0을 리턴
    {
        return 0;
    }
    if(nPos == nBoxSize && nStatus == 0) //마지막 자리까지 다 체우고, 모두 다 공백인 경우
    {                                   //종료 조건
        return 1;
    }
    if(0 <= pp_nBox[nPos][nStatus])
    {
        return pp_nBox[nPos][nStatus];
    }

    pp_nBox[nPos][nStatus] = 0;
    if(nStatus & 1)//체워야될 자리가 차 있는 경우
    {
        pp_nBox[nPos][nStatus] += GO_DP01648(pp_nBox, nRow, nCol, nPos + 1, nStatus >> 1);
    }
    else
    {
        if(((nStatus & 2) == 0) && ((nPos%nCol) != (nCol - 1)))
        {
            pp_nBox[nPos][nStatus] += GO_DP01648(pp_nBox, nRow, nCol, nPos + 2, nStatus >> 2);
        }
        pp_nBox[nPos][nStatus] += GO_DP01648(pp_nBox, nRow, nCol, nPos + 1, (nStatus >> 1 | 1 << (nCol - 1)));
    }
    pp_nBox[nPos][nStatus] %= 9901;
    return pp_nBox[nPos][nStatus];
}

int Problem01648(void)
{
    int nRow = 0;
    int nCol = 0;
    int nBoxSize = 0;
    int nAnswer = 0;
    int nColShift = 0;
    int **pp_nBox = NULL;

    scanf("%d %d", &nRow, &nCol);
    nBoxSize = nRow*nCol;
    pp_nBox = (int **)malloc(sizeof(int *)*(nBoxSize + 1));
    nColShift = 1 << nCol;
    for(int i = 0; i <= nBoxSize; i++)
    {
        pp_nBox[i] = (int *)malloc(sizeof(int)*(nColShift));
        memset(pp_nBox[i], -1, sizeof(int)*(nColShift));
    }

    nAnswer = GO_DP01648(pp_nBox, nRow, nCol, 0, 0);

    printf("%d\n", nAnswer);
    for(int i = 0; i <= nBoxSize; i++)
    {
        free(pp_nBox[i]);
    }
    free(pp_nBox);
    return 0;
}