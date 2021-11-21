#include <stdlib.h>
#include "linb.h"

void CreateQueue(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

int append(QueueEntry e, Queue *pq)
{
    QueueNode *pn = (QueueNode *) malloc( sizeof(QueueNode));

    if(!pn)
        return 0;

    else {
        pn->entry = e;
        pn->next = NULL;

        if(!pq->front)
            pq->front = pn;
        else
            pq->rear->next = pn;

        pq->rear = pn;
        pq->size++;
        return 1;
    }
}

void serve(QueueEntry *pe, Queue *pq)
{
    QueueNode *pn = pq->front;

    *pe = pn->entry;
    pq->front = pn->next;
    free(pn);

    if(!pq->front)
        pq->rear = NULL;

    pq->size--;
}

int EmptyQueue(Queue *pq)
{
    return !pq->front;
}

int FullQueue(Queue *pq)
{
    return 0;
}

void ClearQueue(Queue *pq)
{
    while(pq->front) {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->size = 0;
}

void QueueFront(QueueEntry *pe, Queue *pq)
{
    *pe = pq->front->entry;
}

int QueueSize(Queue *pq)
{
    return pq->size;
}

void TraverseQueue(Queue *pq, void (*pf) (QueueEntry))
{
    for(QueueNode *pn = pq->front; pn; pn = pn->next)
        (*pf) (pn->entry);
}
