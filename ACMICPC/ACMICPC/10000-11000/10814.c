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