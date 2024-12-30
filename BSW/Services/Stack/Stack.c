
#include "Stack.h"

 void CreateStack(Stack * PStr_Stack)
{
    PStr_Stack->Top=0;
}

/**
 *
 * @brief  Brief description of the function.
 *
 * @param  PStr_Stack reference of the stack.
 * @param  E Entry to be pushed in the stack.
 * @return Status of the entry whether it's pushed or not.
 *
 * @pre    Preconditions:
 *         - stack needs to be initialized and not full.
 *
 * @post   Postconditions:
 *         - N/A
 *
 * @note   N/A
 *
 * @warning value will not be pushed in the stack of the stack is full.
 */
 void Push(Stack * PStr_Stack,StackEntry E)
{

        PStr_Stack->Entry[PStr_Stack->Top]=E;
        PStr_Stack->Top++;
}


 void POP(StackEntry* PE,Stack * PStr_Stack)
{
           //stack is not empty
        *PE=PStr_Stack->Entry[PStr_Stack->Top-1];
        PStr_Stack->Top--;
}


 void TraverseStack(Stack *ps,void(*pf)(StackEntry e))
{
    for(int i=ps->Top;i>0;i--)
    {
         (*pf)(ps->Entry[i-1]);

    }

}

 int StackEmpty(Stack * PS)
{
    int returnVal=1;
    if(PS->Top>0)
    {
        returnVal=0;
    }
    return returnVal;
}

 int StackFull(Stack*PS)
{
    int returnVal=0;
    if(PS->Top==STACK_MAX)
    {
        returnVal=1;
    }
    return returnVal;
}

 void StackTop(StackEntry *e,Stack *PS)
{
    *e=PS->Entry[PS->Top-1];
}

 int StackSize(Stack *PS)
{
    return PS->Top;
}

 void clearStack(Stack*PS)
{
    PS->Top=0;
}


