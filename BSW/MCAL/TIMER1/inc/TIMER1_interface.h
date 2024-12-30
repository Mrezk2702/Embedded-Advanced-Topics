/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER1                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

typedef enum
{
	TIMER1_OK,
	TIMER1_PONTER_ERR
}Timer1_status;



void TIMER1_voidInit(void);

void TIMER1_voidSetChannelACompMatch(uint16 Copy_uint16Data);
void TIMER1_voidSetChannelBCompMatch(uint16 Copy_uint16Data);
void TIMER1_voidSetICR(uint16 Copy_uint16ICR);

void TIMER1_voidSetTimerValue(uint16 Copy_uint16Value);
uint16 TIMER1_uint16GetTimerValue(void);




Timer1_status TIMER1_CTCASetCallBck(void(*Copy_pvCallBackFunc)(void));
Timer1_status TIMER1_CTCBSetCallBck(void(*Copy_pvCallBackFunc)(void));

Timer1_status TIMER1_OVSetCallBck(void(*Copy_pvCallBackFunc)(void));

Timer1_status TIMER1_CAPTURESetCallBck(void(*Copy_pvCallBackFunc)(void));



#endif /* TIMER1_INTERFACE_H_ */
