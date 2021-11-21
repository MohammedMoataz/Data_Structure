#include "tree.h"

void CreateTree(Tree *ppt)
{
    *ppt = NULL;
}

void InOrder(Tree pt, void (*pf) (TreeEntry e))
{
    if(pt) {
        InOrder(pt->left, pf);
        (*pf)(pt->info);
        InOrder(pt->right, pf);
    }
}

void PreOrder(Tree pt, void (*pf) (TreeEntry e))
{
    if(pt) {
        (*pf)(pt->info);
        InOrder(pt->left, pf);
        InOrder(pt->right, pf);
    }
}

void PostOrder(Tree pt, void (*pf) (TreeEntry e))
{
    if(pt) {
        InOrder(pt->left, pf);
        InOrder(pt->right, pf);
        (*pf)(pt->info);
    }
}

int TreeSize(Tree pt)
{
    if(!pt)
        return 0;
    return (1 + TreeSize(pt->left) + TreeSize(pt->right));
}

int TreeHeight(Tree pt)
{
    if(!pt)
        return 0;

    int left = TreeHeight(pt->left);
    int right = TreeHeight(pt->right);

    return (left > right) ? left + 1 : right + 1;
}

int TreeDepth(Tree pt)
{
    if(!pt)
        return 0;

    int left = TreeDepth(pt->left);
    int right = TreeDepth(pt->right);

    return (left > right) ? left + 1 : right + 1;
}


void ClearTree(Tree *ppt)
{
    if(*ppt) {
        ClearTree(&(*ppt)->left);
        ClearTree(&(*ppt)->right);
        free(*ppt);
        *ppt = NULL;
    }
}

int TreeFull(Tree pt)
{
    return 0;
}

int TreeEmpty(Tree pt)
{
    return (!pt);
}

void InsertTree(Tree *ppt, TreeEntry *pe)
{
    /*
    if(!*ppt) {
        *ppt = (Tree) malloc(sizeof(TreeNode));
        (*ppt)->info = *pe;
        (*ppt)->left = NULL;
        (*ppt)->right = NULL;
    }
    else if((*ppt)->info > *pe)
        InsertTree(&(*ppt)->left, pe);
    else
        InsertTree(&(*ppt)->right, pe);
    */

    TreeNode *pn = (TreeNode *) malloc(sizeof(TreeNode));

    pn->info = *pe;
    pn->left = NULL;
    pn->right = NULL;

    if(!(*ppt))
        *ppt = pn;
    else {
        TreeNode *cur, *pre;
        cur = *ppt;

        while(cur) {
            pre = cur;

            if(*pe < cur->info)
                cur = cur->left;
            else
                cur = cur->right;
        }

        if(*pe < pre->info)
            pre->left = pn;
        else
            pre->right = pn;
    }
}

void DeleteItemTree (Tree *ppt, TreeEntry *pe)
{
    int found = 0;
    TreeNode *q = *ppt, *r = NULL;

    while(q && !(found = (q->info == *pe))) {
        r = q;

        if(q->info > *pe)
            q = q->left;
        else
            q = q->right;
    }

    if(found) {
        *pe = q->info;

        if(!r)
            DeleteNodeTree(ppt);
        else if(r->info > *pe)
            DeleteNodeTree(&r->left);
        else
            DeleteNodeTree(&r->right);
    }
}

void DeleteNodeTree (Tree *ppt)
{
    TreeNode *q = *ppt, *r;

    if(!(*ppt)->left)
        *ppt = (*ppt)->right;
    else if (!(*ppt)->right)
        *ppt = (*ppt)->left;
    else {
        q = (*ppt)->left;

        if(!(*ppt)->right) {
            (*ppt)->info = q->info;
            (*ppt)->left = q->left;
        } else {
            do {
                r = q;
                q = q->right;
            } while(q->right);

            (*ppt)->info = q->info;
            r->right = q->left;
        }
    }
    free(q);
}
