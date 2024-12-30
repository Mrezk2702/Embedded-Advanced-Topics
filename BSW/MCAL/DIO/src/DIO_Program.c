/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:DIO_PROGRAM               *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../inc/DIO_interface.h"
#include  "../inc/DIO_private.h"
#include "../inc/DIO_register.h"

status_t DIO_SetPortVal(Port_t Copy_Port, uint8 Copy_uint8Value) {
	status_t Local_uint8ErrorState = DIO_ok;
	if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
		Local_uint8ErrorState = DIO_SetErr;
	} else {
		switch (Copy_Port) {
		case DIO_PORTA:
			PORTA = Copy_uint8Value;
			break;
		case DIO_PORTB:
			PORTB = Copy_uint8Value;
			break;
		case DIO_PORTC:
			PORTC = Copy_uint8Value;
			break;
		case DIO_PORTD:
			PORTD = Copy_uint8Value;
			break;
		}
	}

	return Local_uint8ErrorState;
}

status_t DIO_SetPinVal(Port_t Copy_Port, Pin_t Copy_Pin, uint8 Copy_uint8Value) {
	status_t Local_uint8ErrorState = DIO_ok;

	if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
		Local_uint8ErrorState = DIO_SetErr;
	} else if ((Copy_Pin > DIO_Pin7) || (Copy_Pin < DIO_Pin0)) {
		Local_uint8ErrorState = DIO_SetErr;
	} else {
		if (DIO_HIGH == Copy_uint8Value) {
			switch (Copy_Port) {
			case DIO_PORTA:
				SET_BIT(PORTA, Copy_Pin);
				break;
			case DIO_PORTB:
				SET_BIT(PORTB, Copy_Pin);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC, Copy_Pin);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD, Copy_Pin);
				break;
			}
		} else if (DIO_LOW == Copy_uint8Value) {
			switch (Copy_Port) {
			case DIO_PORTA:
				CLEAR_BIT(PORTA, Copy_Pin);
				break;
			case DIO_PORTB:
				CLEAR_BIT(PORTB, Copy_Pin);
				break;
			case DIO_PORTC:
				CLEAR_BIT(PORTC, Copy_Pin);
				break;
			case DIO_PORTD:
				CLEAR_BIT(PORTD, Copy_Pin);
				break;
			}
		}
	}

	return Local_uint8ErrorState;
}

status_t DIO_SetPortDir(Port_t Copy_Port, uint8 Copy_uint8Direction) {
	status_t Local_uint8ErrorState = DIO_ok;
	if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
		Local_uint8ErrorState = DIO_DirErr;
	} else {
		switch (Copy_Port) {
		case DIO_PORTA:
			DDRA = Copy_uint8Direction;
			break;
		case DIO_PORTB:
			DDRB = Copy_uint8Direction;
			break;
		case DIO_PORTC:
			DDRC = Copy_uint8Direction;
			break;
		case DIO_PORTD:
			DDRD = Copy_uint8Direction;
			break;
		}
	}
	return Local_uint8ErrorState;
}

status_t DIO_SetPinDir(Port_t Copy_Port, Pin_t Copy_Pin, Dir_t Copy_Direction) {
	status_t Local_uint8ErrorState = DIO_ok;

	if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
		Local_uint8ErrorState = DIO_DirErr;
	} else if ((Copy_Pin > DIO_Pin7) || (Copy_Pin < DIO_Pin0)) {
		Local_uint8ErrorState = DIO_DirErr;
	} else {
		if (DIO_INPUT == Copy_Direction) {
			switch (Copy_Port) {
			case DIO_PORTA:
				CLEAR_BIT(DDRA, Copy_Pin);
				break;
			case DIO_PORTB:
				CLEAR_BIT(DDRB, Copy_Pin);
				break;
			case DIO_PORTC:
				CLEAR_BIT(DDRC, Copy_Pin);
				break;
			case DIO_PORTD:
				CLEAR_BIT(DDRD, Copy_Pin);
				break;
			}
		} else if (DIO_OUTPUT == Copy_Direction) {
			switch (Copy_Port) {
			case DIO_PORTA:
				SET_BIT(DDRA, Copy_Pin);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB, Copy_Pin);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC, Copy_Pin);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD, Copy_Pin);
				break;
			}
		}
	}
	return Local_uint8ErrorState;
}


status_t DIO_GetPinVal(Port_t Copy_Port, Pin_t Copy_Pin, uint8* Copy_pvValue)
{
	status_t Local_uint8ErrorState = DIO_ok;

		if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
			Local_uint8ErrorState = DIO_GetErr;
		} else if ((Copy_Pin > DIO_Pin7) || (Copy_Pin < DIO_Pin0)) {
			Local_uint8ErrorState = DIO_GetErr;
		} else {
			switch (Copy_Port)
			{case DIO_PORTA : *Copy_pvValue=GET_BIT(PINA,Copy_Pin);break;
			case DIO_PORTB : *Copy_pvValue=GET_BIT(PINB,Copy_Pin);break;
			case DIO_PORTC : *Copy_pvValue=GET_BIT(PINC,Copy_Pin);break;
			case DIO_PORTD : *Copy_pvValue=GET_BIT(PIND,Copy_Pin);break;

			}
		}
return Local_uint8ErrorState;
}


uint8 DIO_GetPortVal(Port_t Copy_Port,uint8* Copy_pvValue)
{
	uint8 Local_uint8ErrorState = 0;
		if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
			Local_uint8ErrorState = 1;
		} else {
			switch(Copy_Port)
			{case DIO_PORTA:*Copy_pvValue=PINA;break;
			case DIO_PORTB:*Copy_pvValue=PINB;break;
			case DIO_PORTC:*Copy_pvValue=PINC;break;
			case DIO_PORTD:*Copy_pvValue=PIND;break;
			}
		}

return Local_uint8ErrorState;
}
