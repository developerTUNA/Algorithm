#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int Problem01032(void)
{
	char arr_strFileName[50][51] = { 0, };
	char strResult[51] = { 0, };
	int nFileNum = 0;
	int nFileNameSize = 0;

	scanf("%d", &nFileNum);
	for (int i = 0; i < nFileNum; i++)
	{
		scanf("%s", arr_strFileName[i]);
	}

	nFileNameSize = strlen(arr_strFileName[0]);
	strcpy(strResult, arr_strFileName[0]);

	for (int i = 0; i < nFileNameSize; i++)
	{
		for (int j = 1; j < nFileNum; j++)
		{
			if (strResult[i] != arr_strFileName[j][i])
			{
				strResult[i] = '?';
				break;
			}
		}
	}
	printf("%s\n", strResult);
	return 0;
}