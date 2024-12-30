/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER1                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_

#define TCCR1A_Reg          ((volatile TCCR1A*)0x4F)


#define TCCR1B_Reg          ((volatile TCCR1B*)0x4E)


#define TCNT1_Reg          *((volatile uint16*)0x4C)

#define OCR1A_Reg          *((volatile uint16*)0x4A)


#define OCR1B_Reg          *((volatile uint16*)0x48)



#define ICR1_Reg          *((volatile uint16*)0x46)


#define TIMSK_Reg   ((volatile Timer1_TIMSK *)0x59)

#define TIFR_Reg   ((volatile Timer1_TIFR *)0x58)


#endif /* TIMER1_REGISTER_H_ */
