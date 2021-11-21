#include <stdlib.h>

#include "linb.h"

void CreateList(List *pl)
{
    pl->current = NULL;
    pl->size = 0;
}

int ListFull(List *pl)
{
    return 0;
}

int ListEmpty(List *pl)
{
    return pl->size == 0;
}

int ListSize(List *pl)
{
    return pl->size;
}

void DestroyList(List *pl)
{
    ListNode *pn;

    while(pl->current)
        pl->current = pl->current->prev;

    pn = pl->current;

    while(pl->current) {
        pn = pn->next;
        free(pl->current);
        pl->current = pn;
    }

    pl->size = 0;
}

void InsertList(int p, ListEntry e, List *pl)
{
    ListNode *pn = (ListNode *) malloc(sizeof(ListNode));

    pn->entry = e;
    pn->next = NULL;
    pn->prev = NULL;

    if(p == 0) {
        while(pl->current->prev)
            pl->current = pl->current->prev;

        pn->next = pl->current;
        pl->current = pn;
        pl->currentpos = 0;
    }

    else if(p > pl->currentpos) {
        while(pl->currentpos != p - 1) {
            pl->current = pl->current->next;
            pl->currentpos++;
        }
    }

    else {
        while(pl->currentpos != p - 1) {
            pl->current = pl->current->prev;
            pl->currentpos--;
        }
    }

    pn->prev = pl->current;
    pn->next = pl->current->next;
    pn->next->prev = pn;
    pl->current->next = pn;
    pl->current = pn;
    pl->currentpos++;

    pl->size++;
}

void DeleteList(int p, ListEntry *pe, List *pl)
{
    ListNode *pn;

    if(p == 0) {
        while(pl->current)
            pl->current = pl->current->prev;

        *pe = pl->current->entry;

        pn = pl->current->next;
        pn->prev = pl->current->prev;
        free(pl->current);
        pl->current = pn;
        pl->currentpos = 0;
    }

    else if(p > pl->currentpos) {
        while(pl->currentpos != p) {
            pl->current = pl->current->next;
            pl->currentpos++;
        }

        pn = pl->current->prev;
        pn->next = pl->current->next;
        free(pl->current);
        pl->current = pn;
    }

    else {
        while(pl->currentpos != p) {
            pl->current = pl->current->prev;
            pl->currentpos--;
        }

        pn = pl->current->next;
        pn->prev = pl->current->prev;
        free(pl->current);
        pl->current = pn;
    }

    pl->size--;
}

void TraverseList(List *pl, void (*pf) (ListEntry))
{
    ListNode *pn = pl->current;

    while(pn->prev)
        pn = pn->prev;

    while(pn) {
        (*pf) (pn->entry);
        pn = pn->next;
    }
}

void RetrieveList(int p, ListEntry *pe,List *pl)
{
    *pe = pl->current->entry;
}

void ReplaceList(int p, ListEntry e, List *pl)
{
    pl->current->entry = e;
}
