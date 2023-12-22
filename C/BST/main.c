#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "tree.h"
void print(type_entry e){
    printf("%d\n",e);
}

int main()
{
    Tree t;
    CreateTree(&t);
    type_entry e = 5,l = 4, r = 6;
    InsertTree(&t,&e);
    InsertTree(&t,&l);
    InsertTree(&t,&r);
//    printf("%d\n",TreeSizeRec(&t));
    printf("%d\n",TreeDepthRec(&t));
    Inorder(&t,&print);
    return 0;
}
