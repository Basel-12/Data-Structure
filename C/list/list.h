#include "global.h"
#define LINKED_LIST_H_INCLUDED
#ifdef LINKED_LIST_H_INCLUDED

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


#else
typedef struct list{
	type_entry entry[MAX_SIZE];
	int size;
}List;
#endif // LINKED_LIST_H_INCLUDED
int 	CreateList	(List *);
int 	ListEmpty	(List *);
int 	ListFull	(List *);
int 	ListSize	(List *);
void	DestroyList	(List *);
void 	InsertList	(int, type_entry, List *);
void 	DeleteList	(int, type_entry *, List *);
void 	TraverseList(List *, void (*Visit)(type_entry));
void 	RetrieveList(int , type_entry *, List *);
void 	ReplaceList	(int, type_entry, List *);




