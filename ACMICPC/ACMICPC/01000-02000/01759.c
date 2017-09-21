#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Go01759(int nCount, int nLength, char *p_cList, char *p_cMake, int nCheck, int nConsonant, int nVowel)
{
	if (nCount == nConsonant + nVowel)
	{
		if (2 <= nConsonant &&
			1 <= nVowel)
		{
			printf("%s\n", p_cMake);
		}
		return 0;
	}
	if (nLength <= nCheck)
	{
		return 0;
	}
	p_cMake[nConsonant + nVowel] = p_cList[nCheck];
	if (p_cList[nCheck] == 'a' ||
		p_cList[nCheck] == 'e' ||
		p_cList[nCheck] == 'i' ||
		p_cList[nCheck] == 'o' ||
		p_cList[nCheck] == 'u')
	{
		Go01759(nCount, nLength, p_cList, p_cMake, nCheck + 1, nConsonant, nVowel + 1);
	}
	else
	{
		Go01759(nCount, nLength, p_cList, p_cMake, nCheck + 1, nConsonant + 1, nVowel);
	}
	p_cMake[nConsonant + nVowel] = 0;

	Go01759(nCount, nLength, p_cList, p_cMake, nCheck + 1, nConsonant, nVowel);
}

int Problem01759(void)
{
	int nCount = 0;
	int nLength = 0;
	int a_nSort[26] = { 0, };
	char *p_cList = NULL;
	char *p_cMake = NULL;
	scanf("%d %d", &nCount, &nLength);
	p_cList = (char*)malloc(sizeof(char)*nLength);
	memset(p_cList, 0, sizeof(char)*nLength);
	p_cMake = (char*)malloc(sizeof(char)*(nCount + 1));
	memset(p_cMake, 0, sizeof(char)*(nCount + 1));

	for (int i = 0; i < nLength; i++)
	{
		char temp;
		scanf(" %c", &temp);
		a_nSort[temp - 'a'] = 1;
	}
	for (int i = 0, j = 0; i < 26; i++)
	{
		if (a_nSort[i] == 1)
		{
			p_cList[j] = i + 'a';
			j++;
		}
	}

	Go01759(nCount, nLength, p_cList, p_cMake, 0, 0, 0);

	return 0;
}