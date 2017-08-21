#ifndef OHTBL_H
#define OHTBL_H

#include <stdlib.h>

typedef struct OHTbl_ {
	int nPositions;
	void *vacated;
	int(*hash1)(const void *key);
	int(*hash2)(const void *key);
	int(*match)(const void *key1, const void *key2);
	void(*destory)(void *data);
	int nSize;
	void **table;
}OHTbl;

int OhtblInit(OHTbl *htbl, int Positions, int(*hash1)(const void *key), int(*hash2)(const void *key), int(*match)(const void *key1, const void *key2), void(*destory)(void *data));
void OhtblDestory(OHTbl *htbl);
int OhtblInsert(OHTbl *htbl, const void *data);
int OhtblRemove(OHTbl *htbl, void **data);
int OhtblLookup(const OHTbl *htbl, void **data);
#define OhtblSize(htbl) ((htbl)->nSize)

#endif