#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>
#include "../05_Linked_List/list.h"

typedef struct CHTbl_ {
	int nBuckets;
	int(*hash)(const void *key);
	int(*match)(const void *key1, const void *key2);
	void(*destory)(void *data);
	int nSize;
	List *table;
} CHTbl;

int ChtblInit(CHTbl *htbl, int nBuckets, int(*hash)(const void *key), int(*match)(const void *key1, const void *key2), void(*destory)(void *data));
void ChtblDestory(CHTbl *htbl);
int ChtblInsert(CHTbl *htbl, const void *data);
int ChtblRemove(CHTbl *htbl, void **data);
int ChtblLookup(const CHTbl *htbl, void **data);
#define ChtblSize(htbl) ((htbl)->nSize)
#endif