#ifndef SET_H
#define SET_H

#include "../05_Linked_List/list.h"

typedef List Set;

void SetInit(Set *set, int(*match)(const void *key1, const void *key2), void(*destory)(void*data));
#define SetDestory ListDestory
int SetInsert(Set *set, const void *data);
int SetRemove(Set *set, void **data);
int SetUnion(Set *setu, const Set *set1, const Set *set2);
int SetIntersection(Set *seti, const Set *set1, const Set *set2);
int SetDifference(Set *setd, const Set *set1, const Set *set2);
int SetisMember(const Set *set, const void *data);
int SetisSubset(const Set *set1, const Set *set2);
int SetisEqual(const Set *set1, const Set *set2);
#define SetSize(set)((set)->nSize)

#endif