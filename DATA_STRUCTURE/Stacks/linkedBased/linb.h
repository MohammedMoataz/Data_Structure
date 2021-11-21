#ifndef LINB_H_INCLUDED
#define LINB_H_INCLUDED

#define MAXSTACK 10
#define StackEntry int
// #define StackEntry char
// #define StackEntry float
// #define StackEntry double

typedef struct stackNode {
    StackEntry entry;
    struct stackNode *next;
}StackNode;

typedef struct stack {
    StackNode *top;
    int size;
}Stack;

void CreateStack    (Stack *ps);
void Push           (StackEntry e, Stack *ps);
void Pop            (StackEntry *e, Stack *ps);
void ClearStack     (Stack *ps);
void StackTop       (StackEntry *e, Stack *ps);
int  StackEmpty     (Stack *ps);
int  StackFull      (Stack *ps);
int  StackSize      (Stack *ps);
void TraverseStack  (Stack *ps, void (*pf) (StackEntry));

#endif // LINB_H_INCLUDED
