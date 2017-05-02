#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

//연결 리스트 항목들의 구조체 정의
typedef struct ListElmt_ {
	void *data;
	struct ListElmt_ *next;
} ListElmt;

//연결 리스트 구조체 정의
typedef struct List_ {
	int nSize;
	int(*match)(const void *key1, const void *key2);
	void(*destory)(void *data);

	ListElmt *Head;
	ListElmt *Tail;
} List;

//인터페이스
void ListInit(List *list, void(*destory)(void *data));
void ListDestory(List *list);
int ListInsert_Next(List *list, ListElmt *element, const void *data);
int ListRemove_Next(List *list, ListElmt *element, void **data);

#define ListSize(list)((list)->nSize)
#define ListHead(list)((list)->Head)
#define ListTail(list)((list)->Tail)
#define ListisHead(list, element)((element)==(list)->Head?1:0)
#define ListisTail(list, element)((element)->next == NULL?1:0)
#define ListData(element)((element)->data)
#define ListNext(element)((element)->next)

#endif LIST_H