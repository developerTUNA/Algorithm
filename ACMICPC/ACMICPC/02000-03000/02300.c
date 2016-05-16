#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX02300(a,b) ((a)<(b)?(b):(a))
#define ABS02300(a) ((a)<0?(-a):(a))

typedef int OrderType02300;          //정렬할 기본 데이터형, 이걸 어찌 지정할 방법이 없을까?

typedef struct _QuickSortData02300//사용자가 저장할 데이터 구조체
{
    int nX;
    int nY;
}QuickSortData02300;

typedef struct _QuickSort02300       //퀵정렬 기본
{
    void *p_Data;
    int(*pfunc_PivotRule)(int, int);
    int(*pfunc_Compare)(OrderType02300, OrderType02300);
    OrderType02300(*pfunc_DataGet)(struct _QuickSort02300 *, int);
    OrderType02300(*pfunc_PivotGet)(struct _QuickSort02300 *, int, int);
}QuickSort02300;

//사용자 지정 함수
int QuickSortPivotRule02300(int nLeft, int nRight)
{
    return (nLeft + nRight) / 2;
}
//사용자 지정 함수
int QuickSortCompare02300(OrderType02300 nA, OrderType02300 nB)
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
OrderType02300 QuickSortDataGet02300(QuickSort02300 *pstr_QuickSort, int nIdx)
{
    QuickSortData02300 *p_Data = pstr_QuickSort->p_Data;
    return p_Data[nIdx].nX;                         //data중 어떤 값으로 정렬하는지 지정 nX? nY?
}
//사용자 지정 함수
OrderType02300 QuickSortPivotGet02300(QuickSort02300 *pstr_QuickSort, int nLeft, int nRight)
{
    QuickSortData02300 *p_Data = pstr_QuickSort->p_Data;
    return p_Data[pstr_QuickSort->pfunc_PivotRule(nLeft, nRight)].nX;         //피벗 값 지정
}

//고정 함수, 사용자 실행
int QuickSortInitialize02300(QuickSort02300 *pstr_QuickSort,
                             void *p_Data,
                             int(*pfunc_PivotRule)(int, int),
                             int(*pfunc_Compare)(OrderType02300, OrderType02300),
                             OrderType02300(*pfunc_DataGet)(QuickSort02300 *, int),
                             OrderType02300(*pfunc_PivotGet)(QuickSort02300 *, int, int))
{
    pstr_QuickSort->p_Data = p_Data;
    pstr_QuickSort->pfunc_PivotRule = pfunc_PivotRule;
    pstr_QuickSort->pfunc_Compare = pfunc_Compare;
    pstr_QuickSort->pfunc_DataGet = pfunc_DataGet;
    pstr_QuickSort->pfunc_PivotGet = pfunc_PivotGet;
    return 0;
}

//고정 함수
void QuickSortSwap02300(QuickSort02300 *pstr_QuickSort, int nIdx1, int nIdx2)
{
    QuickSortData02300 *p_Data = pstr_QuickSort->p_Data;
    QuickSortData02300 temp = p_Data[nIdx1];
    p_Data[nIdx1] = p_Data[nIdx2];
    p_Data[nIdx2] = temp;
}

//고정 함수
int QuickSortPartition02300(QuickSort02300 *pstr_QuickSort, int nLeft, int nRight)
{
    OrderType02300 nPivot = pstr_QuickSort->pfunc_PivotGet(pstr_QuickSort, nLeft, nRight);
    int nPivotPoz = pstr_QuickSort->pfunc_PivotRule(nLeft, nRight);
    int nLow = nLeft + 1;
    int nHigh = nRight;
    QuickSortSwap02300(pstr_QuickSort, nPivotPoz, nLeft);
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
            QuickSortSwap02300(pstr_QuickSort, nLow, nHigh);
        }
    }
    QuickSortSwap02300(pstr_QuickSort, nLeft, nHigh);
    return nHigh;
}

//고정 함수, 사용자 실행
void QuickSortStart02300(QuickSort02300 *pstr_QuickSort, int nLeft, int nRight)
{
    if(nLeft <= nRight)
    {
        OrderType02300 nPivot = QuickSortPartition02300(pstr_QuickSort, nLeft, nRight);
        QuickSortStart02300(pstr_QuickSort, nLeft, nPivot - 1);
        QuickSortStart02300(pstr_QuickSort, nPivot + 1, nRight);
    }
}


int Problem02300(void)
{
    int nBuilding = 0;
    int nMax = 0;
    int *nPrice = NULL;
    QuickSort02300 pstr_Qsort;
    QuickSortData02300 *p_XY = NULL;
    scanf("%d", &nBuilding);
    p_XY = malloc(sizeof(QuickSortData02300)*(nBuilding + 1));
    nPrice = malloc(sizeof(int)*(nBuilding+1));
    memset(p_XY, 0, sizeof(QuickSortData02300)*(nBuilding + 1));
    memset(nPrice, 0, sizeof(int)*(nBuilding + 1));
    for(int i = 1; i <= nBuilding; i++)
    {
        scanf("%d %d", &p_XY[i].nX, &p_XY[i].nY);
        if(p_XY[i].nY < 0)
        {
            p_XY[i].nY = -p_XY[i].nY;
        }
        if(nMax < p_XY[i].nX)
        {
            nMax = p_XY[i].nX;
        }
        if(nMax < p_XY[i].nY)
        {
            nMax = p_XY[i].nY;
        }
    }

    QuickSortInitialize02300(&pstr_Qsort, p_XY+1, QuickSortPivotRule02300, QuickSortCompare02300, QuickSortDataGet02300, QuickSortPivotGet02300);
    QuickSortStart02300(&pstr_Qsort,0, nBuilding-1);

    nPrice[0] = 0;
    for(int i = 1; i <= nBuilding; i++)
    {
        int nUp = 0;
        nPrice[i] = nMax*2;
        for(int j = i; 1 <= j; j--)
        {
            nUp = MAX02300(nUp , p_XY[j].nY);
            int nLenIJ = MAX02300(p_XY[i].nX - p_XY[j].nX,nUp*2);
            if(nPrice[j - 1] + nLenIJ < nPrice[i] )
            {
                nPrice[i] = nPrice[j - 1] + nLenIJ;
            }
        }
    }

    printf("%d\n", nPrice[nBuilding]);
    free(p_XY);
    free(nPrice);
    return 0;
}