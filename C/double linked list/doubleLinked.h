#include "global.h"
#ifndef DOUBLELINKED_H_INCLUDED
#define DOUBLELINKED_H_INCLUDED


typedef struct node
{
    type_entry item;
    struct node *next;
    struct node *prev;
}Node;


typedef struct doubleLinked
{
    int size;
    Node* head;
}DoubleLinkedList;

int 	CreateList	(DoubleLinkedList *);
int 	ListEmpty	(DoubleLinkedList *);
int 	ListFull	(DoubleLinkedList *);
int 	ListSize	(DoubleLinkedList *);
void	DestroyList	(DoubleLinkedList *);
int 	InsertList	(int, type_entry, DoubleLinkedList *);
int 	DeleteList	(int, type_entry *, DoubleLinkedList *);
void 	TraverseList(DoubleLinkedList *, void (*Visit)(type_entry));
void 	RetrieveList(int , type_entry *, DoubleLinkedList *);
void 	ReplaceList	(int, type_entry, DoubleLinkedList *);
#endif // DOUBLELINKED_H_INCLUDED
