#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int Merge11652(void *data, int esize, int i, int j, int k, int(*compare)(const void*key1, const void*key2))
{
	char *a = data;
	char *m = NULL;
	int ipos = 0;
	int jpos = 0;
	int mpos = 0;

	ipos = i;
	jpos = j + 1;
	mpos = 0;

	if ((m = (char *)malloc(esize * ((k - i) + 1))) == NULL)
	{
		return -1;
	}
	while (ipos <= j || jpos <= k)
	{
		if (ipos > j)
		{
			while (jpos <= k)
			{
				memcpy(&m[mpos * esize], &a[jpos*esize], esize);
				jpos++;
				mpos++;
			}
			continue;
		}
		else if (jpos > k)
		{
			while (ipos <= j)
			{
				memcpy(&m[mpos*esize], &a[ipos*esize], esize);
				ipos++;
				mpos++;
			}
			continue;
		}
		if (compare(&a[ipos*esize], &a[jpos*esize]) < 0)
		{
			memcpy(&m[mpos*esize], &a[ipos*esize], esize);
			ipos++;
			mpos++;
		}
		else
		{
			memcpy(&m[mpos*esize], &a[jpos*esize], esize);
			jpos++;
			mpos++;
		}
	}
	memcpy(&a[i*esize], m, esize * ((k - i) + 1));
	free(m);

	return 0;
}

int Mgsort11652(void *data, int size, int esize, int i, int k, int(*compare)(const void* key1, const void *key2))
{
	int j = 0;
	if (i < k)
	{
		j = (int)((i + k - 1) / 2);
		if (Mgsort11652(data, size, esize, i, j, compare) < 0)
		{
			return -1;
		}
		if (Mgsort11652(data, size, esize, j + 1, k, compare) < 0)
		{
			return -1;
		}
		if (Merge11652(data, esize, i, j, k, compare) < 0)
		{
			return -1;
		}
	}

	return 0;
}

int Compare11652(const void *key1, const void *key2)
{
	long long llnKey1 = *(long long *)key1;
	long long llnKey2 = *(long long *)key2;
	if (llnKey1 > llnKey2)
	{
		return 1;
	}
	else if (llnKey1 == llnKey2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int Problem11652(void)
{
	long long *p_llnInput = NULL;
	int nInputSize = 0;
	int nCardCount = 0;
	int nCardCount_Max = 0;
	long long llnCardName = 0;
	long long llnCardName_Temp = 0;

	scanf("%d", &nInputSize);
	p_llnInput = malloc(sizeof(long long)*(nInputSize));
	memset(p_llnInput, 0, sizeof(long long)*(nInputSize));

	for (int i = 0; i < nInputSize; i++)
	{
		scanf("%lld", &p_llnInput[i]);
	}

	Mgsort11652(p_llnInput, nInputSize, sizeof(long long), 0, nInputSize - 1, Compare11652);

	nCardCount = 1;
	nCardCount_Max = 1;
	llnCardName_Temp = p_llnInput[0];
	llnCardName = p_llnInput[0];

	for (int i = 1; i < nInputSize; i++)
	{
		if (llnCardName_Temp == p_llnInput[i])
		{
			nCardCount++;
		}
		else
		{
			llnCardName_Temp = p_llnInput[i];
			nCardCount = 1;
		}
		if (nCardCount_Max < nCardCount)
		{
			llnCardName = p_llnInput[i];
			nCardCount_Max = nCardCount;
		}
	}

	printf("%lld\n", llnCardName);

	free(p_llnInput);

	return 0;
}