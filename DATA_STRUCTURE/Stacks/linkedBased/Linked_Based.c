#include "linb.h"
#include <stdlib.h>

#define MAXSTACK 10
#define StackEntry int
// #define StackEntry char
// #define StackEntry float
// #define StackEntry double

void CreateStack(Stack *ps)
{
    ps->top = NULL;
}

void Push(StackEntry e, Stack *ps)
{
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}

void Pop(StackEntry *pe, Stack *ps)
{
    StackNode *pn;

    *pe = ps->top->entry;
    pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
}

int StackEmpty(Stack *ps)
{
    return ps->top == NULL;
}

int StackFull(Stack *ps)
{
    return 0;
}

void ClearStack(Stack *ps)
{
    StackNode *pn = ps->top;

    while(pn) {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->size = 0;
}

void StackTop(StackEntry *pe, Stack *ps)
{
    *pe = ps->top->entry;
}

int StackSize(Stack *ps)
{
    return ps->size;
}

void TraverseStack(Stack *ps, void (*pf) (StackEntry))
{
    /*
    StackNode *pn = ps->top;

    while(pn) {
        (*pf) (pn->entry);
        pn = pn->next;
    }
    */

    for(StackNode *pn = ps->top; pn; pn = pn->next)
        (*pf) (pn->entry);
}
