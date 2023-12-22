#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "circular linked list.h"

void print(type_entry e)
{
    printf("%c ",e);
}
int main()
{
    List l;
    CreateList(&l);
    type_entry e;
    InsertList(0,'0',&l);
    InsertList(1,'1',&l);
    InsertList(2,'3',&l);
    InsertList(3,'4',&l);
    InsertList(0,'2',&l);
    printf("%d\n",ListSize(&l));
    TraverseList(&l,&print);
    DeleteList(0,&e,&l);
    printf("\n%c\n",e);
    TraverseList(&l,&print);
    return 0;
}
