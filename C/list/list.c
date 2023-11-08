#include "list.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef LINKED_LIST_H_INCLUDED
/**
 * 
 * 
*/
int CreateList	(List* pl)
{
    pl->head = NULL;
    pl->size = 0;
    return 1;
}

/**
 * 
 * 
*/
int ListEmpty	(List* pl)
{
    return (!pl->size);
}

/**
 * 
 * 
*/
int ListFull (List* pl)
{
    return (0);
}

/**
 * 
 * 
*/
int ListSize	(List* pl)
{
    return (pl->size);
}

/**
 *  
 * 
*/
void DestroyList	(List* pl)
{
    ListNode *q;
    while (pl->head)
    {
        q = pl->head->next;
        free(pl->head);
        pl->head = q; 
    }
    pl->size = 0;
}

/**
 * 
 * 
*/
void TraverseList(List* pl, void (*Visit)(type_entry item))
{
   ListNode *q = pl->head;

   while (q)
   {
    Visit(q->item);
    q = q->next;
   }
    
}



/**
 * 
 * 
*/
void InsertList	(int pos, type_entry item, List* pl)
{
    ListNode* pn,*q;
    int i;
    if (pn = malloc(sizeof(ListNode)))
    {
        pn->item = item;
        pn->next = NULL;

        if (pos == 0)
        {
            pn->next = pl->head;
            pl->head = pn;
        }
        else
        {
            for (q = pl->head ,i = 0; i < pos - 1; i++)
                q = q->next;
            pn->next = q->next;
            q->next = pn;
            
        }
        pl->size++;
    }
    
    
}

/**
 * 
 * 
*/
void DeleteList	(int pos, type_entry* item, List* pl)
{
    ListNode *q,*tmp;
    int i;

    if (pos == 0)
    {
        *item = pl->head->item;
        tmp = pl->head->next;
        free(pl->head);
        pl->head = tmp;
    }
    else
    {
        for(q=pl->head, i=0; i<pos-1; i++)
		q=q->next;
        *item = q->next->item;
        tmp = q->next->next;
        free(q->next);
        q->next = tmp;
    }
    pl->size--;
    
}

/**
 * 
 * 
*/
void RetrieveList(int pos, type_entry* item, List* pl)
{
    ListNode *p;
    int i;

    for (p = pl->head,  i = 0; i < pos; i++)
        p = p->next;
    *item = p->item;
}

/**
 * 
 * 
*/
void ReplaceList	(int pos, type_entry item, List* pl)
{
    ListNode *p;
    int i;

    for (p = pl->head,  i = 0; i < pos; i++)
        p = p->next;
    p->item = item;
}
#else

/**
 * 
 * 
*/
int CreateList	(List* pl)
{
    pl->size = 0;
    return 0;
}

/**
 * 
 * 
*/
int ListEmpty	(List* pl)
{
    return (!pl->size);
}

/**
 * 
 * 
*/
int ListFull (List* pl)
{
    return (pl->size == MAX_SIZE);
}

/**
 * 
 * 
*/
int ListSize	(List* pl)
{
    return (pl->size);
}

/**
 * 
 * 
*/
void DestroyList	(List* pl)
{
    pl->size = 0;
}

/**
 * 
 * 
*/
void InsertList	(int pos, type_entry item, List* pl)
{
    for (int i = pl->size - 1; i >= pos; i--)
    {
        pl->entry[i + 1] = pl->entry[i]; 
    }
    pl->entry[pos] = item;
    pl->size++;
    
}

/**
 * 
 * 
*/
void DeleteList	(int pos, type_entry* item, List* pl)
{
    *item = pl->entry[pos];
    for (int i = pos + 1; i <= pl->size-1; i++)
        pl->entry[i - 1] = pl->entry[i];
    pl->size--;
}

/**
 * 
 * 
*/
void TraverseList(List* pl, void (*Visit)(type_entry item))
{
    for (int i = 0; i < pl->size; i++)
    {
        Visit(pl->entry[i]);
    }
    
}

/**
 * 
 * 
*/
void RetrieveList(int pos, type_entry* item, List* pl)
{
    *item = pl->entry[pos];
}

/**
 * 
 * 
*/
void ReplaceList	(int pos, type_entry item, List* pl)
{
    pl->entry[pos] = item;
}
#endif