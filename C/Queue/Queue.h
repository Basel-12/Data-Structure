#ifndef QUEUE_ENTRY
#define QUEUE_ENTRY char
#endif // QUEUE_ENTRY

#ifndef MAX_QUEUE
#define MAX_QUEUE 100
#endif // MAX_QUEUE

#define LINKED_QUEUE_H
#ifdef  LINKED_QUEUE_H

/**
 * QueueNode - node of queue
 *
 * @next: pointer to next element;
 *
 * @entry: array where we store elements pushed
 **/
typedef struct queuenode
{
    QUEUE_ENTRY entry;
    struct queuenode* next;
} QueueNode;


/**
 * Queue - struct queue
 *
 * @front: element to be poped (first element pushed)
 *
 * @rear: position of last element pushed
 *
 * @size: size of the queue;
 *
 **/

typedef struct queue
{
    QueueNode *first;
    QueueNode *rear;
    int size;
} Queue;

#else
#define ARRAYED_QUEUE
/**
 * Queue - struct queue
 *
 * @front: element to be poped (first element pushed)
 *
 * @rear: position of last element pushed
 *
 * @size: size of the queue;
 *
 * @entry: array where we store elements pushed
 **/

typedef struct queue
{
    int front;
    int rear;
    int size;
    QUEUE_ENTRY entry[MAX_QUEUE];
} Queue;
#endif // QUEUE_H

int Push(QUEUE_ENTRY, Queue *);
void Pop(QUEUE_ENTRY *, Queue *);
int QueueEmpty(Queue *);
int QueueFull(Queue *);
int CreateQueue(Queue *);
void QueueTop(QUEUE_ENTRY *, Queue *);
int QueueSize(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue *, void (*)(QUEUE_ENTRY));
