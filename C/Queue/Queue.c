#include "Queue.h"
#include <stdio.h>

#ifdef LINKED_QUEUE_H

int CreateQueue(Queue *pq)
{
    pq->first = NULL;
    pq->rear = NULL;
    pq->size = 0;
    return 1;
}

int Push(QUEUE_ENTRY e, Queue *pq)
{
    QueueNode *pn = malloc(sizeof(QueueNode));
    if (!pn)
        return (0);
    
    pn->entry = e;
    pn->next = NULL;

    if (!pq->rear)
        pq->first = pn;
    else
        pq->rear->next = pn;
    pq->rear = pn;
    pq->size++;
    return (1);
}

int QueueFull(Queue *pq)
{
    return (0);
}

int QueueEmpty(Queue *pq)
{
    return (!pq->size);
}

void Pop(QUEUE_ENTRY *pe, Queue *pq)
{
    QueueNode *pn = pq->first;
    *pe = pq->first->entry;
    pq->first = pq->first->next;
    free(pn);
    if (!pq->first)
		pq->rear=NULL;
    pn = NULL;
    pq->size--;
}

void QueueTop(QUEUE_ENTRY *pe, Queue *pq)
{
    *pe = pq->first->entry;
}


int QueueSize(Queue *pq)
{
    return (pq->size);
}

void ClearQueue(Queue *pq)
{
    
    while (pq->first)
    {
        pq->rear = pq->first->next;
        free(pq->first);
        pq->first = pq->rear;
    }
    pq->size = 0;
}
void TraverseQueue(Queue *pq, void (*pf)(QUEUE_ENTRY))
{
        for (QueueNode *p = pq->first; p; p = p->next)
        {
            pf(p->entry);
        }
        
}
#else
/**
 * CreateQueue - function that intialize queue
 *
 * @pq: pointer to queue
 *
 * pre: there is an object of Queue exists
 **/
int CreateQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
    return 0;
}

/**
 * push - function to push element in queue
 *
 * @e: copy of element to be pushed
 *
 * @pq: ponter to queue
 *
 **/
int Push(QUEUE_ENTRY e, Queue *pq)
{
    /*pre: queue exists and must be intialized and not full*/
    pq->rear = (pq->rear + 1) % MAX_QUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
    /*post: elemt pushed and rear increased */
    return (1);
}

/**
 * QueueFull - function check if queue is full or not
 *
 * @pq: pointer to queue
 *
 * Return: 1 if queue is full
 **/
int QueueFull(Queue *pq)
{
    /*pre :queue exist and must be initialized */
    return ((pq->size == MAX_QUEUE));
}

/**
 * pop - function  that pop first element of queue and return it in pe
 *
 * @pe: pointer to element
 *
 *
 * @pq: pointer to queue
 *
 *
 **/
void Pop(QUEUE_ENTRY *pe, Queue *pq)
{
    /*pre: queue exists and intialized and not empty!*/
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAX_QUEUE;
    pq->size--;
    /*post: element poped in pe and size decreased*/
}

/**
 * QueueEmpty - chaeck if queue empty or not
 *
 * @pq: pointer to queue
 *
 * Return: 1 if queue is empty
 **/
int QueueEmpty(Queue *pq)
{
    /*pre: queue exists and intialized*/
    return (!pq->size);
}

/**
 * QueueTop - return first element in queue without poping it
 *
 * @pe: pointer to elemnet returned value
 *
 * @pq: pointer to queue
 *
 *
 **/
void QueueTop(QUEUE_ENTRY *pe, Queue *pq)
{
    /*pre: queue exists intialized and not empty*/
    *pe = pq->entry[pq->front];
    /*post element returned without being poped*/
}

/**
 * QueueSize - return queue size
 *
 * @pq: pointer to queue
 *
 *
 *
 **/
int QueueSize(Queue *pq)
{
    return (pq->size);
}

/**
 * ClearQueue - function clear queue & reintialized it
 *
 * @pq: pointer to queue
 *
 *
 **/
void ClearQueue(Queue *pq)
{
    /*pre: queue exists*/
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
    /*post: queue re intialized*/
}

/**
 * TraverseQueue - function help user access every element in queue without poping
 *
 * @pq: pointer to queue
 *
 * @pf: pointer to function written by user
 **/
void TraverseQueue(Queue *pq, void (*pf)(QUEUE_ENTRY))
{
    /*pre: queue exists initialized and pf is a valid function*/
    for (int i = 0, pos = pq->front; i < pq->size; i++)
    {
        pf(pq->entry[pos]);
        pos = (pos + 1) % MAX_QUEUE;
    }
}
#endif
