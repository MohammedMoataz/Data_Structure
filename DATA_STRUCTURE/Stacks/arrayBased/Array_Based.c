#include "arrb.h"

void CreateStack(Stack *ps)
{
    ps->top = 0;
}

void Push(StackEntry e, Stack *ps)
{
    ps->entry[ps->top++] = e;
}

void Pop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[--ps->top];
}

int StackEmpty(Stack *ps)
{
    /*
    if(ps->top == 0)
        return 1;
    else
        return 0;
    */

//    ps->top == 0 ? return 1: return 0;

    return !ps->top;
}

int StackFull(Stack *ps)
{
//    ps->top == MAXSTACK ? return 1: return 0;

    return ps->top == MAXSTACK;
}

void ClearStack(Stack *ps)
{
    ps->top = 0;
}

void StackTop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[ps->top-1];
}

int StackSize(Stack *ps)
{
    return ps->top;
}

void TraverseStack(Stack *ps, void (*pf) (StackEntry))
{
    for(int i = 0; i < ps->top; i++)
        (*pf) (ps->entry[i]);
}
