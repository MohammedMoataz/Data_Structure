#ifndef ARRB_H_INCLUDED
#define ARRB_H_INCLUDED

#define ListEntry int
// #define QueueEntry char
// #define QueueEntry float
// #define QueueEntry double

typedef struct listNode {
    ListEntry entry;
    struct listNode *next,
                    *prev;
}ListNode;

typedef struct list {
    int size,
        currentpos;
    ListNode *current;
}List;

void CreateList    (List *);
int  ListFull      (List *);
int  ListEmpty     (List *);
int  ListSize      (List *);
void DestroyList   (List *);
void InsertList    (int , ListEntry , List *);
void DeleteList    (int , ListEntry *, List *);
void TraverseList  (List *, void (*) (ListEntry));
void RetrieveList  (int , ListEntry *,List *);
void ReplaceList   (int , ListEntry , List *);

#endif // ARRB_H_INCLUDED
