#include <stdlib.h>
#include <string.h>

#include "clist.h"

void CListInit(CList *list, void(*destory)(void *data))
{
	list->nSize = 0;
	list->destory = destory;
	list->head = NULL;

	return;
}

void CListDestory(CList *list)
{
	void *data;
	while (0 < CListSize(list))
	{
		if (CListRemove_Next(list, list->head, (void**)&data) == 0 && list->destory != NULL)
		{
			list->destory(data);
		}
	}

	memset(list, 0, sizeof(CList));
	return;
}

int CListInsert_Next(CList *list, CListElmt *element, const void *data)
{
	CListElmt *element_new;

	if ((element_new = (CListElmt *)malloc(sizeof(CListElmt))) == NULL)
	{
		return -1;
	}

	element_new->data = (void*)data;
	if (CListSize(list) == 0)
	{
		element_new->next = element_new;
		list->head = element_new;
	}
	else
	{
		element_new->next = element->next;
		element->next = element_new;
	}

	list->nSize++;
	
	return 0;
}

int CListRemove_Next(CList *list, CListElmt *element, void **data)
{
	CListElmt *element_old;

	if (CListSize(list) == 0)
	{
		return -1;
	}

	*data = element->next->data;
	
	if (element->next == element)
	{
		element_old = element->next;
		list->head = NULL;
	}
	else
	{
		element_old = element->next;
		element->next = element->next->next;
	}

	free(element_old);
	list->nSize--;
	return 0;
}