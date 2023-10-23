#ifndef ARRAYED_STACK
#define ARRAYED_STACK

#ifndef MAXSTACK
#define MAXSTACK 100
#endif // MAXSTACK

#ifndef stack_entry
#define stack_entry char
#endif // Stack_Entry

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
