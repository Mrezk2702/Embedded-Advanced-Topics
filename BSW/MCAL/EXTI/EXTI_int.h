/*
 * EXTI_int.h
 *
 *  Created on: Feb 14, 2025
 *      Author: mrezk
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#ifndef BSW_MCAL_EXTI_EXTI_INT_H_
#define BSW_MCAL_EXTI_EXTI_INT_H_


typedef struct
{
	uint8 ISC0:2 ;
	uint8 ISC1:2;
	uint8 :1;
	uint8 :1;
	uint8 :1;
	uint8 :1;

}EXTI_CONFIG;
/*This enum is for int0 and int1 only*/


/*MACROS to be used by application
 *  and in config section*/

#define 	LOW_LEVEL 	0u
#define 	ANY_LOGIC_CHANGE 	1u
#define 	FALLING_EDGE 	2u
#define 	RISING_EDGE 	3u

#define INT2_FALLING 0u
#define INT2_RISING 1u

#define ENABLE 1u
#define DISABLE 0u

/* @NOTE :Enabling and disabling configuration
 *
 * */
#define INT0_STATUS		ENABLE
#define INT1_STATUS     DISABLE
#define INT2_STATUS     DISABLE
#define INT2_SENSE_CONTROL INT2_FALLING



/*End of configuration section*/








#define EXTI_MCUCR (( EXTI_CONFIG *)0x55)
#define EXTI_MCUCSR *(( uint8 *) 0x54)
#define EXTI_GICR	*(( uint8 *) 0x5B)



#define INT0_ENABLE_BIT 6
#define INT1_ENABLE_BIT	7
#define INT2_ENABLE_BIT	5
#define INT2_ISC_BIT	6


void EXTI_voidInit(EXTI_CONFIG copy_strEXTIConfig);
void EXTI_voidSetInt0CbkFnc(void(*pFunc)(void));
void EXTI_voidSetInt1CbkFnc(void(*pFunc)(void));
void EXTI_voidSetInt2CbkFnc(void(*pFunc)(void));

#endif /* BSW_MCAL_EXTI_EXTI_INT_H_ */
