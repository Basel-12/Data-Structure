#include "global.h"
#include "Sorted linked list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* makenode(type_entry e)
{
    ListNode *p = malloc(sizeof(ListNode));
    p->item=e;
    p->next=NULL;
    return (p);
}

int CreateSortedList(SortedList *pl)
{
        pl->head = NULL;
        pl->size = 0;
        return (1);
}

int 	SortedListEmpty	(SortedList *pl)
{
    return (!pl->size);
}

int 	SortedListFull	(SortedList *pl)
{
    return (1);
}

int 	SortedListSize	(SortedList *pl)
{
    return (pl->size);
}

int 	InsertSortedList ( type_entry e, SortedList *pl)
{
    ListNode *pn,*q;
    int i = 0;
    pn = makenode(e);
    if (pn)
    {
        if (!pl->head)
            pl->head = pn;
        else
        {
            for (q = pl->head; i < pl->size - 1; i++)
            {
                if(pn->item < q->item)
                    break;
                q=q->next;
            }
            if(i == 0 )
            {
                if (pl->head->item < pn->item)
                {
                    pn->next = pl->head->next;
                    pl->head = pn;
                }
                else{
                    pn->next = pl->head;
                }
            }
            else{
            pn->next = q;
            q = pn;
            }
        }
        pl->size++;
        return (1);
    }
    return (0);
}

int 	DeleteSortedList	(int pos, type_entry *pe, SortedList *pl)
{
    if(pl->size == 0 || pl->head == NULL)
        return (0);

    ListNode *q,*tmp;
    int i;

    if (pos == 0)
    {
        *pe= pl->head->item;
        tmp = pl->head->next;
        free(pl->head);
        pl->head = tmp;
    }
    else
    {
        for(q=pl->head, i=0; i<pos-1; i++)
		q=q->next;
        *pe= q->next->item;
        tmp = q->next->next;
        free(q->next);
        q->next = tmp;
    }
    pl->size--;
    return (1);
}

void 	TraverseSortedList(SortedList *pl, void (*Visit)(type_entry e))
{
    ListNode *q =pl->head;
    while (q)
    {
        Visit(q->item);
        q = q->next;
    }
}
