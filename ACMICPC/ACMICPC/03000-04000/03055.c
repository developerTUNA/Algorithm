#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _QueueNode03055
{
    int nRow;
    int nCol;
    struct _QueueNode03055 *Next;
}typedef QueueNode03055;


int QueuePush03055(QueueNode03055 **QueueHead, int nRow, int nCol)
{
    QueueNode03055 *QueueNodeNew = NULL;
    QueueNodeNew = malloc(sizeof(QueueNode03055));
    QueueNodeNew->nRow = nRow;
    QueueNodeNew->nCol = nCol;
    QueueNodeNew->Next = *QueueHead;
    *QueueHead = QueueNodeNew;
    return 0;
}

int QueuePop03055(QueueNode03055 **QueueHead, int *nRow, int *nCol)
{
    QueueNode03055 *QueueNext = NULL;
    QueueNode03055 *QueueLast = NULL;
    if (*QueueHead == NULL)
    {
        return -1;
    }
    else if ((*QueueHead)->Next == NULL)
    {
        *nRow = (*QueueHead)->nRow;
        *nCol = (*QueueHead)->nCol;
        free(*QueueHead);
        *QueueHead = NULL;
    }
    else
    {
        QueueNext = *QueueHead;
        QueueLast = (*QueueHead)->Next;
        while (QueueLast->Next != NULL)
        {
            QueueNext = QueueNext->Next;
            QueueLast = QueueNext->Next;
        }
        *nRow = QueueLast->nRow;
        *nCol = QueueLast->nCol;
        QueueNext->Next = NULL;
        free(QueueLast);
    }
    return 0;
}
int BFS03055_Water(int **pp_chMap, int nRow, int nCol)
{
    int arr_nMoveRow[4] = { 1,-1,0,0 };
    int arr_nMoveCol[4] = { 0,0,1,-1 };
    int nRowRet = 0;
    int nColRet = 0;
    QueueNode03055 *QueueHead = NULL;
    for (int i = 1; i <= nRow; i++)
    {
        for (int j = 1; j <= nCol; j++)
        {
            if (pp_chMap[i][j] == 1)
            {
                QueuePush03055(&QueueHead, i, j);
            }
        }
    }
    
    while (QueuePop03055(&QueueHead, &nRowRet, &nColRet) != -1)
    {
        int nTemp = 0;
        nTemp = pp_chMap[nRowRet][nColRet];
        for (int i = 0; i < 4; i++)
        {
            if (pp_chMap[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]]==0)
            {
                pp_chMap[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]] = nTemp + 1;
                QueuePush03055(&QueueHead, nRowRet + arr_nMoveRow[i], nColRet + arr_nMoveCol[i]);
            }
        }
    }
    return 0;
}

int BFS03055_Go(int **pp_chMap_Water, int **pp_chMap_Go, int nRow, int nCol)
{
    int arr_nMoveRow[4] = { 1,-1,0,0 };
    int arr_nMoveCol[4] = { 0,0,1,-1 };
    int nRowRet = 0;
    int nColRet = 0;
    QueueNode03055 *QueueHead = NULL;
    for (int i = 1; i <= nRow; i++)
    {
        for (int j = 1; j <= nCol; j++)
        {
            if (pp_chMap_Go[i][j] == 1)
            {
                QueuePush03055(&QueueHead, i, j);
            }
        }
    }

    while (QueuePop03055(&QueueHead, &nRowRet, &nColRet) != -1)
    {
        int nTemp = 0;
        nTemp = pp_chMap_Go[nRowRet][nColRet];
        for (int i = 0; i < 4; i++)
        {
            if (pp_chMap_Go[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]] != 0) continue;
            if (pp_chMap_Water[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]] == -1 ) continue;
            if (pp_chMap_Water[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]] != 0 &&
                pp_chMap_Water[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]] != -2 &&
                pp_chMap_Water[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]] <= nTemp + 1) continue;
            {
                pp_chMap_Go[nRowRet + arr_nMoveRow[i]][nColRet + arr_nMoveCol[i]] = nTemp + 1;
                QueuePush03055(&QueueHead, nRowRet + arr_nMoveRow[i], nColRet + arr_nMoveCol[i]);
            }
        }
    }
    return 0;
}

int Problem03055(void)
{
    int nRow = 0;
    int nCol = 0;
    int nGoalRow = 0;
    int nGoalCol = 0;
    char chRead = 0;
    int **pp_chMap_Water = NULL;
    int **pp_chMap_Go = NULL;

    scanf("%d %d", &nRow, &nCol);
    pp_chMap_Water = malloc(sizeof(int*)*(nRow + 2));
    pp_chMap_Go = malloc(sizeof(int*)*(nRow + 2));
    for (int i = 0; i < nRow + 2; i++)
    {
        pp_chMap_Water[i] = malloc(sizeof(int)*(nCol + 2));
        memset(pp_chMap_Water[i], -1, sizeof(int)*(nCol + 2));
        pp_chMap_Go[i] = malloc(sizeof(int)*(nCol + 2));
        memset(pp_chMap_Go[i], -1, sizeof(int)*(nCol + 2));
    }

    for (int i = 1; i <= nRow; i++)
    {
        for (int j = 1; j <= nCol; j++)
        {
            while (1)
            {
                scanf("%c", &chRead);
                if (chRead != '\n')
                    break;
            }
            if (chRead == 'D')
            {
                pp_chMap_Water[i][j] = -2;
                pp_chMap_Go[i][j] = 0;
                nGoalRow = i;
                nGoalCol = j;
            }
            else if (chRead == '*')
            {
                pp_chMap_Water[i][j] = 1;
            }
            else if (chRead == 'X')
            {
                //pp_chMap_Water[i][j] = -1;
            }
            else if (chRead == '.')
            {
                pp_chMap_Water[i][j] = 0;
                pp_chMap_Go[i][j] = 0;
            }
            else if (chRead == 'S')
            {
                pp_chMap_Water[i][j] = 0;
                pp_chMap_Go[i][j] = 1;
            }
        }
    }

    BFS03055_Water(pp_chMap_Water, nRow, nCol);
    BFS03055_Go(pp_chMap_Water, pp_chMap_Go, nRow, nCol);

    if (pp_chMap_Go[nGoalRow][nGoalCol] == 0)
    {
        printf("KAKTUS\n");
    }
    else
    {
        printf("%d\n", pp_chMap_Go[nGoalRow][nGoalCol]-1);
    }

    for (int i = 0; i < nRow + 2; i++)
    {
        free(pp_chMap_Water[i]);
        free(pp_chMap_Go[i]);
    }
    free(pp_chMap_Water);
    free(pp_chMap_Go);
    return 0;
}