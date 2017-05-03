#include <stdlib.h>
#include <string.h>

#include "list.h"

void ListInit(List *list, void(*destory)(void *data))
{
	list->nSize = 0;
	list->destory = destory;
	list->Head = NULL;
	list->Tail = NULL;

	return;
}
void ListDestory(List *list)
{
	void *data;

	while (0 < ListSize(list))
	{
		if (ListRemove_Next(list, NULL, (void**)&data) == 0 && list->destory != NULL)
		{
			list->destory(data);
		}
	}

	memset(list, 0, sizeof(List));
}

int ListInsert_Next(List *list, ListElmt *element, const void *data)
{
	ListElmt *element_new;

	if ((element_new = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
	{
		return -1;
	}
	element_new->data = (void*)data;
	if (element == NULL)
	{
		if (ListSize(list) == 0)
		{
			list->Tail = element_new;
		}
		element_new->Next = list->Head;
		list->Head = element_new;
	}
	else
	{
		if (element->Next == NULL)
		{
			list->Tail = element_new;
		}
		element_new->Next = element->Next;
		element->Next = element_new;
	}
	list->nSize++;
	return 0;
}

int ListRemove_Next(List *list, ListElmt *element, void **data)
{
	ListElmt *element_old;

	if (ListSize(list) == 0)
	{
		return -1;
	}

	if (element == NULL)
	{
		*data = list->Head->data;
		element_old = list->Head;
		list->Head = list->Head->Next;

		if(list->nSize == 1)
		{
			list->Tail = NULL;
		}
	}
	else
	{
		if (element->Next == NULL)
		{
			return -1;
		}
		*data = element->Next->data;
		element_old = element->Next;
		element->Next = element->Next->Next;
		
		if (element->Next == NULL)
		{
			list->Tail = element;
		}
	}

	free(element_old);
	list->nSize--;

	return 0;
}