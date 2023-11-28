#include "global.h"
#ifndef CIRCULAR_LINKED_LIST_H_INCLUDED
#define CIRCULAR_LINKED_LIST_H_INCLUDED

typedef struct listnode
{
	type_entry item;
	struct listnode* next;
} ListNode;

typedef struct list
{
	ListNode* head;
	int size;
} List;

int 	CreateList	(List *);
int 	ListEmpty	(List *);
int 	ListFull	(List *);
int 	ListSize	(List *);
void	DestroyList	(List *);
int		InsertList	(int, type_entry, List *);
int 	DeleteList	(int, type_entry *, List *);
void 	TraverseList(List *, void (*Visit)(type_entry));
void 	RetrieveList(int , type_entry *, List *);
void 	ReplaceList	(int, type_entry, List *);
#endif // CIRCULAR_LINKED_LIST_H_INCLUDED
