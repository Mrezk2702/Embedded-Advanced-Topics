#include "../inc/TrafficLightsControl_interface.h"
#include "../inc/TrafficLightsControl_config.h"
#include "../inc/TrafficLightsControl_private.h"

void Yellow_handler(void);
void Red_handler(void);
void Green_handler(void);


Stack Traffic_STATE;
sint8 Traffic_Time=2;
uint8 updateDisplaay=0;
uint8 entry=0;
void (*CurrentState)(void);
void (*Prev_State)(void);


void Green_handler(void)
{
	DIO_SetPortVal(DIO_PORTC, 0x01);
	if(entry)
	{
		CLCD_voidSendCommand(1);
		entry=0;
	}
	CLCD_voidGoToXY(0, 0);
	CLCD_voidSendString("Traffic: Green");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("  ");
	CLCD_voidGoToXY(1,0);
	CLCD_voidWriteNumber(Traffic_Time);
}

void Yellow_handler(void)
{
	DIO_SetPortVal(DIO_PORTC, 0x02);
	if(entry)
	{
		CLCD_voidSendCommand(1);
		entry=0;
	}
	CLCD_voidGoToXY(0, 0);
	CLCD_voidSendString("Traffic: Yellow");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("  ");
	CLCD_voidGoToXY(1,0);
	CLCD_voidWriteNumber(Traffic_Time);
}

void Red_handler(void)
{
	DIO_SetPortVal(DIO_PORTC, 0x04);
	if(entry)
	{
		CLCD_voidSendCommand(1);
		entry=0;
	}
	CLCD_voidGoToXY(0, 0);
	CLCD_voidSendString("Traffic: Red");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("  ");
	CLCD_voidGoToXY(1,0);
	CLCD_voidWriteNumber(Traffic_Time);
}


uint8 Init_Flag=1;
StackEntry test;
void Traffic_Handler (void)
{
	Traffic_Time--;

	if(Traffic_Time<0)
	{
		if (CurrentState==Green_handler)
		{

			if(Prev_State==Yellow_handler)
			{
				/*This handles pushing Yellow in the stack if SW is at init*/
				Init_Flag=0;
			}
			/*Pop green as no need to return back to it*/
			POP(&Prev_State, &Traffic_STATE);
			if(Init_Flag)
			{
				Push(&Traffic_STATE, Yellow_handler);
			}


			Traffic_Time=2;
		}
		else if(CurrentState==Yellow_handler)
		{
			if(Prev_State==Green_handler)
			{
				//Save Previous State before pushing new one
				StackTop(&Prev_State, &Traffic_STATE);
				Push(&Traffic_STATE, &Red_handler);
				Traffic_Time=2;
			}
			else if(Prev_State==Red_handler)
			{
				//Save Previous State before pushing new one
				StackTop(&Prev_State, &Traffic_STATE);
				Push(&Traffic_STATE, &Green_handler);
				Traffic_Time=2;
			}


		}
		else if (CurrentState==Red_handler)
		{
			/*Pop red as no need to return back to it*/
			if(!StackEmpty(&Traffic_STATE))
			{
				POP(&Prev_State, &Traffic_STATE);
			}
			Traffic_Time=2;

		}
		StackTop(&CurrentState, &Traffic_STATE);
		entry=1;

	}


}


void TrafficLightInit(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	GIE_Enable();
	TIMER1_voidInit();
	TIMER1_voidSetChannelACompMatch(31250);
	TIMER1_CTCASetCallBck(&Traffic_Handler);

	CreateStack(&Traffic_STATE);/*Initializes stack*/
	/*Initially push Green state into stack*/
	Push(&Traffic_STATE, &Green_handler);
	StackTop(&CurrentState, &Traffic_STATE);

}






void TrafficLightMainFunction(void)
{
	CurrentState();
	CLCD_voidGoToXY(1, 8);
	CLCD_voidSendString("SIZE:");
	CLCD_voidWriteNumber(StackSize(&Traffic_STATE));

}




