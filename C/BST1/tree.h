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
void LevelOrder(Tree *, void (*)(type_entry));
void InsertTreeRec(Tree *, type_entry *);
void InsertTree(Tree *, type_entry *);
treenode * DeleteNode(Tree *,type_entry *);
treenode * Deleteleaves(Tree *);
int TreeSizeRec(Tree *);
int TreeDepthRec(Tree *);
void print2D(Tree*);
int existsRec(Tree*,type_entry* );
int exists(Tree*,type_entry* );
int  findminRec(Tree *, type_entry *);
int  findmin(Tree *, type_entry *);
int  findmaxRec(Tree *, type_entry *);
int  findmax(Tree *, type_entry *);
#endif // TREE_H_INCLUDED
