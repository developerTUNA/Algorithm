#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _Member10814
{
    int nAge;
    char arr_cName[101];
}typedef Member10814;

int QuickSortSwap10814(Member10814 *MemA, Member10814 *MemB)
{
    Member10814 MemTemp;
    MemTemp = *MemA;
    *MemA = *MemB;
    *MemB = MemTemp;
    return 0;
}

int QuickSortCmp10814(Member10814 MemA, Member10814 MemB)
{
    if (MemA.nAge<MemB.nAge)
    {
        return 1;
    }
    return 0;
}

int QuickSortPartion10814(int nLeft, int nRight, Member10814 *p_MemList)
{
    int nPivot = 0;
    int nStore = 0;

    nPivot = nRight; // 안정성 유지
    nStore = nLeft;
    QuickSortSwap10814(&p_MemList[nPivot], &p_MemList[nRight]);

    for (int i = nLeft; i < nRight; i++)
    {
        if (QuickSortCmp10814(p_MemList[i], p_MemList[nRight])==1)
        {
            QuickSortSwap10814(&p_MemList[i], &p_MemList[nStore]);
            nStore++;
        }
    }
    QuickSortSwap10814(&p_MemList[nStore],&p_MemList[nRight]);

    return nStore;
}

int QuickSort10814(int nLeft, int nRight, Member10814 *p_MemList)
{
    int nPivot = 0;
    if (nLeft < nRight)
    {
        nPivot = QuickSortPartion10814(nLeft, nRight, p_MemList);
        QuickSort10814(nLeft, nPivot - 1, p_MemList);
        QuickSort10814(nPivot + 1, nRight, p_MemList);
    }
    return 0;
}

int Problem10814(void)
{
    int nNum = 0;
    Member10814 *p_MemList = NULL;

    scanf("%d", &nNum);
    p_MemList = malloc(sizeof(Member10814)*nNum);
    memset(p_MemList, 0, sizeof(Member10814)*nNum);

    for (int i = 0; i < nNum; i++)
    {
        scanf("%d %s", &p_MemList[i].nAge, &p_MemList[i].arr_cName);
    }

    QuickSort10814(0, nNum - 1, p_MemList);

    for (int i = 0; i < nNum; i++)
    {
        printf("%d %s\n", p_MemList[i].nAge, p_MemList[i].arr_cName);
    }

    free(p_MemList);
    return 0;
}

int Merge10814(Member10814 *p_MemList, int nStart, int nMid, int nEnd)
{
    Member10814 *p_MemListLeft = NULL;
    Member10814 *p_MemListRight = NULL;
    int nSizeLeft = 0;
    int nSizeRight = 0;
    int nPozLeft = 0;
    int nPozRight = 0;

    nSizeLeft = nMid - nStart + 1;
    nSizeRight = nEnd - nMid;

    p_MemListLeft = malloc(sizeof(Member10814)*(nSizeLeft+1));
    p_MemListRight = malloc(sizeof(Member10814)*(nSizeRight+1));
    memset(p_MemListLeft, 0, sizeof(Member10814)*(nSizeLeft + 1));
    memset(p_MemListRight, 0, sizeof(Member10814)*(nSizeRight + 1));
    memcpy(p_MemListLeft, p_MemList+nStart, sizeof(Member10814)*nSizeLeft);
    memcpy(p_MemListRight, p_MemList+nMid+1, sizeof(Member10814)*nSizeRight);

    p_MemListLeft[nSizeLeft].nAge = 100000;
    p_MemListRight[nSizeRight].nAge = 100000;

    for (int i = nStart; i <= nEnd; i++)
    {
        if (p_MemListLeft[nPozLeft].nAge <= p_MemListRight[nPozRight].nAge)
        {
            p_MemList[i] = p_MemListLeft[nPozLeft];
            nPozLeft++;
        }
        else
        {
            p_MemList[i] = p_MemListRight[nPozRight];
            nPozRight++;
        }
    }

    free(p_MemListLeft);
    free(p_MemListRight);
    return 0;
}

int MergeSort10814(Member10814 *p_MemList, int nStart, int nEnd)
{
    int nMid = 0;
    
    if (nStart < nEnd)
    {
        nMid = (nStart + nEnd) / 2;
        MergeSort10814(p_MemList, nStart, nMid);
        MergeSort10814(p_MemList, nMid + 1, nEnd);
        Merge10814(p_MemList, nStart, nMid, nEnd);
    }
    return 0;
}
int Problem10814_2(void)
{
    int nNum = 0;
    Member10814 *p_MemList = NULL;

    scanf("%d", &nNum);
    p_MemList = malloc(sizeof(Member10814)*nNum);
    memset(p_MemList, 0, sizeof(Member10814)*nNum);

    for (int i = 0; i < nNum; i++)
    {
        scanf("%d %s", &p_MemList[i].nAge, &p_MemList[i].arr_cName);
    }

    MergeSort10814(p_MemList, 0, nNum-1);

    for (int i = 0; i < nNum; i++)
    {
        printf("%d %s\n", p_MemList[i].nAge, p_MemList[i].arr_cName);
    }

    free(p_MemList);
    return 0;
}