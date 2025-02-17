
#define MAX_SIZE 10
#include "../../LIB/STD_TYPES.h"

typedef enum
{
	TIMER_EVENT=2,
	EXTI_EVENT=4
}EVENTS;
typedef EVENTS QueueEntry;

typedef int QueueMember;


typedef struct queue
{
    QueueMember front;
    QueueMember rear;
    QueueMember size;
    QueueEntry Entry[MAX_SIZE];
}Queue;


 void createQueue(Queue * PStr_Queue);
 void Enqueue(Queue * PStr_Queue,QueueEntry E);
 void Dequeue(QueueEntry* PE,Queue * PStr_Queue);
 void traverseQueue(Queue *ps,void(*pf)(QueueEntry e));
 uint8 queueEmpty(Queue * PS);
 void queueFront(Queue * PS,QueueEntry* PE);
 uint8 queueFull(Queue*PS);
 QueueMember queueSize(Queue *PS);
 void clearQueue(Queue*PS);
