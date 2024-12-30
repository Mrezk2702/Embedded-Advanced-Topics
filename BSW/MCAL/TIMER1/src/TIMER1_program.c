/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER1                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"s
#include "../inc/TIMER1_interface.h"
#include "../inc/TIMER1_private.h"
#include "../inc/TIMER1_register.h"
#include "../inc/TIMER1_config.h"


void TIMER1_voidInit(void)
{
	/*Clock selection*/
TCCR1B_Reg->CS1X= CLCK_SELECT;

/*Waveform generation mode*/
TCCR1A_Reg->WGM1X=WAVE_GEN & 0b0011;
TCCR1B_Reg->WGM1XX=(WAVE_GEN>>2) & 0b0011;

/*Output mode */

#ifdef CHANNEL_A

#if TIMER1A_MODE == TIMER1_NON_PWM

TCCR1A_Reg->COM1AX=TIMER1A_OUT_MODE;

#elif  TIMER1A_MODE == TIMER1_FAST_PWM

TCCR1A_Reg->COM1AX=TIMER1A_OUT_MODE;

#elif TIMER1A_MODE == TIMER1_PHASE_CORRECT

		TCCR1A_Reg->COM1AX=TIMER1A_OUT_MODE;

#endif
#endif

#ifdef CHANNEL_B

#if TIMER1B_MODE == TIMER1_NON_PWM

		TCCR1A_Reg->COM1BX=TIMER1B_OUT_MODE;

		#elif  TIMER1B_MODE == TIMER1_FAST_PWM


		TCCR1A_Reg->COM1BX=TIMER1B_OUT_MODE;

		#elif TIMER1B_MODE == TIMER1_PHASE_CORRECT


		TCCR1A_Reg->COM1BX=TIMER1B_OUT_MODE;


		#endif
#endif

/*INTERRUPT ENABLE*/
#ifdef TIMER1_COMPARE_MATCH_A_ISR_ENABLE

		TIMSK_Reg->OCIE1A=Enable;
#endif

#ifdef TIMER1_COMPARE_MATCH_B_ISR_ENABLE
		TIMSK_Reg->OCIE1B=Enable;
#endif

#ifdef TIMER1_OVERFLOW_ISR_ENABLE

		TIMSK_Reg->TOIE1=Enable;
#endif

#ifdef TIMER1_INPUT_CAPTURE_INTERRUPT
		TIMSK_Reg->TICIE1=Enable;
#endif


}


void TIMER1_voidSetChannelACompMatch(uint16 Copy_uint16Data)
{
	OCR1A_Reg=Copy_uint16Data;
}
void TIMER1_voidSetChannelBCompMatch(uint16 Copy_uint16Data)
{
	OCR1B_Reg=Copy_uint16Data;
}
void TIMER1_voidSetICR(uint16 Copy_uint16ICR)
{
	ICR1_Reg=Copy_uint16ICR;
}
void TIMER1_voidSetTimerValue(uint16 Copy_uint16Value)
{
	TCNT1_Reg=	Copy_uint16Value;
}
uint16 TIMER1_uint16GetTimerValue(void)
{
return TCNT1_Reg;
}


Timer1_status TIMER1_CTCASetCallBck(void(*Copy_pvCallBackFunc)(void))
{
	Timer1_status Local_ErrorState=TIMER1_OK;

	if(NULL == Copy_pvCallBackFunc)
	{
		Local_ErrorState=TIMER1_PONTER_ERR;
	}
	else
	{
		TIMER1_pvCallBackFunc_CTC_A=Copy_pvCallBackFunc;
	}
return Local_ErrorState;
}
Timer1_status TIMER1_CTCBSetCallBck(void(*Copy_pvCallBackFunc)(void))
{

	Timer1_status Local_ErrorState=TIMER1_OK;

		if(NULL == Copy_pvCallBackFunc)
		{
			Local_ErrorState=TIMER1_PONTER_ERR;
		}
		else
		{
			TIMER1_pvCallBackFunc_CTC_B=Copy_pvCallBackFunc;
		}
	return Local_ErrorState;
}


Timer1_status TIMER1_OVSetCallBck(void(*Copy_pvCallBackFunc)(void))
{
	Timer1_status Local_ErrorState=TIMER1_OK;

		if(NULL == Copy_pvCallBackFunc)
		{
			Local_ErrorState=TIMER1_PONTER_ERR;
		}
		else
		{
			TIMER1_pvCallBackFunc_OV=Copy_pvCallBackFunc;
		}
	return Local_ErrorState;
}


Timer1_status TIMER1_CAPTURESetCallBck(void(*Copy_pvCallBackFunc)(void))
{
	Timer1_status Local_ErrorState=TIMER1_OK;

		if(NULL == Copy_pvCallBackFunc)
		{
			Local_ErrorState=TIMER1_PONTER_ERR;
		}
		else
		{
			TIMER1_pvCallBackFunc_CaptEvnt=Copy_pvCallBackFunc;
		}
	return Local_ErrorState;
}



void __vector_6 (void)
{

	TIMER1_pvCallBackFunc_CaptEvnt();
	TIFR_Reg->ICF1=Enable;
}

void __vector_7 (void)
{
	TIMER1_pvCallBackFunc_CTC_A();
}

void __vector_8 (void)
{
	TIMER1_pvCallBackFunc_CTC_B();
}


void __vector_9 (void)
{
	TIMER1_pvCallBackFunc_OV();
}
