#ifndef LINB_H_INCLUDED
#define LINB_H_INCLUDED

#define MAXQUEUE 10
#define QueueEntry int
// #define QueueEntry char
// #define QueueEntry float
// #define QueueEntry double

typedef struct queueNode {
    QueueEntry entry;
    struct queueNode *next;
}QueueNode;

typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;

void CreateQueue(Queue *);
int append(QueueEntry, Queue *);
void serve(QueueEntry *, Queue *);
int EmptyQueue(Queue *);
int FullQueue(Queue *);
void ClearQueue(Queue *);
void QueueFront(QueueEntry *, Queue *);
int QueueSize(Queue *);
void TraverseQueue(Queue *, void (*) (QueueEntry));

#endif // LINB_H_INCLUDED
