/*
 * EventBased.c
 *
 *  Created on: Feb 2, 2025
 *      Author: mrezk
 */


#include "EventBased.h"
#include <util/atomic.h>

static void handleExtiEvent(void);
static void handleTimerEvent(void);


typedef void (*EventHandler)(void);

EventHandler eventHandlers[EVENT_COUNT] = {
    handleExtiEvent, // EXTI_EVENT
    handleTimerEvent // TIMER_EVENT
};

Queue event_q;

static void Timer_Event(void)
{
	uint8 Loc_u8PinVal;
	static uint8 holdButton=0;
	status_t PinStatus=	DIO_GetPinVal(DIO_PORTD, DIO_Pin0, &Loc_u8PinVal);

	if(PinStatus==DIO_ok)
	{
		if(Loc_u8PinVal==0&&holdButton==0)
		{
			/*Preventing to trigger the event if the button
			 * is pressed and hold*/
			holdButton=1;
			ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
			{

				Enqueue(&event_q, TIMER_EVENT);
			}

		}
		else if(Loc_u8PinVal==1)
		{
			holdButton=0;
		}
	}
}

void EXTI_Button_Handler(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){

		Enqueue(&event_q, EXTI_EVENT);

	    }

}


EXTI_CONFIG EXTI_cfg={
		FALLING_EDGE,
		LOW_LEVEL,

};

void EDA_voidInit(void)
{

	PORT_voidInit();
	CLCD_voidInit();
	GIE_Enable();
	createQueue(&event_q);
	TIMER1_voidInit();
	TIMER1_voidSetChannelACompMatch(1563);
	TIMER1_CTCASetCallBck(&Timer_Event);
	EXTI_voidInit(EXTI_cfg);
	EXTI_voidSetInt0CbkFnc(&EXTI_Button_Handler);




}

static void handleExtiEvent(void) {
    DIO_SetPinVal(DIO_PORTC, DIO_Pin0, DIO_HIGH);
}

static void handleTimerEvent(void) {
    DIO_SetPinVal(DIO_PORTC, DIO_Pin1, DIO_HIGH);
}

void EDA_voidRunnable(void)
{

	QueueEntry q;

	if(!queueEmpty(&event_q))
	{


		ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
		Dequeue(&q, &event_q);
		}

		if(q<EVENT_COUNT&&eventHandlers[q]!=NULL)
		{
			eventHandlers[q]();
		}
	}
	else
	{
		/*TODO: add switching to power saving mode in the future */
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Idle Mode");
	}
}


