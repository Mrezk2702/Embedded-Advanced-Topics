#ifndef STACK_H_
#define STACK_H_
#define STACK_MAX 3

typedef void (*pFunc)(void);

typedef pFunc StackEntry;
typedef struct stack
{
    int Top;
    StackEntry Entry[STACK_MAX];
}Stack;

 void CreateStack(Stack * PStr_Stack);
 void Push(Stack * PStr_Stack,StackEntry E);
 void POP(StackEntry* PE,Stack * PStr_Stack);
 void TraverseStack(Stack *ps,void(*pf)(StackEntry e));
 int StackEmpty(Stack * PS);
 int StackFull(Stack*PS);
 void StackTop(StackEntry *e,Stack *PS);
 int StackSize(Stack *PS);
 void clearStack(Stack*PS);


#endif
