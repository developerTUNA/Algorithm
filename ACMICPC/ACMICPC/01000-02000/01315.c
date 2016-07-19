#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Quest01315
{
    int nStr;
    int nInt;
    int nPoint;
}Quest01315;

int Problem01315(void)
{
    int nQuestNum = 0;
    int nQuestClearMax = 0;
    int **pp_nStrIntPossible = NULL;
    int **pp_nFreePoint = NULL;
    Quest01315 *p_QuestList = NULL;

    scanf("%d", &nQuestNum);
    p_QuestList = (Quest01315 *)malloc(sizeof(Quest01315)*nQuestNum);
    memset(p_QuestList, 0, sizeof(Quest01315)*nQuestNum);
    pp_nStrIntPossible = (int**)malloc(sizeof(int*) * 1001);
    pp_nFreePoint = (int**)malloc(sizeof(int*) * 1001);
    for(int i = 0; i < 1001; i++)
    {
        pp_nStrIntPossible[i] = (int*)malloc(sizeof(int) * 1001);
        pp_nFreePoint[i] = (int *)malloc(sizeof(int) * 1001);
        memset(pp_nStrIntPossible[i], 0, sizeof(int) * 1001);
        memset(pp_nFreePoint[i], 0, sizeof(int) * 1001);
    }

    for(int i = 0; i < nQuestNum; i++)
    {
        scanf("%d %d %d", &p_QuestList[i].nStr, &p_QuestList[i].nInt, &p_QuestList[i].nPoint);
    }

    for(int nStr = 1; nStr <= 1000; nStr++)
    {
        for(int nInt = 1; nInt <= 1000; nInt++)
        {
            int nQuestPossible = 0;
            pp_nFreePoint[nStr][nInt] = 2 - (nStr + nInt);

            for(int i = 0; i < nQuestNum; i++)
            {
                if(p_QuestList[i].nStr <= nStr || p_QuestList[i].nInt <= nInt)
                {
                    pp_nFreePoint[nStr][nInt] += p_QuestList[i].nPoint;
                    nQuestPossible += 1;
                }
            }

            if(nStr == 1 || nInt == 1)
            {
                pp_nStrIntPossible[nStr][nInt] = 1;
                if(nQuestClearMax < nQuestPossible)
                {
                    nQuestClearMax = nQuestPossible;
                }
            }
            else if(pp_nStrIntPossible[nStr - 1][nInt] && 0 < pp_nFreePoint[nStr][nInt])
            {
                pp_nStrIntPossible[nStr][nInt] = 1;
                if(nQuestClearMax < nQuestPossible)
                {
                    nQuestClearMax = nQuestPossible;
                }
            }
            else if(pp_nStrIntPossible[nStr - 1][nInt] && 0 < pp_nFreePoint[nStr][nInt])
            {
                pp_nStrIntPossible[nStr][nInt] = 1;
                if(nQuestClearMax < nQuestPossible)
                {
                    nQuestClearMax = nQuestPossible;
                }
            }
        }
    }

    printf("%d\n", nQuestClearMax);
    free(p_QuestList);
    return 0;
}