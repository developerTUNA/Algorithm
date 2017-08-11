#ifndef SORT_H
#define SORT_H

int Sort_Insert(void *data, int nNum, int nSizeBlock, int(*compare)(const void *key1, const void *key2));

int Sort_Quick(void *data, int nNum, int nSizeBlock, int nStart, int nEnd, int(*compare)(const void *key1, const void *key2));

int Sort_Merge(void *data, int nNum, int nSizeBlock, int nStart, int nEnd, int(*compare)(const void *key1, const void *key2));

int Sort_Count(int *data, int nNum, int nMax);

int Sort_Radix(int *data, int nNum, int nDigit, int nBase);

#endif
