#include "global.h"
#include "doubleLinked.h"
#include <stdio.h>
#include <stdlib.h>

Node* makeNode(type_entry e)
{
    Node *pn = malloc(sizeof(Node));
        pn->next = NULL;
        pn->prev = NULL;
        pn->item = e;
        return (pn);
}
int CreateList(DoubleLinkedList *pl)
{
    pl->head = NULL;
    pl->size = 0;
    return 1;
}

int ListEmpty(DoubleLinkedList *pl)
{
    return (pl->size == 0);
}

int ListFull(DoubleLinkedList *pl)
{
    return (0);
}

int ListSize(DoubleLinkedList *pl)
{
    return (pl->size);
}

int InsertList(int pos, type_entry e, DoubleLinkedList *pl)
{
    Node *pn, *q;
    pn = makeNode(e);
    int i;
    if (pn)
    {
        if (pos == 0)
        {
            pn->next = pl->head;
            if(pl->head != NULL)
                pl->head->prev = pn;
            pl->head = pn;
        }
        else
        {
            for (q = pl->head, i = 0; i < pos - 1; i++)
                    q = q->next;
            pn->next = q->next;
            q->next = pn;
            pn->prev = q;
            if(pn->next != NULL)
                pn->next->prev = pn;

        }
        pl->size++;
        return (1);
    }
    return (0);
}

int DeleteList(int pos, type_entry *pe, DoubleLinkedList *pl)
{
    Node *q;
    int i;
    if (pos >= pl->size || ListEmpty(pl))
    {
        return (0);
    }

    if (pos == 0)
    {
        q = pl->head;
        *pe = q->item;
        pl->head = q->next;
        pl->head->prev = q->prev;
    }
    else
    {
        for (q = pl->head, i = 0; i < pos; i++)
            q = q->next;
        *pe = q->item;
        q->prev->next = q->next;
        if (pos != pl->size - 1)
            q->next->prev = q->prev;
    }
    free(q);
    pl->size--;
    return (1);
}
void 	RetrieveList(int pos, type_entry *pe, DoubleLinkedList *pl)
{
     Node *q;
        int i;
     if (pos == 0)
    {
        *pe = pl->head->item;
    }
    else
    {
        for (q = pl->head, i = 0; i < pos; i++)
            q = q->next;
        *pe = q->item;
    }
}
void 	ReplaceList	(int pos, type_entry e, DoubleLinkedList *pl)
{
     Node *q;
        int i;
     if (pos == 0)
    {
        pl->head->item = e;
    }
    else
    {
        for (q = pl->head, i = 0; i < pos; i++)
            q = q->next;
       q->item = e;
    }
}

void 	TraverseList(DoubleLinkedList *pl, void (*Visit)(type_entry e))
{
    Node *q = pl->head;
    while (q)
    {
        Visit(q->item);
        q = q->next;
    }
}
