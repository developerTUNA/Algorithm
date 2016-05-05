#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = 0;
typedef struct _Node01012
{
    int nRow;
    int nCol;
    struct _Node01012 *pNext;
} Node01012;

int QueuePut01012(Node01012 **ppstr_NodeHead, int nRow, int nCol)
{
	top++;
	Node01012 *pstr_NodeHead = *ppstr_NodeHead;
    Node01012 *pstr_NodeNew = NULL;

    pstr_NodeNew = (Node01012*)malloc(sizeof(Node01012));
    pstr_NodeNew->nRow = nRow;
    pstr_NodeNew->nCol = nCol;
    pstr_NodeNew->pNext = NULL;

    if(pstr_NodeHead == NULL)
    {
        *ppstr_NodeHead = pstr_NodeNew;
    }
    else
    {
        while(pstr_NodeHead->pNext != NULL)
        {
            pstr_NodeHead = pstr_NodeHead->pNext;
        }
        pstr_NodeHead->pNext = pstr_NodeNew;
    }
    return 0;
}
int QueueGet01012(Node01012 **ppstr_NodeHead, int *nRow, int *nCol)
{
	
    Node01012 *pstr_NodeSelect = *ppstr_NodeHead;
    if(pstr_NodeSelect == NULL)
    {
        return 1;
    }
	top--;
    *nRow = pstr_NodeSelect->nRow;
    *nCol = pstr_NodeSelect->nCol;
    *ppstr_NodeHead = pstr_NodeSelect->pNext;
    free(pstr_NodeSelect);
    return 0;
}
int BFS01012(int ***ppp_nFarm, int nRow, int nCol)
{
    int nGetRow = 0;
    int nGetCol = 0;
	int nWorm = 0;
	int nMoveRow[4] = { 1,-1,0,0 };
	int nMoveCol[4] = { 0,0,1,-1 };
	int **pp_nFarm = *ppp_nFarm;
	int **pp_nCheck = NULL;
    Node01012 *pstr_NodeHead = NULL;
	
	pp_nCheck = malloc(sizeof(int*)*nRow);
	for (int i = 0; i < nRow; i++)
	{
		pp_nCheck[i] = malloc(sizeof(int*)*nCol);
		memset(pp_nCheck[i], 0, sizeof(int*)*nCol);
	}
    for(int i = 0; i < nRow; i++)
    {
        for(int j = 0; j < nCol; j++)
        {
            if(pp_nFarm[i][j] == 1)
            {
				nWorm++;
                QueuePut01012(&pstr_NodeHead, i, j);
                while(QueueGet01012(&pstr_NodeHead, &nGetRow, &nGetCol)==0)
                {
                    for(int k = 0; k < 4 ;k++)
                    {
						if(0<=nGetRow + nMoveRow[k] && nGetRow + nMoveRow[k]<nRow &&
							0 <= nGetCol + nMoveCol[k] && nGetCol + nMoveCol[k] < nCol &&
							pp_nFarm[nGetRow + nMoveRow[k]][nGetCol + nMoveCol[k]] == 1 &&
							pp_nCheck[nGetRow + nMoveRow[k]][nGetCol + nMoveCol[k]] == 0)
						{	
							QueuePut01012(&pstr_NodeHead, nGetRow + nMoveRow[k], nGetCol + nMoveCol[k]);
							pp_nCheck[nGetRow + nMoveRow[k]][nGetCol + nMoveCol[k]] = 1;
						}
                    }
					pp_nFarm[nGetRow][nGetCol] = 0;
                }
            }
        }
    }
	return nWorm;
}
int Problem01012(void)
{
    int nRound = 0;
    int nRow = 0;
    int nCol = 0;
    int nCabbage = 0;
    int nCabbageRow = 0;
    int nCabbageCol = 0;
    int nWorm = 0;

    int **pp_nFarm = NULL;

    scanf("%d", &nRound);
    for(int i = 0; i < nRound; i++)
    {
        scanf("%d %d %d", &nRow, &nCol, &nCabbage);
        pp_nFarm = (int **)malloc(sizeof(int*)*nRow);
        for(int j = 0; j < nRow; j++)
        {
            pp_nFarm[j] = (int *)malloc(sizeof(int*)*nCol);
			memset(pp_nFarm[j], 0, sizeof(int*)*nCol);
        }
        for(int j = 0; j < nCabbage; j++)
        {
            scanf("%d %d",&nCabbageRow, &nCabbageCol);
            pp_nFarm[nCabbageRow][nCabbageCol] = 1;
        }
		nWorm = BFS01012(&pp_nFarm, nRow, nCol);
		printf("%d\n", nWorm);
		
		for (int j = 0; j < nRow; j++)
		{
			free(pp_nFarm[j]);
		}
		free(pp_nFarm);
    }

    return 0;
}
