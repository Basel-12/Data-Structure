#include "global.h"
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct treenode
{
    type_entry item;
    struct treenode *left, *right;

} treenode;

typedef treenode *Tree;

typedef struct tree
{
    treenode *root;
    int size;
    int depth;
} tree;

void CreateTree(Tree *);
void ClearTree(Tree *);
int TreeSize(Tree *);
int TreeDepth(Tree *);
int TreeEmpty(Tree *);
int TreeFull(Tree *);
void Preorder(Tree *, void (*)(type_entry));
void Inorder(Tree *, void (*)(type_entry));
void Postorder(Tree *, void (*)(type_entry));
void InsertTreeRec(Tree *, type_entry *);
void InsertTree(Tree *, type_entry *);
int TreeSizeRec(Tree *);
int TreeDepthRec(Tree *);

#endif // TREE_H_INCLUDED
