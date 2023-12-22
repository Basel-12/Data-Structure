#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "Sorted linked list.h"

#define type_entry int
void print(type_entry e)
{
    printf("%d ",e);
}
int main()
{
    SortedList l;
    CreateSortedList(&l);
    printf("%d\n",SortedListSize(&l));
    InsertSortedList(1,&l);
    InsertSortedList(2,&l);
    InsertSortedList(3,&l);
    TraverseSortedList(&l,&print);
    printf("\n%d\n",SortedListSize(&l));

    return 0;
}
