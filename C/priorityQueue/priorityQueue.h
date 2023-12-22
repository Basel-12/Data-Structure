#include "global.h"
#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

/**
 * QueueNode - node of queue
 *
 * @next: pointer to next element;
 *
 * @item: array where we store elements pushed
 **/
typedef struct queuenode
{
    PriorityQueueype item;
    struct queuenode* next;
} QueueNode;


/**
 * Queue - struct queue
 *
 * @ftop: element to be poped (first element pushed)
 * 
 * @size: size of the queue;
 *
 **/

typedef struct queue
{
    QueueNode *top;
    int size;
} PriorityQueue;


int Push(PriorityQueueype, PriorityQueue *);
int Pop(PriorityQueueype*, PriorityQueue *);
int PriorityQueueEmpty(PriorityQueue *);
int PriorityQueueFull(PriorityQueue *);
int CreatePriorityQueue(PriorityQueue *);
void PriorityQueueTop(PriorityQueueype*, PriorityQueue *);
int PriorityQueueSize(PriorityQueue *);
void ClearPriorityQueue(PriorityQueue *);
void TraversePriorityQueue(PriorityQueue *, void (*)(PriorityQueueype));
#endif // PRIORITYQUEUE_H_INCLUDED
