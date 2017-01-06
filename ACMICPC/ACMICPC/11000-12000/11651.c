#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _Coordinate11651
{
    int nX;
    int nY;
} typedef Coordiate11651;

int QuickSortCmp11651(Coordiate11651 A, Coordiate11651 B)
{
    if (A.nY < B.nY)
    {
        return 1;
    }
    else if (B.nY < A.nY)
    {
        return -1;
    }
    else
    {
        if (A.nX < B.nX)
        {
            return 1;
        }
        else if (B.nX < A.nX)
        {
            return -1;
        }
    }
    return 0;
}

int QuickSortSwap11651(Coordiate11651 *A, Coordiate11651 *B)
{
    Coordiate11651 Temp;
    Temp = *A;
    *A = *B;
    *B = Temp;
    return 0;
}

int QuickSortPartion11651(int nLeft, int nRight, Coordiate11651 *p_List)
{
    int nPivot = 0;
    int nStore = 0;
    nPivot = (nLeft + nRight) / 2;
    nStore = nLeft;

    QuickSortSwap11651(&p_List[nPivot], &p_List[nRight]);
    for (int i = nLeft; i < nRight; i++)
    {
        if (QuickSortCmp11651(p_List[i], p_List[nRight]) == 1)
        {
            QuickSortSwap11651(&p_List[i], &p_List[nStore]);
            nStore++;
        }
    }
    QuickSortSwap11651(&p_List[nRight], &p_List[nStore]);
    return nStore;
}

int QuickSort11651(int nLeft, int nRight, Coordiate11651 *p_List)
{
    int nPivot = 0;

    if (nLeft < nRight)
    {
        nPivot = QuickSortPartion11651(nLeft, nRight, p_List);
        QuickSort11651(nLeft, nPivot - 1, p_List);
        QuickSort11651(nPivot + 1, nRight, p_List);
    }
    return 0;
}

int Problem11651(void)
{
    int nSize;
    Coordiate11651 *p_List;

    scanf("%d", &nSize);
    p_List = malloc(sizeof(Coordiate11651)*nSize);
    for (int i = 0; i < nSize; i++)
    {
        scanf("%d %d", &p_List[i].nX, &p_List[i].nY);
    }

    QuickSort11651(0, nSize - 1, p_List);

    for (int i = 0; i < nSize; i++)
    {
        printf("%d %d\n", p_List[i].nX, p_List[i].nY);
    }
    free(p_List);
    return 0;
}