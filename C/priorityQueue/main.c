#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "priorityQueue.h"'
void print(PriorityQueueype e){
    printf("%d ",e.priority);
}
int main()
{
   PriorityQueueype e,p,c,x,y,f;
   e.priority = 1;
   p.priority = 4;
   c.priority = 5;
   f.priority = 6;
   PriorityQueue pq;
   CreatePriorityQueue(&pq);
   Push(e,&pq);
   Push(p,&pq);
   Push(c,&pq);
//   Push(f,&pq);
   TraversePriorityQueue(&pq,&print);
   printf("\n");
   Pop(&x,&pq);
   Pop(&y,&pq);
   print(x);
   print(y);
   printf("\n");
   Push(f,&pq);
   TraversePriorityQueue(&pq,&print);
    return 0;
}
