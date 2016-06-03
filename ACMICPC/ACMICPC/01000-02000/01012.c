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

int QueuePut01012(Node01012 **pp_NodeHead, int nRow, int nCol)
{
	top++;
	Node01012 *p_NodeHead = *pp_NodeHead;
    Node01012 *p_NodeNew = NULL;

    p_NodeNew = (Node01012*)malloc(sizeof(Node01012));
    p_NodeNew->nRow = nRow;
    p_NodeNew->nCol = nCol;
    p_NodeNew->pNext = NULL;

    if(p_NodeHead == NULL)
    {
        *pp_NodeHead = p_NodeNew;
    }
    else
    {
        while(p_NodeHead->pNext != NULL)
        {
            p_NodeHead = p_NodeHead->pNext;
        }
        p_NodeHead->pNext = p_NodeNew;
    }
    return 0;
}
int QueueGet01012(Node01012 **pp_NodeHead, int *nRow, int *nCol)
{
	
    Node01012 *p_NodeSelect = *pp_NodeHead;
    if(p_NodeSelect == NULL)
    {
        return 1;
    }
	top--;
    *nRow = p_NodeSelect->nRow;
    *nCol = p_NodeSelect->nCol;
    *pp_NodeHead = p_NodeSelect->pNext;
    free(p_NodeSelect);
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
    Node01012 *p_NodeHead = NULL;
	
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
                QueuePut01012(&p_NodeHead, i, j);
                while(QueueGet01012(&p_NodeHead, &nGetRow, &nGetCol)==0)
                {
                    for(int k = 0; k < 4 ;k++)
                    {
						if(0<=nGetRow + nMoveRow[k] && nGetRow + nMoveRow[k]<nRow &&
							0 <= nGetCol + nMoveCol[k] && nGetCol + nMoveCol[k] < nCol &&
							pp_nFarm[nGetRow + nMoveRow[k]][nGetCol + nMoveCol[k]] == 1 &&
							pp_nCheck[nGetRow + nMoveRow[k]][nGetCol + nMoveCol[k]] == 0)
						{	
							QueuePut01012(&p_NodeHead, nGetRow + nMoveRow[k], nGetCol + nMoveCol[k]);
							pp_nCheck[nGetRow + nMoveRow[k]][nGetCol + nMoveCol[k]] = 1;
						}
                    }
					pp_nFarm[nGetRow][nGetCol] = 0;
                }
            }
        }
    }
	
	for (int i = 0; i < nRow; i++)
	{
		free(pp_nCheck[i]);
	}
	free(pp_nCheck);
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
