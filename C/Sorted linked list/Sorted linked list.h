#include "global.h"
#ifndef SORTED_LINKED_LIST_H_INCLUDED
#define SORTED_LINKED_LIST_H_INCLUDED

typedef struct listnode
{
	type_entry item;
	struct listnode* next;
} ListNode;

typedef struct list
{
	ListNode* head;
	int size;
} SortedList;


int 	CreateSortedList	(SortedList *);
int 	SortedListEmpty	(SortedList *);
int 	SortedListFull	(SortedList *);
int 	SortedListSize	(SortedList *);
void	DestroySortedList	(SortedList *);
int 	InsertSortedList	(type_entry, SortedList *);
int 	DeleteSortedList	(int, type_entry *, SortedList *);
void 	TraverseSortedList(SortedList *, void (*Visit)(type_entry));
void 	RetrieveSortedList(int , type_entry *, SortedList *);
void 	ReplaceSortedList	(int, type_entry, SortedList *);

#endif // SORTED_LINKED_LIST_H_INCLUDED
