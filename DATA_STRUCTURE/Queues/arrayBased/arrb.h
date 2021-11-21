#ifndef ARRB_H_INCLUDED
#define ARRB_H_INCLUDED

#define MAXQUEUE 10
#define QueueEntry int
// #define QueueEntry char
// #define QueueEntry float
// #define QueueEntry double

typedef struct queue {
    int front,
        rear,
        size;
    QueueEntry entry[MAXQUEUE];
}Queue;

void CreateQueue    (Queue *);
void append         (QueueEntry, Queue *);
void serve          (QueueEntry *, Queue *);
int  EmptyQueue     (Queue *);
int  FullQueue      (Queue *);
void ClearQueue     (Queue *);
void QueueFront     (QueueEntry *, Queue *);
int  QueueSize      (Queue *);
void TraverseQueue  (Queue *, void (*) (QueueEntry));

#endif // ARRB_H_INCLUDED
