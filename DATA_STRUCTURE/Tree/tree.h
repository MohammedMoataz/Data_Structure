#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdlib.h>

// typedef int TreeEntry;
typedef char TreeEntry;
// typedef float TreeEntry;
// typedef double TreeEntry;

typedef struct treeNode {
    TreeEntry info;
    struct treeNode *left,
                    *right;
}TreeNode;

typedef TreeNode *Tree;

/*
typedef struct tree {
    TreeNode *root;
    int size,
        depth;
} Tree2;
*/

void CreateTree       (Tree *ppt);
void InOrder          (Tree pt, void (*pf) (TreeEntry e));
void PreOrder         (Tree pt, void (*pf) (TreeEntry e));
void PostOrder        (Tree pt, void (*pf) (TreeEntry e));
int  TreeSize         (Tree pt);
int  TreeHeight       (Tree pt);
void ClearTree        (Tree *ppt);
int  TreeDepth        (Tree pt);
int  TreeFull         (Tree pt);
int  TreeEmpty        (Tree pt);
void InsertTree       (Tree *ppt, TreeEntry *pe);
void DeleteItemTree   (Tree *ppt, TreeEntry *pe);
void DeleteNodeTree   (Tree *ppt);

#endif // TREE_H_INCLUDED
