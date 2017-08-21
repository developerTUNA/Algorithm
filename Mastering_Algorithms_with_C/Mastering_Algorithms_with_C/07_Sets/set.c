#include <stdlib.h>
#include <string.h>

#include "set.h"

void SetInit(Set *set, int(*match)(const void *key1, const void *key2), void(*destory)(void *data))
{
	ListInit(set, destory);
	set->match = match;

	return;
}

int SetInsert(Set *set, const void *data)
{
	if (SetisMember(set, data))
	{
		return 1;
	}
	return ListInsert_Next(set, ListTail(set), data);
}

int SetRemove(Set *set, void **data)
{
	ListElmt *member, *prev;
	
	prev = NULL;
	for (member = ListHead(set); member != NULL; member = ListNext(member))
	{
		if (set->match(*data, ListData(member)))
		{
			break;
		}
		prev = member;
	}
	if (member == NULL)
	{
		return -1;
	}
	return ListRemove_Next(set, prev, data);
}

int SetUnion(Set *setu, const Set *set1, const Set *set2)
{
	ListElmt *member = NULL;
	void *data = NULL;

	SetInit(setu, set1->match, NULL);

	for (member = ListHead(set1); member != NULL; member = ListNext(member))
	{
		data = ListData(member);
		if (ListInsert_Next(setu, ListTail(setu), data) != 0)
		{
			SetDestory(setu);
			return -1;
		}
	}

	for (member = ListHead(set2); member != NULL; member = ListNext(member))
	{
		if (SetisMember(setu, ListData(member)))
		{
			continue;
		}
		else
		{
			data = ListData(member);
			if (ListInsert_Next(setu, ListTail(setu), data) != 0)
			{
				SetDestory(setu);
				return -1;
			}
		}
	}
	return 0;
}

int SetIntersection(Set *seti, const Set *set1, const Set *set2)
{
	ListElmt *member = NULL;
	void *data = NULL;

	SetInit(seti, set1->match, NULL);
	
	for (member = ListHead(set1); member != NULL; member = ListNext(member))
	{
		if (SetisMember(set2, ListData(member)))
		{
			data = ListData(member);
			if (ListInsert_Next(seti, ListTail(seti), data) != 0)
			{
				SetDestory(seti);
				return -1;
			}
		}
	}
	return 0;
}

int SetDifference(Set *setd, const Set *set1, const Set *set2)
{
	ListElmt *member = NULL;
	void *data = NULL;

	SetInit(setd, set1->match, NULL);

	for (member = ListHead(set1); member != NULL; member = ListNext(member))
	{
		if (!SetisMember(set2, ListData(member)))
		{
			data = ListData(member);
			if (ListInsert_Next(setd, ListTail(setd), data) != 0)
			{
				SetDestory(setd);
				return -1;
			}
		}
	}
	return 0;
}

int SetisMember(const Set *set, const void *data)
{
	ListElmt *member = NULL;
	for (member = ListHead(set); member != NULL; member = ListNext(member))
	{
		if (set->match(data, ListData(member)))
		{
			return 1;
		}
	}
	return 0;
}

int SetisSubset(const Set *set1, const Set *set2)
{
	ListElmt *member = NULL;
	
	if (SetSize(set1) > SetSize(set2))
	{
		return 0;
	}

	for (member = ListHead(set1); member != NULL; member = ListNext(member))
	{
		if (!SetisMember(set2, ListData(member)))
		{
			return 0;
		}
	}
	return 1;
}

int SetisEqual(const Set *set1, const Set *set2)
{
	if (SetSize(set1) != SetSize(set2))
	{
		return 0;
	}

	return SetisSubset(set1, set2);
}