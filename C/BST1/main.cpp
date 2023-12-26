#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "tree.h"
void print(type_entry e){
    printf("\t%d\n / \\ \n",e);
}

int main()
{
    Tree t;
    CreateTree(&t);
    type_entry e = 5,l = 7, r = 4,f = 9,g = 6,gg = 10,ggg = 3,fff = 8;
    InsertTree(&t,&e);
    InsertTree(&t,&l);
    InsertTree(&t,&r);
    InsertTree(&t,&f);
    InsertTree(&t,&g);
    InsertTree(&t,&gg);
    InsertTree(&t,&ggg);
    InsertTree(&t,&fff);
    print2D(&t);
    printf("new ----------------------\n ");
//    DeleteNode(&t,&e);
    Deleteleaves(&t);
    print2D(&t);
//    Inorder(&t,&print);
//    Preorder(&t,&print);
    // Postorder(&t,&print);
    // LevelOrder(&t,&print);
//    printf("%d\n",TreeSizeRec(&t));
//     printf("%d\n",TreeDepthRec(&t));
//     findminRec(&t,&ggg);
//    findmin(&t,&ggg);
//findmax(&t,&ggg);
//findmaxRec(&t,&ggg);
//    print(ggg);
//    printf("\n");
//    printf("%d\n",exists(&t,&ggg));
    return 0;
}
