#include "global.h"
#include "circular linked list.h"
#include <stdlib.h>

ListNode *makenode(type_entry e)
{
    ListNode *pn = malloc(sizeof(ListNode));
    pn->item = e;
    pn->next = NULL;
    return (pn);
}

/**
 *
 */
int CreateList(List *pl)
{
    pl->head = NULL;
    pl->size = 0;
    return (1);
}

/**
 *
 *
 */
int ListEmpty(List *pl)
{
    return (pl->size == 0);
}

/**
 *
 *
 */
int ListFull(List *pl)
{
    return (1);
}

/**
 *
 *
 */
int ListSize(List *pl)
{
    return (pl->size);
}

/**
 *
 *
 */
int InsertList(int pos, type_entry e, List *pl)
{
    ListNode *pn = makenode(e), *q;
    int i;
    if (pn)
    {

        if (pos == 0)
        {
            pn->next = pl->head;
            pl->head = pn;
        }
        else
        {
            for (q = pl->head, i = 0; i < pos - 1; i++)
                q = q->next;
            pn->next = q->next;
            q->next = pn;
            if (pn->next == NULL)
                pn->next = pl->head;
        }
        pl->size++;
        return (1);
    }
    return (0);
}

/**
 *
 *
 */
int DeleteList(int pos, type_entry *pe, List *pl)
{
    if (pl->size == 0 || pos >= pl->size)
        return (0);
    ListNode *q, *tmp;
    int i;

    if (pos == 0)
    {
        *pe = pl->head->item;
        tmp = pl->head->next;
        free(pl->head);
        pl->head = tmp;
        for (q = pl->head, i = 0; i < pl->size - 2; i++)
            q = q->next;
        q->next = pl->head;
    }
    else
    {
        for (q = pl->head, i = 0; i < pos - 1; i++)
            q = q->next;
        *pe = q->next->item;
        tmp = q->next->next;
        free(q->next);
        q->next = tmp;
    }
    pl->size--;
    return (1);
}

/**
 *
 *
 */
void TraverseList(List *pl, void (*Visit)(type_entry e))
{
    ListNode *q;
    int i;
    for (q = pl->head, i = 0; i < pl->size; i++, q = q->next)
        Visit(q->item);
}

/**
 * 
 * 
*/
void 	RetrieveList(int pos , type_entry *pe, List *pl)
{
    ListNode *q;
    int i;
    if (pos == 0)
    {
        *pe = pl->head->item;
    }
    else
    {
        for (q = pl->head, i = 0; i < pos ; i++)
            q = q->next;
        *pe = q->item;
    
    }
}

/**
 * 
 * 
*/
void 	ReplaceList	(int pos, type_entry e, List *pl)
{
     ListNode *q;
    int i;
    if (pos == 0)
    {
        pl->head->item = e;
    }
    else
    {
        for (q = pl->head, i = 0; i < pos ; i++)
            q = q->next;
        q->item = e;
    
    }
}