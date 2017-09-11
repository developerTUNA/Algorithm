#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TryData02580_
{
	int nRow;
	int nCol;
	int nValue;
}TryData02580;

int Problem02580(void)
{
	int nDeep = 0;
	int nDone = 0;
	TryData02580 TryStack[82] = { 0, };
	int aaaa_nBox[82][9][9][10] = { 0, };
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &aaaa_nBox[0][i][j][0]);
		}
	}
	int nRound = 0;
	while (nDone != 1)
	{
		nRound++;
		//검사 배열 채우기
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (aaaa_nBox[nDeep][i][j][0] != 0)
				{
					for (int k = 0; k < 9; k++)
					{
						aaaa_nBox[nDeep][i][k][aaaa_nBox[nDeep][i][j][0]] = 1;
						aaaa_nBox[nDeep][k][j][aaaa_nBox[nDeep][i][j][0]] = 1;
					}
					for (int k = (i / 3) * 3; k < ((i / 3) + 1) * 3; k++)
					{
						for (int l = (j / 3) * 3; l < ((j / 3) + 1) * 3; l++)
						{
							aaaa_nBox[nDeep][k][l][aaaa_nBox[nDeep][i][j][0]] = 1;
						}
					}
				}
			}
		}

		//답이 있는지 변경
		int nChange = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int nFix = 0;
				int nSet = 0;
				if (aaaa_nBox[nDeep][i][j][0] == 0)
				{
					for (int k = 1; k < 10; k++)
					{
						if (aaaa_nBox[nDeep][i][j][k] == 0)
						{
							nFix++;
							nSet = k;
						}
					}
					if (nFix == 1)
					{
						aaaa_nBox[nDeep][i][j][0] = nSet;
						nChange = 1;
					}
				}
			}
		}

		//다 채워졌는지 검사
		nDone = 1;
		for (int i = 0; i < 9; i++) //가로 세로 검사
		{
			int nRowCheck = 0;
			int nColCheck = 0;
			int nRowSum = 0;
			int nColSum = 0;
			int nRowSave = 0;
			int nColSave = 0;
			for (int j = 0; j < 9; j++)
			{
				if (aaaa_nBox[nDeep][i][j][0] != 0)
				{
					nRowCheck++;
					nRowSum += aaaa_nBox[nDeep][i][j][0];
				}
				else
				{
					nRowSave = j;
				}
				if (aaaa_nBox[nDeep][j][i][0] != 0)
				{
					nColCheck++;
					nColSum += aaaa_nBox[nDeep][j][i][0];
				}
				else
				{
					nColSave = j;
				}
			}
			if (nRowCheck == 9 && nRowSum != 45)		//다 찼는데, 1~9 아님
			{
				nDone = -1;
				break;
			}
			else if (nRowCheck == 8 && aaaa_nBox[nDeep][i][nRowSave][45 - nRowSum] == 1) // 1칸 비었는데 못들어감
			{
				nDone = -1;
				break;
			}
			else if (nRowCheck != 9)					//아직 다 안참
			{
				nDone = 0;
			}

			if (nColCheck == 9 && nColSum != 45)
			{
				nDone = -1;
				break;
			}
			else if (nColCheck == 8 && aaaa_nBox[nDeep][nColSave][i][45 - nColSum] == 1)
			{
				nDone = -1;
				break;
			}
			else if (nColCheck != 9)
			{
				nDone = 0;
			}
		}
		if (nDone == 1) //블럭 검사
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					int nBlockCheck = 0;
					int nBlockSum = 0;
					int nBlockSave_Row = 0;
					int nBlockSave_Col = 0;
					for (int k = 0; k < 3; k++)
					{
						for (int l = 0; l < 3; l++)
						{
							if (aaaa_nBox[nDeep][i * 3 + k][j * 3 + l][0] != 0)
							{
								nBlockCheck++;
								nBlockSum += aaaa_nBox[nDeep][i * 3 + k][j * 3 + l][0];
							}
							else
							{
								nBlockSave_Row = i * 3 + k;
								nBlockSave_Col = j * 3 + l;
							}
						}
					}
					if (nBlockCheck == 9 && nBlockSum != 45)
					{
						i = 3;
						j = 3;
						nDone = -1;
						break;
					}
					else if (nBlockCheck == 8 && aaaa_nBox[nDeep][nBlockSave_Row][nBlockSave_Col][45 - nBlockSum] == 1)
					{
						i = 3;
						j = 3;
						nDone = -1;
						break;
					}
					else if (nBlockCheck != 9)
					{
						nDone = 0;
					}
				}
			}
		}
		if (nDone == -1)
		{
			aaaa_nBox[nDeep - 1][TryStack[nDeep].nRow][TryStack[nDeep].nCol][TryStack[nDeep].nValue] = 1;
			memset(&TryStack[nDeep], 0, sizeof(TryStack[nDeep]));
			memset(&aaaa_nBox[nDeep], 0, sizeof(aaaa_nBox[nDeep]));
			nDeep--;
			continue;
		}
		else if (nDone == 1)
		{
			break;
		}

		//임의의 값 예측해서 집어넣거나, 예측이 틀림
		if (nChange == 0)
		{
			//임의의 값 찾기
			int nFind = 0;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (aaaa_nBox[nDeep][i][j][0] == 0)
					{
						for (int k = 1; k < 10; k++)
						{
							if (aaaa_nBox[nDeep][i][j][k] == 0)		//스택 집어넣기
							{										//임의 값 발견 
								nFind = 1;
								nDeep++;
								memcpy(aaaa_nBox[nDeep], aaaa_nBox[nDeep - 1], sizeof(aaaa_nBox[nDeep]));
								aaaa_nBox[nDeep][i][j][0] = k;
								TryStack[nDeep].nRow = i;
								TryStack[nDeep].nCol = j;
								TryStack[nDeep].nValue = k;
								i = 9;
								j = 9;
								k = 10;
							}
						}
					}
				}
			}
			if (nFind == 0)	//변경 가능한 값 못찾음, 예측 실패
			{				//스택 꺼내기
				aaaa_nBox[nDeep - 1][TryStack[nDeep].nRow][TryStack[nDeep].nCol][TryStack[nDeep].nValue] = 1;
				memset(&TryStack[nDeep], 0, sizeof(TryStack[nDeep]));
				memset(&aaaa_nBox[nDeep], 0, sizeof(aaaa_nBox[nDeep]));
				nDeep--;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", aaaa_nBox[nDeep][i][j][0]);
		}
		printf("\n");
	}

	return 0;
}
