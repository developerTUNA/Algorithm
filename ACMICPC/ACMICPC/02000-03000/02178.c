#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node02178
{
    int nRow;
    int nCol;
    struct _Node02178 *pNext;
} Node02178;

int QueuePut02178(Node02178 **pp_NodeHead, int nRow, int nCol)
{
    Node02178 *p_NodeNew;
    Node02178 *p_NodeSearch;
    p_NodeNew = malloc(sizeof(Node02178));
    p_NodeNew->nRow = nRow;
    p_NodeNew->nCol = nCol;
    p_NodeNew->pNext = NULL;

    if (*pp_NodeHead == NULL)
    {
        *pp_NodeHead = p_NodeNew;
    }
    else {
        p_NodeSearch = *pp_NodeHead;
        while (p_NodeSearch->pNext != NULL)
        {
            p_NodeSearch = p_NodeSearch->pNext;
        }
        p_NodeSearch->pNext = p_NodeNew;
    }
    return 0;
}

int QueueGet02178(Node02178 **p_NodeHead, int *nRow, int *nCol)
{
    Node02178 *str_pNodeGet;
    if (*p_NodeHead == NULL)
    {
        return 1;
    }
    str_pNodeGet = *p_NodeHead;
    *p_NodeHead = (*p_NodeHead)->pNext;
    *nRow = str_pNodeGet->nRow;
    *nCol = str_pNodeGet->nCol;
    free(str_pNodeGet);
    return 0;
}

int Problem02178(void)
{

    int nRow = 0;
    int nCol = 0;
    char a_cChar[2] = {'\0','\0'};
    int a_nMoveRow[4] = { 1,-1,0,0 };
    int a_nMoveCol[4] = { 0,0,1,-1 };
    char *p_cLine = NULL;
    int **pp_nMaze = NULL;
    int **pp_nMazeCheck = NULL;
    Node02178 *p_QueHead = NULL;

    scanf("%d %d", &nRow, &nCol);

    p_cLine = (char *)malloc(sizeof(char)*(nCol + 1));
    memset(p_cLine, 0, sizeof(char)*(nCol + 1));
    pp_nMaze = (int **)malloc(sizeof(int*)*(nRow + 2));
    pp_nMazeCheck = (int **)malloc(sizeof(int*)*(nRow + 2));
    for (int i = 0; i < (nRow + 2); i++)
    {
        pp_nMaze[i] = (int *)malloc(sizeof(int)*(nCol + 2));
        pp_nMazeCheck[i] = (int *)malloc(sizeof(int)*(nCol + 2));
        memset(pp_nMaze[i], 0, sizeof(int)*(nCol + 2));
        memset(pp_nMazeCheck[i], 0, sizeof(int)*(nCol + 2));
    }

    for (int i = 1; i < (nRow + 1); i++)
    {
        memset(p_cLine, 0, sizeof(char)*(nCol + 1));
        scanf("%s", p_cLine);
        for (int j = 0; j < nCol; j++)
        {
            memset(a_cChar, 0, 2);
            strncpy(a_cChar, p_cLine + j, 1);
            pp_nMaze[i][j + 1] = atoi(a_cChar);
        }
    }

    QueuePut02178(&p_QueHead, 1, 1);
    pp_nMazeCheck[1][1] = 1;

    while (1)
    {
        int nRowGet = 0;
        int nColGet = 0;
        int nCount = 0;
        QueueGet02178(&p_QueHead, &nRowGet, &nColGet);
        if (nRowGet == nRow && nColGet == nCol)
        {
            break;
        }
        nCount = pp_nMazeCheck[nRowGet][nColGet] + 1;
        for (int i = 0; i < 4; i++)
        {
            int nRowTemp = nRowGet + a_nMoveRow[i];
            int nColTemp = nColGet + a_nMoveCol[i];
            if ((pp_nMaze[nRowTemp][nColTemp] == 1) &&
                (pp_nMazeCheck[nRowTemp][nColTemp] == 0))
            {
                pp_nMazeCheck[nRowTemp][nColTemp] = nCount;
                QueuePut02178(&p_QueHead, nRowTemp, nColTemp);
            }
        }
    }
    printf("%d\n", pp_nMazeCheck[nRow][nCol]);

    free(p_cLine);
    for (int i = 0; i < (nRow + 2); i++)
    {
        free(pp_nMaze[i]);
        free(pp_nMazeCheck[i]);
    }
    free(pp_nMaze);
    free(pp_nMazeCheck);
    return 0;
}