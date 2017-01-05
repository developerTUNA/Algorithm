#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _Coordinate11650
{
    int nX;
    int nY;
} typedef Coordiate11650;

int QuickSortCmp11650(Coordiate11650 A, Coordiate11650 B)
{
    if(A.nX < B.nX)
    {
        return 1;
    }
    else if (B.nX < A.nX)
    {
        return -1;
    }
    else
    {
        if (A.nY < B.nY)
        {
            return 1;
        }
        else if (B.nY < A.nY)
        {
            return -1;
        }
    }
    return 0;
}

int QuickSortSwap11650(Coordiate11650 *A, Coordiate11650 *B)
{
    Coordiate11650 Temp;
    Temp = *A;
    *A = *B;
    *B = Temp;
    return 0;
}

int QuickSortPartion11650(int nLeft, int nRight, Coordiate11650 *p_List)
{
    int nPivot = 0;
    int nStore = 0;
    nPivot = (nLeft + nRight) / 2;
    nStore = nLeft;

    QuickSortSwap11650(&p_List[nPivot], &p_List[nRight]);
    for (int i = nLeft; i < nRight; i++)
    {
        if (QuickSortCmp11650(p_List[i], p_List[nRight]) == 1)
        {
            QuickSortSwap11650(&p_List[i], &p_List[nStore]);
            nStore++;
        }
    }
    QuickSortSwap11650(&p_List[nRight], &p_List[nStore]);
    return nStore;
}

int QuickSort11650(int nLeft, int nRight, Coordiate11650 *p_List)
{
    int nPivot = 0;

    if (nLeft < nRight)
    {
        nPivot = QuickSortPartion11650(nLeft, nRight, p_List);
        QuickSort11650(nLeft, nPivot - 1, p_List);
        QuickSort11650(nPivot + 1, nRight, p_List);
    }
    return 0;
}

int Problem11650(void)
{
    int nSize;
    Coordiate11650 *p_List;
    
    scanf("%d", &nSize);
    p_List = malloc(sizeof(Coordiate11650)*nSize);
    for (int i = 0; i < nSize; i++)
    {
        scanf("%d %d", &p_List[i].nX, &p_List[i].nY);
    }

    QuickSort11650(0, nSize - 1, p_List);

    for (int i = 0; i < nSize; i++)
    {
        printf("%d %d\n", p_List[i].nX, p_List[i].nY);
    }
    free(p_List);
    return 0;
}