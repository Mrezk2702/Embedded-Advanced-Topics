/*
 * EventBased.c
 *
 *  Created on: Feb 2, 2025
 *      Author: mrezk
 */


#include "EventBased.h"



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
			Enqueue(&event_q, TIMER_EVENT);
		}
		else if(Loc_u8PinVal==1)
		{
			holdButton=0;
		}
	}
}

void EXTI_Button_Handler(void)
{

	Enqueue(&event_q, EXTI_EVENT);

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

void EDA_voidRunnable(void)
{

	QueueEntry q;

	if(!queueEmpty(&event_q))
	{


		Dequeue(&q, &event_q);

		switch (q)
		{
		case EXTI_EVENT:
			DIO_SetPinVal(DIO_PORTC,DIO_Pin0, DIO_HIGH);
			break;
		case TIMER_EVENT:
			DIO_SetPinVal(DIO_PORTC,DIO_Pin1, DIO_HIGH);
			break;
		}
	}
	else
	{
		/*TODO: add switching to power saving mode in the future */
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Idle Mode");
	}
}


