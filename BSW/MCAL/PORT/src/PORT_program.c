/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:PORT                      *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include"../inc/PORT_private.h"
#include"../inc/PORT_interface.h"
#include"../inc/PORT_register.h"
#include"../inc/PORT_config.h"



void PORT_voidInit(void)
{

DDRA=PORTA_DIR;
DDRB=PORTB_DIR;
DDRC=PORTC_DIR;
DDRD=PORTD_DIR;

PORTA=PORTA_INIT_VALUE;
PORTB=PORTB_INIT_VALUE;
PORTC=PORTC_INIT_VALUE;
PORTD=PORTD_INIT_VALUE;
}
