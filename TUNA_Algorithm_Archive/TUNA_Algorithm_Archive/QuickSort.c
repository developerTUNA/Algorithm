#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int OrderType;          //정렬할 기본 데이터형, 이걸 어찌 지정할 방법이 없을까?

typedef struct _QuickSortData//사용자가 저장할 데이터 구조체
{
    int nX;
    int nY;
}QuickSortData;

typedef struct _QuickSort       //퀵정렬 기본
{
    void *p_Data;
    int(*pfunc_SetPivotRule)(int, int);
    int(*pfunc_Compare)(OrderType, OrderType);
    OrderType(*pfunc_GetData)(struct _QuickSort *, int);
    OrderType(*pfunc_SetPivot)(struct _QuickSort *, int ,int);
}QuickSort;

//사용자 지정 함수
int QuickSortPivotRule(int nLeft, int nRight)
{
    return (nLeft + nRight) / 2;
}
//사용자 지정 함수
int QuickSortCompare(OrderType nA, OrderType nB)
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
OrderType QuickSortGetData(QuickSort *pstr_QuickSort, int nIdx)
{
    QuickSortData *p_Data = pstr_QuickSort->p_Data;
    return p_Data[nIdx].nX;                         //돌려줘야 되는 값을 지정
}
//사용자 지정 함수
OrderType QuickSortSetPivot(QuickSort *pstr_QuickSort, int nLeft, int nRight)
{
    QuickSortData *p_Data = pstr_QuickSort->p_Data;
    return p_Data[pstr_QuickSort->pfunc_SetPivotRule(nLeft, nRight)].nX;         //피벗 선택 방법 지정
}

//고정 함수, 사용자 실행
int QuickSortInitialize(QuickSort *pstr_QuickSort,
                        int (*pfunc_SetPivotRule)(int, int),
                        int(*pfunc_Compare)(OrderType, OrderType),
                        OrderType(*pfunc_GetData)(QuickSort *, int),
                        OrderType(*pfunc_SetPivot)(QuickSort *, int ,int))
{
    pstr_QuickSort->pfunc_SetPivotRule = pfunc_SetPivotRule;
    pstr_QuickSort->pfunc_Compare = pfunc_Compare;
    pstr_QuickSort->pfunc_GetData = pfunc_GetData;
    pstr_QuickSort->pfunc_SetPivot = pfunc_SetPivot;
    return 0;
}

//고정 함수
void QuickSortSwap(QuickSort *pstr_QuickSort, int nIdx1, int nIdx2)
{
    QuickSortData *p_Data = pstr_QuickSort->p_Data;
    QuickSortData temp = p_Data[nIdx1];
    p_Data[nIdx1] = p_Data[nIdx2];
    p_Data[nIdx1] = temp;
}

//고정 함수
int QuickSortPartition(QuickSort *pstr_QuickSort, int nLeft, int nRight)
{
    OrderType nPivot = QuickSortSetPivot(pstr_QuickSort,  nLeft,  nRight);
    int nLow = nLeft + 1;
    int nHigh = nRight;

    while(nLow <= nHigh)
    {
        while(0<=QuickSortCompare(QuickSortGetData(pstr_QuickSort,nLow), nPivot) && nLow<=nRight)
        {
            nLow++;
        }
        while(0<=QuickSortCompare(nPivot,QuickSortGetData(pstr_QuickSort, nHigh))&&(nLeft+1)<=nHigh)
        {
            nHigh--;
        }
        if(nLow <= nHigh)
        {
            QuickSortSwap(pstr_QuickSort, nLow, nHigh);
        }
    }
    QuickSortSwap(pstr_QuickSort, pstr_QuickSort->pfunc_SetPivotRule(nLow,nHigh), nHigh);
    return nHigh;
}

//고정 함수, 사용자 실행
void QuickSortStart(QuickSort *pstr_QuickSort, int nLeft, int nRight)
{
    if(nLeft <= nRight)
    {
        OrderType nPivot = QuickSortPartition(pstr_QuickSort,  nLeft, nRight);
        QuickSortStart(pstr_QuickSort, nLeft, nPivot - 1);
        QuickSortStart(pstr_QuickSort, nPivot + 1, nRight);
    }
}