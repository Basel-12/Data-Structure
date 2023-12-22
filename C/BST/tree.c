#include "global.h"
#include "tree.h"
#include <stdlib.h>

void	CreateTree	(Tree *pt){
    *pt = NULL;
}

int TreeEmpty(Tree *pt){
        return (*pt != NULL);
}

int TreeFull(Tree *pt){
    return 1;
}

void	Inorder	(Tree *pt, void (*fun)(type_entry e)){
    if (*pt)
    {
        Inorder(&(*pt)->left, fun);
        fun((*pt)->item);
        Inorder(&(*pt)->right, fun);
    }
}

void	ClearTreeRec (Tree *pt){
    if (*pt)
    {
        ClearTreeRec(&(*pt)->left);
        ClearTreeRec(&(*pt)->right);
        free(*pt);
    }
}

void	ClearTree (Tree *pt){
    ClearTreeRec(pt);
    *pt=NULL;
}

void InsertTreeRec(Tree *pt, type_entry *pe){
    if (!*pt)
    {
        *pt = malloc(sizeof(treenode));
        (*pt)->item = *pe;
        (*pt)->left = NULL;
        (*pt)->right = NULL;
    }
    else if( *pe < (*pt)->item)
        InsertTreeRec(&(*pt)->left,pe); 
    else
    InsertTreeRec(&(*pt)->right,pe);
}

void InsertTree(Tree *pt, type_entry *pe){
    treenode *pn , *prev = NULL, *curr = *pt;
        pn = malloc(sizeof(treenode));
        pn->item = *pe;
        pn->left = NULL;
        pn->right  = NULL;
    if (!*pt)
        *pt = pn;
    else{
        while (curr)
        {
            prev = curr;
            if(*pe < curr->item)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if(*pe < prev->item)
            prev->left = pn;
        else
            prev->right = pn; 
    }
    

}

int TreeSizeRec(Tree *pt){
    if (!*pt)
        return 0;
    return (1+TreeSizeRec(&(*pt)->left)+TreeSizeRec(&(*pt)->right));
}

int TreeDepthRec(Tree *pt){
    if (!*pt)
        return 0;
    int a=TreeDepthRec(&(*pt)->left);
    int b=TreeDepthRec(&(*pt)->right);
    return (a>b)? 1+a : 1+b;
}

