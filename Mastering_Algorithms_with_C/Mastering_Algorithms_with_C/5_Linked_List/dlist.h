#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

typedef struct DListElmt_
{
	void *data;
	struct DListElmt_ *prev;
	struct DListElmt_ *next;
} DListElmt;

typedef struct DList_
{
	int nSize;
	int(*match)(const void *key1, const void *key2);
	void(*destory)(void *data);

	DListElmt *Head;
	DListElmt *Tail;
} DList;

void DListInit(DList *list, void(*destory)(void*data));
void DListDestory(DList *list);
int DListInsert_Next(DList *list, DListElmt *element, const void *data);
int DListInsert_Prev(DList *list, DListElmt *element, const void *data);
int DListRemove(DList *list, DListElmt *element, void **data);
#define DListSize(list)((list)->nSize)
#define DListHead(list)((list)->Head)
#define DListTail(list)((list)->Tail)
#define DListisHead(element)((element)->perv == NULL?1:0)
#define DListisTail(element)((element)->next == NULL?1:0)
#endif DLIST_H
