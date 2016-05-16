#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int OrderType00000;          //정렬할 기본 데이터형, 이걸 어찌 지정할 방법이 없을까?

typedef struct _QuickSortData00000//사용자가 저장할 데이터 구조체
{
    int nX;
    int nY;
}QuickSortData00000;

typedef struct _QuickSort00000       //퀵정렬 기본
{
    void *p_Data;
    int(*pfunc_PivotRule)(int, int);
    int(*pfunc_Compare)(OrderType00000, OrderType00000);
    OrderType00000(*pfunc_DataGet)(struct _QuickSort00000 *, int);
    OrderType00000(*pfunc_PivotGet)(struct _QuickSort00000 *, int, int);
}QuickSort00000;

//사용자 지정 함수
int QuickSortPivotRule00000(int nLeft, int nRight)
{
    return (nLeft + nRight) / 2;
}
//사용자 지정 함수
int QuickSortCompare00000(OrderType00000 nA, OrderType00000 nB)
{
    if(nA < nB)
    {
        return 1;
    }
    else if(nA == nB)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
//사용자 지정 함수
OrderType00000 QuickSortDataGet00000(QuickSort00000 *pstr_QuickSort, int nIdx)
{
    QuickSortData00000 *p_Data = pstr_QuickSort->p_Data;
    return p_Data[nIdx].nX;                         //data중 어떤 값으로 정렬하는지 지정 nX? nY?
}
//사용자 지정 함수
OrderType00000 QuickSortPivotGet00000(QuickSort00000 *pstr_QuickSort, int nLeft, int nRight)
{
    QuickSortData00000 *p_Data = pstr_QuickSort->p_Data;
    return p_Data[pstr_QuickSort->pfunc_PivotRule(nLeft, nRight)].nX;         //피벗 값 지정
}

//고정 함수, 사용자 실행
int QuickSortInitialize00000(QuickSort00000 *pstr_QuickSort,
                        void *p_Data,
                        int(*pfunc_PivotRule)(int, int),
                        int(*pfunc_Compare)(OrderType00000, OrderType00000),
                        OrderType00000(*pfunc_DataGet)(QuickSort00000 *, int),
                        OrderType00000(*pfunc_PivotGet)(QuickSort00000 *, int, int))
{
    pstr_QuickSort->p_Data = p_Data;
    pstr_QuickSort->pfunc_PivotRule = pfunc_PivotRule;
    pstr_QuickSort->pfunc_Compare = pfunc_Compare;
    pstr_QuickSort->pfunc_DataGet = pfunc_DataGet;
    pstr_QuickSort->pfunc_PivotGet = pfunc_PivotGet;
    return 0;
}

//고정 함수
void QuickSortSwap00000(QuickSort00000 *pstr_QuickSort, int nIdx1, int nIdx2)
{
    QuickSortData00000 *p_Data = pstr_QuickSort->p_Data;
    QuickSortData00000 temp = p_Data[nIdx1];
    p_Data[nIdx1] = p_Data[nIdx2];
    p_Data[nIdx2] = temp;
}

//고정 함수
int QuickSortPartition00000(QuickSort00000 *pstr_QuickSort, int nLeft, int nRight)
{
    OrderType00000 nPivot = pstr_QuickSort->pfunc_PivotGet(pstr_QuickSort, nLeft, nRight);
    int nPivotPoz = pstr_QuickSort->pfunc_PivotRule(nLeft, nRight);
    int nLow = nLeft + 1;
    int nHigh = nRight;
    QuickSortSwap00000(pstr_QuickSort, nPivotPoz, nLeft);
    while(nLow <= nHigh)
    {
        while(0 <= pstr_QuickSort->pfunc_Compare(pstr_QuickSort->pfunc_DataGet(pstr_QuickSort, nLow), nPivot) && nLow <= nRight)
        {
            nLow++;
        }
        while(0 <= pstr_QuickSort->pfunc_Compare(nPivot, pstr_QuickSort->pfunc_DataGet(pstr_QuickSort, nHigh)) && (nLeft + 1) <= nHigh)
        {
            nHigh--;
        }
        if(nLow <= nHigh)
        {
            QuickSortSwap00000(pstr_QuickSort, nLow, nHigh);
        }
    }
    QuickSortSwap00000(pstr_QuickSort, nLeft, nHigh);
    return nHigh;
}

//고정 함수, 사용자 실행
void QuickSortStart00000(QuickSort00000 *pstr_QuickSort, int nLeft, int nRight)
{
    if(nLeft <= nRight)
    {
        OrderType00000 nPivot = QuickSortPartition00000(pstr_QuickSort, nLeft, nRight);
        QuickSortStart00000(pstr_QuickSort, nLeft, nPivot - 1);
        QuickSortStart00000(pstr_QuickSort, nPivot + 1, nRight);
    }
}