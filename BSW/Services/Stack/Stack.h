#ifndef STACK_H_
#define STACK_H_
#include "../../LIB/STD_TYPES.h"

#if defined(co_TRAFFIC)
typedef void (*pFunc)(void);
typedef pFunc StackEntry;
#define STACK_MAX 3
#elif defined(co_FIXEDPOINT)
typedef uint8 StackEntry;
#define STACK_MAX 11
#else
typedef uint8 StackEntry;
#define STACK_MAX 10
#endif


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
