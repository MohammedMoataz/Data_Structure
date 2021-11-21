#ifndef ARRB_H_INCLUDED
#define ARRB_H_INCLUDED

#define MAXSTACK 10
#define StackEntry int
// #define StackEntry char
// #define StackEntry float
// #define StackEntry double

typedef struct stack {
    int top;
    StackEntry entry[MAXSTACK];
}Stack;

void CreateStack    (Stack *);
void Push           (StackEntry , Stack *);
void Pop            (StackEntry *, Stack *);
int  StackEmpty     (Stack *);
int  StackFull      (Stack *);
void ClearStack     (Stack *);
void StackTop       (StackEntry *, Stack *);
int  StackSize      (Stack *);
void TraverseStack  (Stack *, void (*) (StackEntry));

#endif // ARRB_H_INCLUDED
