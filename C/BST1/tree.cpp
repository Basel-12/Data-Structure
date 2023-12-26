#include "global.h"
#include "tree.h"
#include <stdlib.h>
#include<stdio.h>
#include<queue>
#define COUNT 10
using namespace std;
void	CreateTree	(Tree *pt)
{
    *pt = NULL;
}

int TreeEmpty(Tree *pt)
{
    return (*pt != NULL);
}

int TreeFull(Tree *pt)
{
    return 1;
}

void	Inorder	(Tree *pt, void (*fun)(type_entry e))
{
    if (*pt)
    {
        Inorder(&(*pt)->left, fun);
        fun((*pt)->item);
        Inorder(&(*pt)->right, fun);
    }
}

void Preorder(Tree *pt, void (*pf)(type_entry e)){
    if(*pt){
        (*pf)((*pt)->item);
        Preorder(&(*pt)->left,pf);
        Preorder(&(*pt)->right,pf);
    }
}

void Postorder(Tree *pt, void (*pf)(type_entry e)){
    if(*pt){
        Postorder(&(*pt)->left,pf);
        Postorder(&(*pt)->right,pf);
        (*pf)((*pt)->item);
    }
}

void LevelOrder(Tree *pt, void (*pf)(type_entry e)){
    if(!*pt)
        return ;
    queue<treenode *>q;
    q.push(*pt);
    while (!q.empty())
    {
        treenode *temp = q.front();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        (*pf)(temp->item);
        q.pop();
    }
}

void	ClearTreeRec (Tree *pt)
{
    if (*pt)
    {
        ClearTreeRec(&(*pt)->left);
        ClearTreeRec(&(*pt)->right);
        free(*pt);
    }
}

void	ClearTree (Tree *pt)
{
    ClearTreeRec(pt);
    *pt=NULL;
}

void InsertTreeRec(Tree *pt, type_entry *pe)
{
    if (!*pt)
    {
        *pt = (treenode *)malloc(sizeof(treenode));
        (*pt)->item = *pe;
        (*pt)->left = NULL;
        (*pt)->right = NULL;
    }
    else if( *pe < (*pt)->item)
        InsertTreeRec(&(*pt)->left,pe);
    else
        InsertTreeRec(&(*pt)->right,pe);
}

void InsertTree(Tree *pt, type_entry *pe)
{
    treenode *pn, *prev = NULL, *curr = *pt;
    pn = (treenode *)malloc(sizeof(treenode));
    pn->item = *pe;
    pn->left = NULL;
    pn->right  = NULL;
    if (!*pt)
        *pt = pn;
    else
    {
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

int TreeSizeRec(Tree *pt)
{
    if (!*pt)
        return 0;
    return (1+TreeSizeRec(&(*pt)->left)+TreeSizeRec(&(*pt)->right));
}


int TreeDepthRec(Tree *pt) // number of edges in lingest path
{
    if (*pt == NULL)
        return -1;
    int a=TreeDepthRec(&(*pt)->left);
    int b=TreeDepthRec(&(*pt)->right);
    return (a>b)? 1+a : 1+b;
}


// int TreeDepthRec(Tree *pt) // number of nodes in longest path
// {
//     if (*pt == NULL)
//         return 0;
//     int a=TreeDepthRec(&(*pt)->left);
//     int b=TreeDepthRec(&(*pt)->right);
//     return (a>b)? 1+a : 1+b;
// }

void print2DUtil(Tree* root, int space)
{
    // Base case
    if (*root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(&(*root)->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", (*root)->item);

    // Process left child
    print2DUtil(&(*root)->left, space);
}

// Wrapper over print2DUtil()
void print2D(Tree* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int existsRec(Tree *pt,type_entry *pe)
{
    if(*pt == NULL)
        return 0;
    if((*pt)->item == *pe)
        return 1;
    if(*pe < (*pt)->item)
        existsRec(&(*pt)->left,pe);
    else
        existsRec(&(*pt)->right,pe);
}


int exists(Tree*pt,type_entry*pe )
{
    treenode *curr = *pt;
    while(curr)
    {
        if(curr->item == *pe)
        {
            return 1;
        }
        if(*pe < curr->item)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return 0;
}

int findmin(Tree *pt,type_entry *pe)
{
    treenode *curr = *pt;
    if(!*pt)
        return 0;
    while (curr->left)
    {
        curr = curr->left;
    }
    *pe = curr->item;
    return 1;
}

treenode* findminAux(Tree *pt,type_entry *pe)
{
    treenode *curr = *pt;
    if(!*pt)
        return *pt;
    while (curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

int findminRec(Tree *pt,type_entry *pe)
{
    if (!*pt)
        return 0;
    if((*pt)->left == NULL)
    {
        *pe = (*pt)->item;
        return 1;
    }
    else
        return findminRec(&((*pt)->left), pe);

}


int findmax(Tree *pt,type_entry *pe)
{
    treenode *curr = *pt;
    if(!*pt)
        return 0;
    while (curr->right)
    {
        curr = curr->right;
    }
    *pe = curr->item;
    return 1;
}

int findmaxRec(Tree *pt,type_entry *pe)
{
    if (!*pt)
        return 0;
    if((*pt)->right == NULL)
    {
        *pe = (*pt)->item;
        return 1;
    }
    else
        return findmaxRec(&((*pt)->right), pe);
}

treenode * DeleteNode(Tree *pt,type_entry *pe){
    if(!*pt)
        return *pt;
    else if(*pe < (*pt)->item)
       (*pt)->left =  DeleteNode(&(*pt)->left,pe);
    else if(*pe > (*pt)->item)
       (*pt)->right =  DeleteNode(&(*pt)->right,pe);
    else{
        if(!(*pt)->left && !(*pt)->right){
            free(*pt);
            *pt=NULL;
        }
        else if(!(*pt)->left)
        {
            treenode *temp = *pt;
            *pt = (*pt)->right;
            free(temp);
        }
        else if(!(*pt)->right){
            treenode *temp = *pt;
            *pt = (*pt)->left;
            free(temp);
        }
        else{
            treenode *temp = findminAux(&(*pt)->right,pe);
            (*pt)->item = temp->item;
            (*pt)->right = DeleteNode(&(*pt)->right,&temp->item);
        }
    }
    return *pt;
}

treenode * Deleteleaves(Tree *pt){
    if(!*pt)
        return *pt;
    if(!(*pt)->left && !(*pt)->right){
        free(*pt);
        *pt = NULL;
        return *pt;
    }
    (*pt)->left = Deleteleaves(&(*pt)->left);
    (*pt)->right = Deleteleaves(&(*pt)->right);
    return *pt;
}
