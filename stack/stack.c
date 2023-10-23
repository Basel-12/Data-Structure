#include "Stack.h"

/**
* CreateStack - intialize top of stack to 0
*pre: stack object exists;
* post: stack intialized
*/
void CreateStack(Stack *ps)
{
    ps->top = 0;
}

/**
 * Push - push element to top of stack
 * pre: stack intialized and not full 
 * push function that push element to the top of the stack
*/
void Push(stack_entry e, Stack *ps)
{
    ps->entry[ps->top++] = e;
}

/** 
 * pre: stack intialized
* StackFull - function  check that the stack is full or not so we can push
*  Return: int
*/
int StackFull(Stack *ps)
{
    return ps->top == MAXSTACK;
}

/**
 * pop : function that return last element enterd in stack
 *
 * pre: stack not empty
 *
 * post: last element returned and pe pointing to it
 */
void Pop(stack_entry *pe, Stack *Ps)
{
    *pe = Ps->entry[--Ps->top];
}

/**
 * FirstElement - function return a copy first element entered in stack
 *
 * pre: stack not empty
 * 
 * post: copy oof first element returned
 */
void FirstElement(stack_entry *pe, Stack *ps)
{
    *pe = ps->entry[0];
}

/**
 * StackEmpty - check if stack empty or not
 * 
 * pre: stack intialized
 */
int StackEmpty(Stack *Ps)
{
    if (Ps->top == 0)
        return 1;
    return 0;
}

/**
 * StackTop - return a copy of element on top of stack
 * 
 * pre: stack not empty
 * 
 * post: copy of last element entered returned
*/
void StackTop(stack_entry *pe, Stack *Ps)
{
    *pe = Ps->entry[Ps->top - 1];
}

/**
 * stack_size - return size of stack 
 * 
 * pre: stack intialized
 * 
 * post: return size of stack
 * 
*/
int stack_size(Stack *ps)
{
    return ps->top;
}

/**
* CopyStack - function copy element of a stack to another
*
*pre: both stack intialized
*
 */

void CopyStack(Stack *ps, Stack *pds)
{
    for (int i = 0; i < ps->top; i++)
    {
        pds->entry[i] = ps->entry[i];
        pds->top++;
    }
}

/**
 * ClearStack - destroy stack and delete elements in it
 * 
 * pre: stack intialized
 * 
*/
void ClearStack(Stack *ps)
{
    ps->top = 0;
}
/**/ 
void TraverseStack(Stack *Ps, void (*pf)(stack_entry e)) 
{ for (int i = Ps->top; i > 0; --i) { 
    (*pf)(Ps->entry[i - 1]); 
    } 
}

