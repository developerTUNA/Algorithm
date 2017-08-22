#include <stdlib.h>
#include <string.h>
#include "dlist.h"

void DListInit(DList *list, void(*destory)(void *data))
{
	list->nSize = 0;
	list->destory = destory;
	list->Head = NULL;
	list->Tail = NULL;
	
	return;
}

void DListDestory(DList *list)
{
	void *data;
	while (0 < DListSize(list))
	{
		if (DListRemove(list, DListTail(list), (void**)&data) == 0 &&
			list->destory != NULL)
		{
			list->destory(data);
		}
	}
	memset(list, 0, sizeof(DList));

	return;
}

int DListInsert_Next(DList *list, DListElmt *element, const void *data)
{
	DListElmt *element_new;
	if (element == NULL &&
		DListSize(list) != 0)
	{
		return -1;
	}
	if ((element_new = (DListElmt*)malloc(sizeof(DListElmt))) == NULL)
	{
		return -1;
	}
	element_new->data = (void*)data;

	if (DListSize(list) == 0)
	{
		list->Head = element_new;
		list->Head->prev = NULL;
		list->Head->next = NULL;
		list->Tail = element_new;
	}
	else
	{
		element_new->next = element->next;
		element_new->prev = element;
		if (element->next == NULL)
		{
			list->Tail = element_new;
		}
		else
		{
			element->next->prev = element;
		}
		element->next = element_new;
	}

	list->nSize++;

	return 0;
}

int DListInsert_Prev(DList *list, DListElmt *element, const void *data)
{
	DListElmt *element_new;
	if (element == NULL &&
		DListSize(list) != 0)
	{
		return -1;
	}
	if ((element_new = (DListElmt*)malloc(sizeof(DListElmt))) == NULL)
	{
		return -1;
	}
	element_new->data = (void*)data;

	if (DListSize(list) == 0)
	{
		list->Head = element_new;
		list->Head->prev = NULL;
		list->Head->next = NULL;
		list->Tail = element_new;
	}
	else
	{
		element_new->next = element;
		element_new->prev = element->prev;
		if (element->prev == NULL)
		{
			list->Head = element_new;
		}
		else
		{
			element->prev->next = element;
		}
		element->prev = element_new;
	}

	list->nSize++;

	return 0;
}

int DListRemove(DList *list, DListElmt *element, void **data)
{
	if (element == NULL || DListSize(list) == 0)
	{
		return -1;
	}
	*data = element->data;
	if (element == list->Head)
	{
		list->Head = element->next;
		if (list->Head == NULL)
		{
			list->Tail = NULL;
		}
		else
		{
			element->next->prev = NULL;
		}
	}
	else
	{
		element->prev->next = element->next;
		if (element->next == NULL)
		{
			list->Tail = element->prev;
		}
		else
		{
			element->next->prev = element->prev;
		}
	}

	free(element);
	list->nSize--;

	return 0;
}
