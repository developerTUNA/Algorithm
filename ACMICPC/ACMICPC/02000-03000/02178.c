#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node02178
{
    int nData;
    Node02178 *pNext;
} Node02178;

int QueuePut02178(Node02178** ppstr_NodeHead, int nData)
{
    Node02178 *pstr_NodeHead = *ppstr_NodeHead;
    Node02178 *pstr_NodeNew;
    
    pstr_NodeNew = malloc(sizeof(Node02178));
    pstr_NodeNew->nData = nData;
    pstr_NodeNew->pNext = NULL;
    if (pstr_NodeHead == NULL)
    {
        pstr_NodeHead = pstr_NodeNew;
    }
    else{
        while (pstr_NodeHead->pNext != NULL)
        {
            pstr_NodeHead = pstr_NodeHead->pNext;
        }
        pstr_NodeHead->pNext = pstr_NodeNew;
    }
    return 0;
}

int QueueGet02178(Node02178* pstr_NodeHead, int *nData)
{
    Node02178 *str_pNodeGet;
    if (pstr_NodeHead == NULL)
    {
        return 1;
    }
    str_pNodeGet = pstr_NodeHead;
    pstr_NodeHead = pstr_NodeHead->pNext;
    *nData = str_pNodeGet->nData;
    free(str_pNodeGet);
    return 0;
}

int Problem02178(void)
{
    char arr_cChar[2] = "\0\0";
    int nRow = 0;
    int nCol = 0;
    int nFlag = 0;
    int nCount = 0;
    char * p_cLine = NULL;
    int ** pp_nMaze = NULL;
    Node02178 *pstr_QueHead;

    scanf("%d %d", &nRow, &nCol);
    
    p_cLine = (char *)malloc(sizeof(char)*(nRow + 1));
    memset(p_cLine, 0, sizeof(char)*(nRow + 1));
    pp_nMaze = (int **)malloc(sizeof(int*)*(nRow+2));
    for(int i=0; i<(nRow+2); i++)
    {
        pp_nMaze[i] = (int *)malloc(sizeof(int)*(nCol + 2));
        memset(pp_nMaze[i], 0, sizeof(int)*(nCol + 2));
    }

    for (int i = 1; i<nRow+1; i++)
    {
        scanf("%s", p_cLine);
        for (int j = 0; j < nCol; j++)
        {
            strncpy(arr_cChar, p_cLine+j, 1);
            pp_nMaze[i][j + 1] = atoi(arr_cChar);
        }
    }

    QueuePut02178(pstr_QueHead, nCol+1);
    nCount = 1;
    
    nFlag = 1;
    while (nFlag)
    {
        int nRowCol = 0;
        QueueGet02178(pstr_QueHead, &nRowCol);
    }

    return 0;
}