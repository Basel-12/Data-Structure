#ifndef Linked_STACK
#define Linked_STACK

#ifndef MAXSTACK
#define MAXSTACK 100
#endif // MAXSTACK

#ifndef stack_entry
#define stack_entry char
#endif // Stack_Entry

#ifdef Linked_STACK
/**
 * StackNode - Node of stack where elements stored
 * 
 * @item: store element entered
 * 
 * @next: point to next node
*/
typedef struct stacknode
{
    stack_entry item;
    struct stacknode *next;
}StackNode;

/**
 * Stack - struct stack
 * 
 * @top: points to last node entered
 * 
 * @size: size of stack
 * 
*/
typedef struct stack
{
    StackNode* top;
    int size;
} Stack;


#else
/**
* Stack - struct stack
*
* @top: index of element to pushed
*
* @entry: array of stack_entry elements
**/
typedef struct stack
{
    int top;
    stack_entry entry[MAXSTACK];
}Stack;
#endif
void CreateStack(Stack *);
void Push (stack_entry, Stack *);
void Pop (stack_entry *, Stack *);
void FirstElement (stack_entry *, Stack *);
int	StackEmpty (Stack *);
int	StackFull (Stack *);
void StackTop	(stack_entry *, Stack *);
int	 stack_size	(Stack *);
void CopyStack (Stack *, Stack *);
void ClearStack(Stack *);
void TraverseStack(Stack *, void (*)(stack_entry));
#endif
