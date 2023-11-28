#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "doubleLinked.h"
void print(type_entry e)
{

    printf("%C ",e);
}
int main()
{
    DoubleLinkedList dl;
    type_entry cc;
    CreateList(&dl);
    InsertList(0,'5',&dl);
    InsertList(1,'6',&dl);
     InsertList(2,'7',&dl);
    InsertList(3,'8',&dl);
    InsertList(4,'9',&dl);
    InsertList(4,'0',&dl);
    printf("%d\n",ListSize(&dl));
   TraverseList(&dl,&print);
   printf("\n");
//   DeleteList(4,&cc,&dl);
//    RetrieveList(3,&cc,&dl);
//   printf("\n%c\n",cc);
ReplaceList(5,'4',&dl);
   TraverseList(&dl,&print);
    return 0;
}
