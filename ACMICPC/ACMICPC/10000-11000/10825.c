#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _Exam10825
{
    char arr_cName[100];
    int nKorean;
    int nEnglish;
    int nMath;
}typedef Exam10825;

int QuickSortCmp10825(Exam10825 ExamA, Exam10825 ExamB)
{
    if (ExamB.nKorean < ExamA.nKorean)
    {
        return 1;
    }
    else if (ExamA.nKorean == ExamB.nKorean)
    {
        if (ExamA.nEnglish < ExamB.nEnglish)
        {
            return 1;
        }
        else if (ExamA.nEnglish == ExamB.nEnglish)
        {
            if (ExamB.nMath < ExamA.nMath)
            {
                return 1;
            }
            else if (ExamA.nMath == ExamB.nMath)
            {
                if (strcmp(ExamA.arr_cName, ExamB.arr_cName)<0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int QuickSortSwap10825(Exam10825 *ExamA, Exam10825 *ExamB)
{
    Exam10825 ExamTemp;

    ExamTemp = *ExamA;
    *ExamA = *ExamB;
    *ExamB = ExamTemp;

    return 0;
}

int QuickSortPivot10825(int nLeft, int nRight, Exam10825 *ExamList)
{
    int nStore = 0;
    int nPivot = 0;

    nStore = nLeft;
    nPivot = (nLeft + nRight) / 2;

    QuickSortSwap10825(&ExamList[nPivot], &ExamList[nRight]);

    for (int i = nLeft; i < nRight; i++)
    {
        if (QuickSortCmp10825(ExamList[i], ExamList[nRight]))
        {
            QuickSortSwap10825(&ExamList[i], &ExamList[nStore]);
            nStore++;
        }
    }
    QuickSortSwap10825(&ExamList[nStore], &ExamList[nRight]);
    return nStore;
}

int QuickSort10825(int nLeft, int nRight, Exam10825 *ExamList)
{
    int nPivot = 0;
    if (nLeft < nRight)
    {
        nPivot = QuickSortPivot10825(nLeft, nRight, ExamList);
        QuickSort10825(nLeft, nPivot, ExamList);
        QuickSort10825(nPivot+1, nRight, ExamList);
    }
    return 0;
}
int Problem10825(void)
{
    int nNum = 0;
    Exam10825 *ExamList = NULL;
    
    scanf("%d",&nNum);
    ExamList = malloc(sizeof(Exam10825)*nNum);
    memset(ExamList, 0, sizeof(Exam10825)*nNum);
    for (int i = 0; i < nNum; i++)
    {
        scanf("%s %d %d %d", ExamList[i].arr_cName, &ExamList[i].nKorean, &ExamList[i].nEnglish, &ExamList[i].nMath);
    }

    QuickSort10825(0, nNum - 1, ExamList);

    for (int i = 0; i < nNum; i++)
    {
        printf("%s\n", ExamList[i].arr_cName);
    }

    free(ExamList);
    return 0;
}