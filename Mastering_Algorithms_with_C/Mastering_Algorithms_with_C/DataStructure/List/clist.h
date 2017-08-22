#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

typedef struct CListElmt_
{
	void *data;
	struct CListElmt_ *next;
}CListElmt;

typedef struct Clist_
{
	int nSize;
	int(*match)(const void *key1, const void *key2);
	void(*destory)(void *data);

	CListElmt *head;
} CList;

void CListInit(CList *list, void(*destory)(void *data));
void CListDestory(CList *list);
int CListInsert_Next(CList *list, CListElmt *elemant, const void *data);
int CListRemove_Next(CList *list, CListElmt *element, void **data);

#define CListSize(list)((list)->nSize)
#define CListHead(list)((list)->head)
#define CListData(element)((element)->data)
#define CListNext(element)((element)->next)

#endif