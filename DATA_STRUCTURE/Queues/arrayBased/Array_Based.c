#include "arrb.h"

void CreateQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void append(QueueEntry e, Queue *pq)
{
    /*
    if(pq->rear == MAXQUEUE)
        pq->rear = 0;
    else
        pq->rear++;
    */
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}

void serve(QueueEntry *pe, Queue *pq)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}

int EmptyQueue(Queue *pq)
{
    return pq->size == 0;
}

int FullQueue(Queue *pq)
{
    return pq->size == MAXQUEUE;
}

void ClearQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void QueueFront(QueueEntry *pe, Queue *pq)
{
    *pe = pq->entry[pq->front];
}

int QueueSize(Queue *pq)
{
    return pq->size;
}

void TraverseQueue(Queue *pq, void (*pf) (QueueEntry))
{
    int pos, i;

    for(pos = pq->front, i = 0; i < pq->size; i++) {
        (*pf) (pq->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}
