#include "global.h"
#include <stdlib.h>
#include "priorityQueue.h"


int PriorityQueueEmpty(PriorityQueue *ppq){
    return (ppq->size == 0);
}

int PriorityQueueFull(PriorityQueue *ppq){
    return (1);
}

int CreatePriorityQueue(PriorityQueue *ppq){
    ppq->top = NULL;
    ppq->size = 0;
}

int PriorityQueueSize(PriorityQueue *ppq){
    return (ppq->size);
}

int Push(PriorityQueueype e, PriorityQueue *pq){
        QueueNode *pn = malloc(sizeof(QueueNode)),*q,*prev;
        int i;
        pn->item = e;
        pn->next = NULL;

        if (pn)
        {
            if(!pq->size || pq->top->item.priority > pn->item.priority){
                pn->next = pq->top;
                pq->top = pn;
            }
            else{
                for (q = pq->top ,i = 0; i < pq->size; i++)
                {
                    if(pn->item.priority < q->item.priority)
                        break;
                    prev = q;
                    q = q->next;
                }
                pn->next = prev->next;
                prev->next = pn;
            }
            pq->size++;
            return (1);
        }
        return (0);
}


int Pop(PriorityQueueype*pe, PriorityQueue *pq){
    if (!pq || !pq->size)
        return (0);
    QueueNode *q = pq->top;
    *pe = q->item;
    pq->top = pq->top->next;
    free(q);
    pq->size--;
    return (1);
}

void TraversePriorityQueue(PriorityQueue *pq, void (*pf)(PriorityQueueype e)){
        QueueNode *p = pq->top;
        while (p)
        {
            pf(p->item);
            p = p->next;
        }
}

void PriorityQueueTop(PriorityQueueype*pe, PriorityQueue *pq){
    *pe = pq->top->item;
}

void ClearPriorityQueue(PriorityQueue *pq){
        QueueNode *q = pq->top;
        while (q)
        {
            pq->top = pq->top->next;
            free(q);
            q = pq->top;
        }
        pq->size = 0;
        pq->top  = NULL;
}