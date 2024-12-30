/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:PORT                      *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#define DDRA   *((volatile uint8*)0X3A)
#define DDRB   *((volatile uint8*)0X37)
#define DDRC   *((volatile uint8*)0X34)
#define DDRD   *((volatile uint8*)0X31)

#define PORTA  *((volatile uint8*)0X3B)
#define PORTB  *((volatile uint8*)0X38)
#define PORTC  *((volatile uint8*)0X35)
#define PORTD  *((volatile uint8*)0X32)

#endif /* PORT_REGISTER_H_ */
